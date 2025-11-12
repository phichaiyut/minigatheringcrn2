void SetKpKd() {  //ตั้งค่า KP KD
  //setKpKd(SPD_10, KP, KD);
  setKpKd(SPD_10, 30, 30);
  setKpKd(SPD_20, 30, 30);
  setKpKd(SPD_30, 30, 30);
  setKpKd(SPD_40, 30, 60);
  setKpKd(SPD_50, 30, 60);
  setKpKd(SPD_60, 30, 30);
  setKpKd(SPD_70, 30, 30);
  setKpKd(SPD_80, 30, 22);
  setKpKd(SPD_90, 50, 50);
  setKpKd(SPD_100, 90, 90);
}

void SetSpeedForward() {  //เดินหน้า

  //setBalanceSpeed(SPD_10, ล้อซ้าย, ล้อขวา); ข้างไหนแรงกว่าไปเพิ่มข้างนั้น

  setBalanceSpeed(SPD_10, 0, 0);
  setBalanceSpeed(SPD_20, 0, 0);
  setBalanceSpeed(SPD_30, 0, 0);
  setBalanceSpeed(SPD_40, 0, 0);
  setBalanceSpeed(SPD_50, 0, 0);
  setBalanceSpeed(SPD_60, 0, 0);
  setBalanceSpeed(SPD_70, 0, 0);
  setBalanceSpeed(SPD_80, 0, 0);
  setBalanceSpeed(SPD_90, 0, 0);
  setBalanceSpeed(SPD_100, 0, 0);
}

void SetSpeedBackward() {  //ถอยหลัง

  //setBalanceBackSpeed(SPD_10, ล้อซ้าย, ล้อขวา); ข้างไหนแรงกว่าไปเพิ่มข้างนั้น

  setBalanceBackSpeed(SPD_10, 0, 0);
  setBalanceBackSpeed(SPD_20, 0, 0);
  setBalanceBackSpeed(SPD_30, 0, 0);
  setBalanceBackSpeed(SPD_40, 0, 0);
  setBalanceBackSpeed(SPD_50, 0, 0);
  setBalanceBackSpeed(SPD_60, 0, 0);
  setBalanceBackSpeed(SPD_70, 0, 0);
  setBalanceBackSpeed(SPD_80, 0, 0);
  setBalanceBackSpeed(SPD_90, 0, 0);
  setBalanceBackSpeed(SPD_100, 0, 0);
}