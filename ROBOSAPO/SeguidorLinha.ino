/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 * Ordem de leitura dos sensores:
 *    - Esquerda
 *    - Centro
 *    - Direita
 */
#define NUM_SENSORES 3

void incializarSeguidores() {
 pinMode(PINO_ANALOGICO_SENSOR_ESQUERDO, INPUT);
 pinMode(PINO_ANALOGICO_SENSOR_CENTRAL, INPUT);
 pinMode(PINO_ANALOGICO_SENSOR_DIREITO, INPUT);
}

bool sensorNaLinha(int leitura) {
  if (leitura > 100) {
    return true;
  } else {
    return false;
  }
}

void lerSensores() {
  int leituraEsquerdo = analogRead(PINO_ANALOGICO_SENSOR_ESQUERDO);
  int leituraCentral = analogRead(PINO_ANALOGICO_SENSOR_CENTRAL);
  int leituraDireito = analogRead(PINO_ANALOGICO_SENSOR_DIREITO);  
 
  bool esquerdoNaLinha = sensorNaLinha(leituraEsquerdo);
  bool centralNaLinha = sensorNaLinha(leituraCentral);
  bool direitoNaLinha = sensorNaLinha(leituraDireito);

  Serial.println("ESQ: " + esquerdoNaLinha + "|  MEI: " + centralNaLinha + "| DIR: " + direitoNaLinha);
  delay(10);
}
