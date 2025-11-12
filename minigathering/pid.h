int MaxSpeed = 100;
int MinSpeed = 0;
int ModePidStatus = 0;
int LastError;

int tocenter = 0;

void ModeSpdPID(int Mod,int max, int min) {
  ModePidStatus = Mod;
  MaxSpeed = max;
  MinSpeed = min;
}

void SetCenter(int x){
tocenter = x;


}

int readPosition(int Track, int noise) {
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrate();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = F[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
    // if (sum == 0) {
    //     return last_value; // ใช้ค่าตำแหน่งล่าสุดเมื่อไม่มีเส้น
    // }
  last_value = avg / sum;
  return last_value;
}

void PID(int SpeedL,int SpeedR, float Kp, float Kd) {
  int Pos = readPosition(300, 50);
  int Error = Pos - ((NUM_SENSORS - 1) * 1000 / 2);
  int PID_Value = ((Kp/1000) * Error) + ((Kd/100) * (Error - LastError));
  LastError = Error;
 int LeftPower = SpeedL + PID_Value;
  int RightPower = SpeedR - PID_Value;
  if (ModePidStatus == 0) {
    if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
    if (LeftPower < 0) LeftPower = MinSpeed;
    if (RightPower > MaxSpeed) RightPower = MaxSpeed;
    if (RightPower < 0) RightPower = MinSpeed;
  } else if (ModePidStatus == 1) {
    if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
    if (LeftPower < MinSpeed) LeftPower = MinSpeed;
    if (RightPower > MaxSpeed) RightPower = MaxSpeed;
    if (RightPower < MinSpeed) RightPower = MinSpeed;
  } else if (ModePidStatus == 2) {
    if (LeftPower > SpeedL) LeftPower = SpeedL;
    if (LeftPower < -SpeedL) LeftPower = -SpeedL;
    if (RightPower > SpeedR) RightPower = SpeedR;
    if (RightPower < -SpeedR) RightPower = -SpeedR;
  }
  else {
    if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
    if (LeftPower < 0) LeftPower = 0;
    if (RightPower > MaxSpeed) RightPower = MaxSpeed;
    if (RightPower < 0) RightPower = 0;
  }
  Motor(LeftPower, RightPower);
}




void TrackSelect(int spd, char x) {
  if (x == 'S') {
    MotorStop();
  } 
  else if (x == 'p') {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(30);
    while (1) {
      Motor(LeftBaseSpeed, RightBaseSpeed);
      ReadCalibrate();
      if (F[0] < Ref && F[5] < Ref) {
        break;
      }
    }
  } 
  else if (x == 'l') {
    ToCenter();
    SpinL();
  } 
  else if (x == 'r') {
    ToCenter();
    SpinR();
  } 
  else if (x == 'f') {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(200/spd);
  } 
 
  else if (x == 'q') {
    while (1) {
      Motor(spd/2, spd/2);
      ReadCalibrate();
      if (F[0] < Ref) {
        break;
      }
    }
    TurnLeft();
  } 
  else if (x == 'e') {
    while (1) {
      Motor(spd/2, spd/2);
      ReadCalibrate();
      if (F[5] < Ref) {
        break;
      }
    }
    TurnRight();
  }

 
}

    


void FF(int Speed, char select) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if ((F[0] > Ref && F[5] > Ref ) || (F[0] > Ref && F[2] > Ref) || (F[3] > Ref && F[5] > Ref)) {
      break;
    }
  }
  TrackSelect(Speed, select);
}

void FFC(int Speed,  char select) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if ((F[0] > Ref && F[5] > Ref)) {
      break;
    }
  }
  TrackSelect(Speed, select);
}
void FFC2(int Speed,  char select) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if ((F[0] > Ref && F[1] > Ref && F[2] > Ref )) {
      break;
    }
  }
  TrackSelect(Speed, select);
}


void FFR(int Speed,  char select) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if ((F[3] > Ref && F[5] > Ref)) {
      break;
    }
  }
  TrackSelect(Speed, select);
}
void FFR2(int Speed,  char select) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if ((F[3] > Ref && F[4] > Ref && F[5] > Ref )) {
      break;
    }
  }
  TrackSelect(Speed, select);
}
void FFL(int Speed, char select) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if ((F[0] > Ref && F[2] > Ref)) {
      break;
    }
  }
  TrackSelect(Speed, select);
}



void FF_DISTANCED(int Speed,char select,int dist) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);

    if (sonar.ping_cm() > dist) {
      MotorStop();
      Beep(10);
      break;
    }
  }
  TrackSelect(Speed, select);
}

void FFTimer(int Speed, int TotalTime) {
  BaseSpeed = Speed;
  InitialSpeed();
  unsigned long StartTime = millis();
  unsigned long EndTime = StartTime + TotalTime;
  while (millis() <= EndTime) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
  }
  // Beep(10);
}

void FFNUM(int Speed, char select,int numm) {
  BaseSpeed = Speed;
  InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if (F[numm] > Ref) {
      break;
    }
  }
  TrackSelect(Speed, select);
}

void FFWhite(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  while (1) {
    PID(LeftBaseSpeed,RightBaseSpeed, PID_Kp, PID_Kd);
    ReadCalibrate();
    if ((F[0] < Ref && F[1] < Ref && F[2] < Ref && F[3] < Ref && F[4] < Ref && F[5] < Ref )) {
      break;
    }
  }
  TrackSelect(Speed, select);
}

void FFBlack(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  Move(LeftBaseSpeed,RightBaseSpeed,50);
  while (1) {
    Motor(LeftBaseSpeed,RightBaseSpeed);
    ReadCalibrate();
    if (F[0] > Ref || F[1] > Ref || F[2] > Ref || F[3] > Ref || F[4] > Ref || F[5] > Ref) {
      break;
    }
  }
  TrackSelect(Speed, select);
}