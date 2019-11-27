#include <Servo.h>

// Constantes e Globais
#define PINO_SERVO_BASE 9
// #define PINO_SERVO_MEIO 
// #define PINO_SERVO_BOCA
#define ZERO 0
#define FULL 179
int angulo = 0;

// Instâncias + configs
Servo servoBase;
// Servo servoMeio;
// Servo servoBoca;

void setup() {
  Serial.begin(9600);
  servoBase.attach(PINO_SERVO_BASE);
}

void loop() {
  demo();
}

void tudoParaEsquerda() {
	servoBase.write(ZERO);
}

void tudoParaDireita() {
	servoBase.write(FULL);
}

void demo() {
	// Aplica o <angulo> no <servoBase> (0° -> 180° -> 0°)
	for (angulo = ZERO; angulo <= FULL; angulo += 15) {
    servoBase.write(angulo);
    Serial.println("Posicao(graus): " + String(angulo));
    delay(500);
  }

  for (angulo = FULL; angulo > ZERO; angulo -= 15) {
    servoBase.write(angulo);
    Serial.println("Posicao(graus): " + String(angulo));
    delay(500);
  }
}