/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 * Ordem de leitura dos sensores:
 *    - Esquerda
 *    - Centro
 *    - Direita
 */
#define NUM_SENSORES 3

void inicializarSeguidores() {
 pinMode(PINO_SENSOR_ESQUERDO, INPUT);
 pinMode(PINO_SENSOR_CENTRAL, INPUT);
 pinMode(PINO_SENSOR_DIREITO, INPUT);
}

bool sensorNaLinha(int leitura) {
  if (leitura > 100) {
    return true;
  } else {
    return false;
  }
}

void lerSensoresLinha() {
  esquerdoNaLinha = digitalRead(PINO_SENSOR_ESQUERDO);
  centralNaLinha = digitalRead(PINO_SENSOR_CENTRAL);
  direitoNaLinha = digitalRead(PINO_SENSOR_DIREITO);

  String mensagem = "ESQ: " + String(esquerdoNaLinha) + " | MEI: " + String(centralNaLinha) + " | DIR: " + String(direitoNaLinha);
  Serial.println(mensagem);
}

void verificarFimDeLinha() {
  // Condição de parada
  if (esquerdoNaLinha && centralNaLinha && direitoNaLinha) {
    return true;
  }
}

void calcularPID() {
/*  Proporcional = Erro lido atualmente
 *  Integral = Erro proporcional somado com o erro anterior
 *  Derivado = Diferença (delta) do erro proporcional para o erro anterior 
 */

  float erro_proporcional;
  float erro_derivado;

  // Andar reto
  if (!esquerdoNaLinha && centralNaLinha && !direitoNaLinha) {
    erro_proporcional = 0;
  }

  // Curvas de 2 sensores
  if (esquerdoNaLinha && centralNaLinha && !direitoNaLinha) {
    erro_proporcional = -1;
  }

  if (!esquerdoNaLinha && centralNaLinha && direitoNaLinha) {
    erro_proporcional = 1;
  }

  // Curvas de 1 sensor
  if (esquerdoNaLinha && !centralNaLinha && !direitoNaLinha) {
    erro_proporcional = -1.5;
  }

  if (!esquerdoNaLinha && !centralNaLinha && direitoNaLinha) {
    erro_proporcional = 1.5;
  }

  if (!esquerdoNaLinha && !centralNaLinha && !direitoNaLinha) {
    /* Ao não detectar mais a linha, continuar fazendo o que estava fazendo antes
    com dois terços da intensidade */
    erro_proporcional = erro_anterior/3*2;
  }

  erro_integral = erro_integral + erro_proporcional;
  erro_derivado = erro_proporcional - erro_anterior;
  erro_anterior = erro_proporcional;

  PID = Kp * erro_proporcional + Ki * erro_integral + Kd * erro_derivado;
  
  Serial.println("PID = " + String(PID));
}

void aplicarPID() {
  // Devido aos sentidos de rotação, somar PID ao motor esquerdo e subtrair do motor direito

  float novo_pwm_a = pwm_a - PID;
  novo_pwm_a = constrain(novo_pwm_a, 0, 75);

  float novo_pwm_b = pwm_b + PID;
  novo_pwm_b = constrain(novo_pwm_b, 0, 75);
 
  aceleracaoDiferencial(novo_pwm_a, novo_pwm_b);

  String mensagem = "PWM_A = " + String(novo_pwm_a) + " | PWM_B = " + String(novo_pwm_b);

  Serial.println(mensagem);
}
