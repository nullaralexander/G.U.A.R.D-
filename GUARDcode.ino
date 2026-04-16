#include <Servo.h>
#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial sim800L(rxPin, txPin); 

// Pin Definitions
const int ldr1 = A1;
const int ldr2 = A2;
const int ldr3 = A3;
const int reedPin = 6;    
const int resetButton = 9;  
const int armSwitch = 11;   
const int led = 8;        
const int buzzer = 7;     
const int servoPin = 10;  

// Objects
Servo myServo;

// Variables
int threshold = 400;
bool alarmActive = false;  
bool smsSent = false;      

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(resetButton, INPUT_PULLUP);
  pinMode(reedPin, INPUT_PULLUP); 
  pinMode(armSwitch, INPUT_PULLUP); 

  myServo.attach(servoPin);
  myServo.write(0); 

  sim800L.begin(9600);
  Serial.begin(9600);
  Serial.println("System Ready.");
}

void loop() {
  bool systemArmed = (digitalRead(armSwitch) == LOW);

  if (!systemArmed) {
        deactivateAlarm();
    smsSent = false; 
    Serial.println("MODE: DISARMED (Safe)");
  } 
  else {
    int ldrStatus1 = analogRead(ldr1);
    int ldrStatus2 = analogRead(ldr2);
    int ldrStatus3 = analogRead(ldr3);
    int reedState = digitalRead(reedPin);

    if ((ldrStatus1 > threshold) || (ldrStatus2 > threshold) || (ldrStatus3 > threshold) || (reedState == HIGH)) {
      alarmActive = true;
    }

    if (alarmActive) {
      triggerAlarm();
      
      if (!smsSent) {
        send_sms();
        make_call();
        smsSent = true; 
      }
    } else {
      Serial.println("MODE: ARMED (Scanning...)");
    }
  }

  if (digitalRead(resetButton) == LOW) {
    alarmActive = false;
    smsSent = false; 
    deactivateAlarm();
    Serial.println("Alarm Silenced manually.");
  }

  delay(200); 
}

void triggerAlarm() {
  digitalWrite(led, HIGH);
  tone(buzzer, 2000);
  myServo.write(90); 
}

void deactivateAlarm() {
  digitalWrite(led, LOW);
  noTone(buzzer);
  myServo.write(0); 
  alarmActive = false;
}

void send_sms() {
  Serial.println("\n--- Preparing to send SMS ---");

  sim800L.println("AT+CMGF=1");
  delay(1000);
  readResponse();

  sim800L.println("AT+CMGS=\"+639455170826\""); 
  delay(1000);
  
  readResponse(); 
  sim800L.print("THIEF DETECTED!!!!");

  delay(500);

  sim800L.write(26); 
  Serial.println("\nMessage pushed to network. Waiting for confirmation...");

  delay(5000); 
  readResponse();
}

void make_call() {
  Serial.println("\n--- Initiating Emergency Call ---");
  
  sim800L.println("ATD+639455170826;"); 
  delay(1000);
  readResponse();

  Serial.println("Ringing... allowing it to ring for 5 seconds.");
  delay(5000); 

  Serial.println("\nHanging up the call...");
  
  sim800L.println("ATH");
  delay(1000);
  readResponse();
}

void readResponse() {
  delay(500);
  while(sim800L.available()) {
    String response = sim800L.readString();
    Serial.println(response);
  }
}
