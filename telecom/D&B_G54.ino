#include <Servo.h>

Servo myServo;  // 创建一个舵机对象

const int servoPin = 3;  // 舵机连接到数字引脚 3

const int M1_SpeedPin = 5;  // 用于控制 M1 电机速度的模拟引脚
const int M1_DirectionPin1 = 7;  // M1 电机方向引脚1

const int M2_SpeedPin = 6;  // 用于控制 M2 电机速度的模拟引脚
const int M2_DirectionPin1 = 4;  // M2 电机方向引脚1

const int triggerPin = 12;
const int echoPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  pinMode(M1_SpeedPin, OUTPUT);
  pinMode(M1_DirectionPin1, OUTPUT);

  pinMode(M2_SpeedPin, OUTPUT);
  pinMode(M2_DirectionPin1, OUTPUT);
}

void moveForward() {
  // 控制左侧电机 M1 前进
  digitalWrite(M1_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M1_SpeedPin, 105);  // 设置速度，范围是 0 到 255

  // 控制右侧电机 M2 前进
  digitalWrite(M2_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M2_SpeedPin, 105);  // 设置速度，范围是 0 到 255
}


void stopMotors() {
  // 将两个电机的速度设为 0，即停止转动
  analogWrite(M1_SpeedPin, 0);
  analogWrite(M2_SpeedPin, 0);
}

void moveBackward() {
  // 控制左侧电机 M1 后退
  digitalWrite(M1_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M1_SpeedPin, 100);  // 设置速度，范围是 0 到 255

  // 控制右侧电机 M2 后退
  digitalWrite(M2_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M2_SpeedPin, 100);  // 设置速度，范围是 0 到 255
}

void turnLeft90Degrees() {
  // 左侧电机后退，右侧电机前进
  digitalWrite(M1_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M1_SpeedPin, 160);  // 设置速度，范围是 0 到 255
  
  digitalWrite(M2_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M2_SpeedPin, 160);  // 设置速度，范围是 0 到 255

  delay(600); // 转向一秒
  stopMotors(); // 停止电机转动
}

void turnRight90Degrees() {
  // 左侧电机前进，右侧电机后退
  digitalWrite(M1_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M1_SpeedPin, 140);  // 设置速度，范围是 0 到 255

  digitalWrite(M2_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M2_SpeedPin, 140);  // 设置速度，范围是 0 到 255

  delay(600); // 转向一秒3
  stopMotors(); // 停止电机转动
}

void make180DegreesTurn_L() {
  // 左侧电机后退，右侧电机前进
  digitalWrite(M1_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M1_SpeedPin, 140);  // 设置速度，范围是 0 到 255
  
  digitalWrite(M2_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M2_SpeedPin, 140);  // 设置速度，范围是 0 到 255

  delay(1400); // 转向两秒，实现180度转弯
  stopMotors(); // 停止电机转动
}

void make180DegreesTurn_R() {
  // 左侧电机后退，右侧电机前进
  digitalWrite(M2_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M2_SpeedPin, 120);  // 设置速度，范围是 0 到 255
  
  digitalWrite(M1_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M1_SpeedPin, 120);  // 设置速度，范围是 0 到 255

  delay(1600); // 转向两秒，实现180度转弯
  stopMotors(); // 停止电机转动
}

int getDistance() {
  // 发送超声波触发脉冲
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // 读取脉冲宽度
  float duration = pulseIn(echoPin, HIGH);

  // 将脉冲宽度转换为距离（单位：厘米）
  float distance = (duration / 2) * 0.0343;

  // 将浮点数距离值转换为整数
  int intDistance = static_cast<int>(distance);
  
  return intDistance;
}

void turnRight_m() {
  myServo.write(0);  // 舵机右转90度
  delay(1000);        // 延时1秒
}

void turnLeft_m() {
  myServo.write(180);  // 舵机左转90度
  delay(1000);        // 延时1秒
}

void reset_m() {
  myServo.write(90);  // 舵机左转90度
  delay(1000);        // 延时1秒
}

void test(int num1, int num2){
  if(num1<=7){
  digitalWrite(M1_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M1_SpeedPin, 0);  // 设置速度，范围是 0 到 255
  digitalWrite(M2_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M2_SpeedPin, 140);  // 设置速度，范围是 0 到 255
  delay(200); // 向左调整

  digitalWrite(M2_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M2_SpeedPin, 0);  // 设置速度，范围是 0 到 255
  digitalWrite(M1_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M1_SpeedPin, 160);  // 设置速度，范围是 0 到 255
  delay(200); // 向右调整

    stopMotors();
    delay(1000);
  
  }

  if(num2<=7){
  digitalWrite(M1_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M1_SpeedPin, 0);  // 设置速度，范围是 0 到 255
  digitalWrite(M2_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M2_SpeedPin, 160);  // 设置速度，范围是 0 到 255
  delay(300); // 向右调整

  digitalWrite(M2_DirectionPin1, LOW);  // 设置为 LOW 表示反向
  analogWrite(M2_SpeedPin, 0);  // 设置速度，范围是 0 到 255
  digitalWrite(M1_DirectionPin1, HIGH);  // 设置为 HIGH 表示正向
  analogWrite(M1_SpeedPin, 140);  // 设置速度，范围是 0 到 255
  delay(300); // 向左调整

    stopMotors();
    delay(1000);

  }
}

void loop() {
  myServo.write(90);
  getDistance();
  int distance_1 = getDistance();
  int distance_2;
  int distance_3;


  if(distance_1>14){
    moveForward();
    distance_1 = getDistance();
    
  }

  if(distance_1<=14){
    stopMotors();
    delay(1000);
    turnRight_m();
    distance_2 = getDistance();
    reset_m();


    turnLeft_m();
    distance_3 = getDistance();
    reset_m();

    
    
    if(distance_2>=distance_3){
      if(distance_2>=29){
        test(distance_2 , distance_3);
        moveForward();
        delay(100);

        turnRight90Degrees();
        
      }

      if(distance_2<31){
          test(distance_2 , distance_3);
          moveBackward();
          delay(100);
          make180DegreesTurn_R();
          stopMotors();
          delay(1000);
      }
    }

    if(distance_2<distance_3){

      
      
      if(distance_3>29){
        test(distance_2 , distance_3);
        moveForward();
        delay(100);
        turnLeft90Degrees();

        distance_1 = getDistance();
      }
      if(distance_3<=29){
        

          test(distance_2 , distance_3);
          moveBackward();
          delay(100);
          make180DegreesTurn_L();
          stopMotors();
          delay(1000);
        
        /*make180DegreesTurn();
        stopMotors();
        delay(1000);*/
      }
    }
    else{
      stopMotors();
      delay(2000);
      
      distance_1 = getDistance();
    }
    

  }

  // 在这里可以添加其他运动逻辑，比如停车、转弯等
}