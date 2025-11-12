int pos1 = 90;
int pos2 = 90;

void servo(int de1, int de2) {
  MotorStop();
  servo_gripper.write(pos2 = de2);  //กำหนดให้มือจับอ้า
  servo_base.write(pos1 = de1);     //กำหนดให้มือจับยก
  delay(300);
}


void servo_up() {
  MotorStop();
  servo_base.write(90);  //กำหนดให้มือจับยก
  delay(300);
}

void servo_down() {
  MotorStop();
  servo_base.write(90);  //กำหนดให้มือจับยก
  delay(300);
}
void servo_open() {
  MotorStop();
  servo_gripper.write(90);  //กำหนดให้มือจับอ้า
  delay(300);
}
void servo_close_small() {
  MotorStop();
  servo_gripper.write(90);  //กำหนดให้มือจับอ้า
  delay(300);
}

void servo_close_big() {
  MotorStop();
  servo_gripper.write(90);  //กำหนดให้มือจับอ้า
  delay(300);
}
