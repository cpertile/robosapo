// S.A.P.O. - Seguidor Automático de Percurso Orientado

#include <hcsr04.h>

#define TRIG_PIN 2
#define ECHO_PIN 4

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Distancia: ");
  Serial.print(hcsr04.distanceInMillimeters());
  Serial.println(" mm");

  delay(250);
}
