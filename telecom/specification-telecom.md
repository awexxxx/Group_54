



**1. Overview**

A robot driven by Ardunio can automatically find a path through the maze by detecting the surrounding environment. It stops when it discovers a treasure, takes a photo of the treasure and uploads it to a webpage, then detects whether it is a treasure, and finally successfully exits the maze.

①The appearance is simple, elegant, and beautiful

②With multiple comprehensive functions

③Conduct good data collection and updates

**2.Appearance**

The car has a simple and elegant appearance. All wires are neatly connected and visually presented. We combine the servo with an ultrasonic detector, which avoids the complexity of the program and reduces the available space of the car due to the installation of too many ultrasonic sensors, while improving aesthetics. A camera and color sensor are placed on the left side of the car, and a WiFi module is placed in the middle of the car. The rear of the car is equipped with main hardware such as the motherboard, electric motor drive chip, and engine. This layout aims to enhance the stability and aesthetics of the car. The good appearance design of the small car can attract the public's attention and improve the market competitiveness of the product.

**3.Hardware Components**

List of The Main Hardware


|**NO.**|**NAME**|**NUMBER**|
| :-: | :-: | :-: |
|1|Arduino uno|1|
|2|Arduino mega |1|
|3|` `Ultrasonic sensor|1|
|4|The LCD screen|1|
|5|ESP8266-01s Wi-Fi-module|1|
|6|Wi-Fi-module downloader|1|
|7|TCS3200 Color sensor|1|
|8|HC-SR04 Ultrasonic ranging module|1|
|9|L298N Drive motor control module|1|
|10|Motor|4|
|11|universal wheel|2|
|12|Front camera GC0308|1|
|13|Cardboard hand-made shell|1|

①Mainboard: Arduino Uno R3 

②Motor driver chip (L298N, TB6612FNG, etc) to control motors

③2 DC motors with wheels and tires/tracks for locomotion 

④1 Ultrasonic to detect line

⑤Power source 2\*3.7 volt-ampere battery pack

⑥front camera model GC0308 HBVCAN-W2312 V11

⑦WiFi module for uploading information

**4. Software Components**

①Arduino IDE to program the Arduino.

②Control the output of the motor using sensor inputs through algorithms.

**5. Testing Plan**

①Initial bench testing of motor control and sensor reading.

②Line following testing on sample tracks.

③Maze solving testing on increasingly complex mazes.

④Metrics to evaluate performance - time to solve, completion rate.

6. **Example**

①Complete the task: the car explores the maze to take treasure photos, upload them to the web page and get out of the maze successfully.

②Install two 3.7V batteries at the rear of the car to power the motor.

③Turn on the power switch at the rear of the car to supply power to the development board.

④After switching on the power, put the car to the maze entrance, where the car will explore the maze and automatically upload photos taken by the front-facing camera.

**7.technical parameter**

①Detection distance (approximately 0-12cm)

②Trolly size: 26 \* 14 \* 14cm 

**8.User considerations** 

①he battery control motor at the rear of the car. If the car is low in battery, please replace it promptly.

②Do not block the ultrasonic sensor located in front of the car, as well as the camera and color sensor on the left.

③Do not maliciously damage the hardware of the car.


