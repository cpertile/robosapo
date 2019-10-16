#include <Servo.h>

Servo servo1;
const int pinoServo = 7;
int posicaoServo = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(pinoServo);
}

void loop() {
  for (posicaoServo = 0; posicaoServo <= 179; posicaoServo += 15) {
    Serial.println("Posicao(graus): " + String(posicaoServo));
    servo1.write(posicaoServo);
    delay(500);
  }

  for (posicaoServo = 180; posicaoServo > 0; posicaoServo -= 15) {
    Serial.println("Posicao(graus): " + String(posicaoServo));
    servo1.write(posicaoServo);
    delay(500);
  }
}
