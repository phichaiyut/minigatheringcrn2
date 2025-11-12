#include <ESP32Servo.h>
#include <NewPing.h>  // เรียกใช้งานไลบรารี NewPing
#include <minigathering.h>

Servo servo_gripper;
Servo servo_base;

// Servo Pin
const int servo_gripper_PIN = 14;
const int servo_base_PIN = 12;


void setup() {
  // put your setup code here, to run once:
  servo_gripper.attach(servo_gripper_PIN);
  servo_base.attach(servo_base_PIN);
  robotsetup();


  SensorValueMin(493, 481, 701, 80, 790, 1455); //ค่าแสงต่ำสุด
  SensorValueMax(3333, 3280, 3500, 3400, 3700, 3700); //ค่าแสงสูงสุด

  //SensorValueF(493, 481, 701, 80, 790, 1455, 3333, 3280, 3500, 3400, 3700, 3700);

  TurnSpeedLeft(0, 25, 80, 40);   // ค่าเลี้ยวซ้าย TurnSpeedLeft(ช่องเซนเซอร์, มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  TurnSpeedRight(5, 80, 25, 40);  // ค่าเลี้ยวขวา TurnSpeedRight(ช่องเซนเซอร์, มอเตอร์ซ้าย, มอเตอร์ขวา, เวลาเลี้ยว);
  SetTurnSpeed(60);               //ความเร็วเลี้ยว

  SetKpKd();           //ตั้งค่า kp kd
  SetSpeedForward();   // setup balance เดินหน้า
  SetSpeedBackward();  // setup balance ถอยหลัง

  TrackLineColor(0);  //0 >> พื้นขาวเส้นดำ  1 >> พื้นดำเส้นขาว
  RefLineValue(500); //ค่าที่วัดวัดแยก

  ModeSpdPID(1, 100, -100);
  // SerialSensor();  // Serial Monitor ค่าของ Sensor
  // SerialCalibrate();  // Serial Monitor ค่าของ Sensor ที่ Calibrate แล้ว
  // SerialDistance(); //Serial Monitor ค่าของ Sensor ระยะทาง
  servo(50, 40);  //เซอร์โวเริ่มต้น+


  wait_start(); //รอจนกว่าจะกดปุ่ม


  //__________________________________วางโค้ดใหม่หลังจากนี้บรรทัดนี้ทั้งหมด______________________________________________________________________
  //เอาโค้ดไปใส่ใน Mission
  Mission();

  MotorStop();
}  //______________________ปีกกาห้ามลบ________________________

void loop() {
  // put your main code here, to run repeatedly:
}
