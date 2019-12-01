/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

void lerFotoResistores() {
	int fotoResistorCentral = analogRead(PINO_FOTORESISTOR_CENTRAL);
	int fotoResistorEsquerdo = analogRead(PINO_FOTORESISTOR_ESQUERDO);
	int fotoResistorDireito = analogRead(PINO_FOTORESISTOR_DIREITO);

  Serial.println("FotoResistor Central: " + String(fotoResistorCentral));
  Serial.println("FotoResistor Esquerdo: " + String(fotoResistorEsquerdo));
  Serial.println("FotoResistor Direito: " + String(fotoResistorDireito));
}
