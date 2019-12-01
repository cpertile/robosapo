/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 * Ordem de leitura dos sensores:
 *    - Esquerda
 *    - Centro
 *    - Direita
 */

void inicializarSeguidores() {
 pinMode(PINO_SENSOR_ESQUERDO, INPUT);
 pinMode(PINO_SENSOR_CENTRAL, INPUT);
 pinMode(PINO_SENSOR_DIREITO, INPUT);
}

void lerSensoresLinha() {
  esquerdoNaLinha = digitalRead(PINO_SENSOR_ESQUERDO);
  centralNaLinha = digitalRead(PINO_SENSOR_CENTRAL);
  direitoNaLinha = digitalRead(PINO_SENSOR_DIREITO);

  // String mensagem = "ESQ: " + String(esquerdoNaLinha) + " | MEI: " + String(centralNaLinha) + " | DIR: " + String(direitoNaLinha);
  // Serial.println(mensagem);
}

bool verificarFimDeLinha() {
  // Condição de parada
  if (esquerdoNaLinha && centralNaLinha && direitoNaLinha) {
    return true;
  } else {
    return false;
  }
}
