/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

void lerFotoResistores() {
	int fotoResistorCentral = analogRead(PINO_FOTORESISTOR_CENTRAL);
	int fotoResistorEsquerdo = analogRead(PINO_FOTORESISTOR_ESQUERDO);
	int fotoResistorDireito = analogRead(PINO_FOTORESISTOR_DIREITO);
}

bool cuboCarregado() {
	lerFotoResistores();

	if (fotoResistorCentral > 100 || fotoResistorEsquerdo > 100 || fotoResistorDireito > 100) {
		return true;
	} else {
		return false;
	}
}