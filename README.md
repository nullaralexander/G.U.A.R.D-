# 👮‍♂️G.U.A.R.D👮‍♂️
## 🚨GSM-Enabled Unified Alarm using Reed and LDR Detection🚨

# 📘 Project Description
The **G.U.A.R.D. (GSM-Enabled Unified Alarm using Reed and LDR Detection)** is a microcontroller-based anti-theft security system designed to detect unauthorized access and object removal. The system uses an Arduino microcontroller integrated with two sensing modules: a Light Dependent Resistor (LDR) for optical intrusion detection and a reed switch for physical displacement detection.
	The LDR operates using an active optical interruption method, where a laser diode continuously illuminates the photoresistor mounted on the enclosure. When the laser beam is interrupted, the resulting change in resistance is detected by the Arduino as a trigger signal, activating an audible buzzer, commanding the SIM900A GSM module to initiate a call to a pre-registered mobile number, and controlling a servo actuator to automatically lock the enclosure door.
	For additional security, a reed switch is installed at the base of the protected object. When the object is removed, the magnetic field is disrupted, causing the reed switch to change state and send a trigger signal to the Arduino. This event similarly activates the buzzer alarm, initiates a GSM call and sms, and engages the servo actuator to lock the door, providing real-time intrusion notification and improved system reliability through dual-sensor detection and physical access prevention.

# 🛠️ Materials
| INPUT |
| :--- |
| LDR Light Dependent Resistor Module (Analog Sensor)|
|Magnetic Control Switch Sensor Reed Module (Digital Sensor)|

| Controller |
| :--- |
| Arduino Microcontroller|

| Controller |
| :--- |
| Led Lamp Light|
|Piezo Buzzer|
|SIM800L GSM Module|
|1 Servo Motor|

# 📔 Block Diagram
<img width="1125" height="528" alt="image" src="https://github.com/user-attachments/assets/9bcf0b97-b0b6-4fd0-8494-e67f478ccc57" />

# 🔗 Connection Diagram
<img width="1225" height="601" alt="image" src="https://github.com/user-attachments/assets/e5fa6f8d-d5d7-436e-be45-4d816d28762f" />

# 📷 Prototype Pictures
## Wirings
### Left Side

<img width="305" height="500" alt="image" src="https://github.com/user-attachments/assets/0dca8903-8d79-4c9a-8066-edb77cd24f3d" />



### Right Side

<img width="305" height="500" alt="image" src="https://github.com/user-attachments/assets/e8d1a2a3-076b-4990-b47f-288af3290baa" />



### Top View

<img width="500" height="455" alt="image" src="https://github.com/user-attachments/assets/33865042-f1ff-4247-a305-4d78d7a128a3" />

## Prototype
### Front

<img width="253" height="500" alt="image" src="https://github.com/user-attachments/assets/68ba731a-3f7b-4c53-a564-57866c95d108" />

### Back

<img width="286" height="500" alt="image" src="https://github.com/user-attachments/assets/fb9d33e0-fca0-4027-8d41-6e108c39fe17" />

### Left and Right
<img width="282" height="500" alt="image" src="https://github.com/user-attachments/assets/58c7049e-7068-49cf-9461-95ca65f19834" /> <img width="282" height="500" alt="image" src="https://github.com/user-attachments/assets/4ec9e3f6-a4c5-4100-b8ca-774bd09be8df" />

### Isometric

<img width="346" height="500" alt="image" src="https://github.com/user-attachments/assets/9cf67cc3-7f3f-4e7a-bba6-94e610f164a5" />

# 📋Testing Sample Monitor
<img width="154" height="668" alt="image" src="https://github.com/user-attachments/assets/bb7cbaee-b59b-4670-949d-ab6c34ccc837" />

# 💻Codes
[click here](https://github.com/nullaralexander/G.U.A.R.D-/blob/main/GUARDcode.ino)

# 🎥 Sample Video

https://github.com/user-attachments/assets/f8bf92d4-3b43-4a84-a742-e93195ad4af7
