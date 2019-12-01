/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

int calibracaoInicial;
int limiteOperacional;

int fotoResistorCentral;
int fotoResistorEsquerdo;
int fotoResistorDireito;

void lerFotoResistores() {
  fotoResistorCentral = analogRead(PINO_FOTORESISTOR_CENTRAL);
  fotoResistorEsquerdo = analogRead(PINO_FOTORESISTOR_ESQUERDO);
  fotoResistorDireito = analogRead(PINO_FOTORESISTOR_DIREITO);
}

void calibrarFotoResistores() {
	lerFotoResistores();
	calibracaoInicial = (fotoResistorCentral + fotoResistorEsquerdo + fotoResistorDireito) / 3;
	limiteOperacional = calibracaoInicial * 1.5;

	Serial.println("calibracaoInicial: " + String(calibracaoInicial));
	Serial.println("limiteOperacional: " + String(limiteOperacional));
}

bool verificarCuboCarregado() {
  lerFotoResistores();
  Serial.println("LDR: " + String(fotoResistorEsquerdo) + " " + String(fotoResistorCentral) + " " + String(fotoResistorDireito));
  if (fotoResistorCentral > limiteOperacional || fotoResistorEsquerdo > limiteOperacional || fotoResistorDireito > limiteOperacional) {
    return true;
  } else {
    return false;
  }
}
