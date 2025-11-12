#include "sensor.h"
#include "motor.h"
#include "initial.h"
#include "forwardbackwardandturn.h"
#include "turn.h"
#include "pid.h"

void robotsetup(){
    Serial.begin(115200);
    pinMode(button, INPUT_PULLUP);  // กำหนดให้ขา button เป็น INPUT แบบ PULLUP
  // Set buzzer controller pins as output
  pinMode(buzzer, OUTPUT);     // กำหนดให้ขา buzzer เป็น OUTPUT
  digitalWrite(buzzer, HIGH);  //กำหนดค่าเริ่มต้นของ buzzer ให้ไม่ดัง

  pinMode(leftMotorPin_IN1, OUTPUT);
  pinMode(rightMotorPin_IN1, OUTPUT);
  pinMode(leftMotorPin_IN2, OUTPUT);
  pinMode(rightMotorPin_IN2, OUTPUT);
  beep();

  Motor(0, 0);  // เริ่มต้นหยุด


}


void wait_start() {  //ฟังก์ชันรอการกดปุ่ม
  MotorStop(100);
  while (digitalRead(button) != 0) {  //ติดลูปค้างไว้ถ้ายังไม่กดปุ่ม
    ;
  }
  Serial.println("Push Switch");
  beep();
  delay(300);
}

