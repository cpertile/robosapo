/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 * Ordem de leitura dos sensores:
 *    - Esquerda
 *    - Centro
 *    - Direita
 */
#define NUM_SENSORES 3

void inicializarSeguidores() {
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
 
  esquerdoNaLinha = sensorNaLinha(leituraEsquerdo);
  centralNaLinha = sensorNaLinha(leituraCentral);
  direitoNaLinha = sensorNaLinha(leituraDireito);

  String mensagem = "ESQ: " + String(leituraEsquerdo) + " | MEI: " + String(leituraCentral) + " | DIR: " + String(leituraDireito);
  Serial.println(mensagem);
}

void decidirDirecao() {
  // Condição de parada
  if (esquerdoNaLinha && centralNaLinha && direitoNaLinha) {
    analogWrite(PINO_PWM_MOTOR_A, 0);
    analogWrite(PINO_PWM_MOTOR_B, 0);
    return;
  }

  // Curvas simples
  if (!esquerdoNaLinha && centralNaLinha && !direitoNaLinha) {
    aceleracaoDiferencial(PWM_A, PWM_B);
    return;
  }

  if (esquerdoNaLinha && !centralNaLinha && !direitoNaLinha) {
    curvaEsquerda();
    return;
  }

  if (!esquerdoNaLinha && !centralNaLinha && direitoNaLinha) {
    curvaDireita();
    return;
  }

  // Curvas compostas

}
