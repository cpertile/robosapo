// Constantes PID
float Kp = 8;
float Ki = 0;
float Kd = 0;
float PID = 0;
float erro_anterior = 0;
float erro_integral = 0;

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
    erro_proporcional = -2;
  }

  if (!esquerdoNaLinha && !centralNaLinha && direitoNaLinha) {
    erro_proporcional = 2;
  }

  if (!esquerdoNaLinha && !centralNaLinha && !direitoNaLinha) {
    // Ao não detectar mais a linha, continuar fazendo o que estava fazendo antes
    erro_proporcional = erro_anterior;
  }

  erro_integral = erro_integral + erro_proporcional;
  erro_derivado = erro_proporcional - erro_anterior;
  erro_anterior = erro_proporcional;

  PID = Kp * erro_proporcional + Ki * erro_integral + Kd * erro_derivado;
  
   Serial.println("PID = " + String(PID));
}

void aplicarPID() {
  // Devido aos sentidos de rotação, somar PID ao motor esquerdo e subtrair do motor direito
  float novo_pwm_a, novo_pwm_b;
  if (PID < 0) { // Curva à esquerda, subtrair do motor B
    novo_pwm_b = pwm_b + PID;
    novo_pwm_b = constrain(novo_pwm_b, 10, 20);
    novo_pwm_a = pwm_a;
  } else if (PID > 0) { // Curva à direita, subtrair do motor A
    novo_pwm_a = pwm_a - PID;
    novo_pwm_a = constrain(novo_pwm_a, 10, 20);
    novo_pwm_b = pwm_b;
  }
 
  aceleracaoDiferencial(novo_pwm_a, novo_pwm_b);

  String mensagem = "PWM_A = " + String(novo_pwm_a) + " | PWM_B = " + String(novo_pwm_b);
  Serial.println(mensagem);
}
