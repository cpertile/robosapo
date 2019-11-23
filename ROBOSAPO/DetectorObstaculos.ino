/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

#include <HCSR04.h>

UltraSonicDistanceSensor SensorDistancia(PINO_TRIGGER, PINO_ECHO);

float getDistanciaAbsoluta() {
  float distanciaLida = SensorDistancia.measureDistanceCm();
//  Serial.println("Distancia lida direto: " + String(distanciaLida));
  return distanciaLida;
}

float getDistanciaNormalizada() {
	float distancia1 = getDistanciaAbsoluta();
	float distancia2 = getDistanciaAbsoluta();
	float distancia3 = getDistanciaAbsoluta();

	float distanciaNormalizada = (distancia1 + distancia2 + distancia3)/3;

	Serial.println("Distancia normalizada: " + String(distanciaNormalizada));
	return distanciaNormalizada;
}

void lerDetectorObstaculo() {
	float distancia = getDistanciaNormalizada();
	if (distancia >= 0 && distancia <= 35) {
		obstaculoDetectado = true;
	} else {
		obstaculoDetectado = false;
	}
}
