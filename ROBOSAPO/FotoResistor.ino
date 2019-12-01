/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

int fotoResistorCentral;
int fotoResistorEsquerdo;
int fotoResistorDireito;

void lerFotoResistores() {
  fotoResistorCentral = analogRead(PINO_FOTORESISTOR_CENTRAL);
  fotoResistorEsquerdo = analogRead(PINO_FOTORESISTOR_ESQUERDO);
  fotoResistorDireito = analogRead(PINO_FOTORESISTOR_DIREITO);
}

bool verificarCuboCarregado() {
  lerFotoResistores();
//  Serial.println("LDR: " + String(fotoResistorEsquerdo) + " " + String(fotoResistorCentral) + " " + String(fotoResistorDireito));
  if (fotoResistorCentral > 400 || fotoResistorEsquerdo > 400 || fotoResistorDireito > 400) {
    return true;
  } else {
    return false;
  }
}
