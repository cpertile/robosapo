void PararMotores() {
  Serial.println("Parando motores...");
  analogWrite(PINO_PWM_MOTOR_A, 0);
  analogWrite(PINO_PWM_MOTOR_B, 0);
}

void AceleracaoConjunta(int porcentagem_pwm) {
  if (porcentagem_pwm < 0 || porcentagem_pwm > 100) {
    Serial.println("Porcentagem inválida (permitido: 0-100)");
    return;
  }
    
  int pwm_convertido = map(porcentagem_pwm, 0, 100, PWM_MINIMO, PWM_MAXIMO);
  
  String mensagem = "Acelerando motores a " + String(pwm_convertido) + " PWM";
  analogWrite(PINO_PWM_MOTOR_A, pwm_convertido);
  analogWrite(PINO_PWM_MOTOR_B, pwm_convertido);
}

void AceleracaoConjuntaGradual(int espera) {
  int pwm = PWM_MINIMO;
  for (pwm; pwm <= PWM_MAXIMO; pwm += 25)
  {
    String mensagem = "Acelerando motores a " + String(pwm) + " PWM";
    Serial.println(mensagem);
    analogWrite(PINO_PWM_MOTOR_A, pwm);
    analogWrite(PINO_PWM_MOTOR_B, pwm);
    Espera(espera);
  }
}

void AceleracaoDiferencial(int pwm_a, int pwm_b) {
  int pwm_a_convertido = map(pwm_a, 0, 100, PWM_MINIMO, PWM_MAXIMO);
  int pwm_b_convertido = map(pwm_a, 0, 100, PWM_MINIMO, PWM_MAXIMO);
  
  String mensagemA = "Acelerando Motor A: " + String(pwm_a_convertido) + " PWM";
  String mensagemB = "Acelerando Motor B: " + String(pwm_b_convertido) + " PWM";
  Serial.println(mensagemA);
  Serial.println(mensagemB);
  analogWrite(PINO_PWM_MOTOR_A, pwm_convertido);
  analogWrite(PINO_PWM_MOTOR_B, pwm_convertido);
}
