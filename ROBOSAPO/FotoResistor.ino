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

  if (fotoResistorCentral > 100 || fotoResistorEsquerdo > 100 || fotoResistorDireito > 100) {
    return true;
  } else {
    return false;
  }
}
