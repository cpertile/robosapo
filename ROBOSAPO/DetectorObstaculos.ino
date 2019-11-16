/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

#include <HCSR04.h>

UltraSonicDistanceSensor SensorDistancia(PINO_TRIGGER, PINO_ECHO);

void getDistanciaObstaculo() {
  double distancia = SensorDistancia.measureDistanceCm();
  Serial.println(distancia);
}
