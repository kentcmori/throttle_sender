#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(115200);     //シリアル通信初期化
  servo.attach(2);
  pinMode(13,OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  static int val = 1000;
  //受信データがある場合if内を処理
  if (Serial.available() > 0) {
    delay(10);
    val = Serial.parseInt();

    while (Serial.available() > 0) {
      char t = Serial.read();
    }
    Serial.println(val*10);
  }
  servo.writeMicroseconds(val);
}
