void PararMotores() {
  Serial.println("Parando motores...");
  analogWrite(PINO_PWM_MOTOR_A, 0);
  analogWrite(PINO_PWM_MOTOR_B, 0);
}

void AcelerarMotores(int porcentagem_pwm) {
  if (porcentagem_pwm < 0 || porcentagem_pwm > 100) {
    Serial.println("Porcentagem inválida (permitido: 0-100)");
    return;
  }
    
  int pwm_convertido = map(porcentagem_pwm, 0, 100, PWM_MINIMO, PWM_MAXIMO);
  
  String mensagem = "Acelerando motores a " + String(pwm_convertido) + " PWM";
  analogWrite(PINO_PWM_MOTOR_A, pwm_convertido);
  analogWrite(PINO_PWM_MOTOR_B, pwm_convertido);
}

void AcelerarGradualmente(int espera) {
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
