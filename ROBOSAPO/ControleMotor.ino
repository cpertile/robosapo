/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */
// Motor A
#define PINO_PWM_MOTOR_A 13
#define PINO_MOTOR_A1 12
#define PINO_MOTOR_A2 11

// Motor B
#define PINO_PWM_MOTOR_B 8
#define PINO_MOTOR_B1 10
#define PINO_MOTOR_B2 9

// Parâmetros gerais de PWM
#define PWM_MINIMO 0
#define PWM_MAXIMO 255
float pwm_a = 15;
float pwm_b = 19;

void inicializarMotores() {
  setarMotoresEmFrente();
}

void setarMotoresEmFrente() {
  // Motor A -> 0%
  pinMode(PINO_PWM_MOTOR_A, OUTPUT);
  pinMode(PINO_MOTOR_A1, OUTPUT);
  pinMode(PINO_MOTOR_A2, OUTPUT);

  digitalWrite(PINO_MOTOR_A1, HIGH);
  digitalWrite(PINO_MOTOR_A2, LOW);
  analogWrite(PINO_PWM_MOTOR_A, PWM_MINIMO);
 
  // Motor B -> 0%
  pinMode(PINO_PWM_MOTOR_B, OUTPUT);
  pinMode(PINO_MOTOR_B1, OUTPUT);
  pinMode(PINO_MOTOR_B2, OUTPUT);  

  digitalWrite(PINO_MOTOR_B1, LOW);
  digitalWrite(PINO_MOTOR_B2, HIGH);
  analogWrite(PINO_PWM_MOTOR_B, PWM_MINIMO);

  // Log
  // Serial.println("Inicializando Motores...");
}

void setarMotoresParaTras() {
  // Motor A -> 0%
  pinMode(PINO_PWM_MOTOR_A, OUTPUT);
  pinMode(PINO_MOTOR_A1, OUTPUT);
  pinMode(PINO_MOTOR_A2, OUTPUT);

  digitalWrite(PINO_MOTOR_A1, LOW);
  digitalWrite(PINO_MOTOR_A2, HIGH);
  analogWrite(PINO_PWM_MOTOR_A, PWM_MINIMO);
 
  // Motor B -> 0%
  pinMode(PINO_PWM_MOTOR_B, OUTPUT);
  pinMode(PINO_MOTOR_B1, OUTPUT);
  pinMode(PINO_MOTOR_B2, OUTPUT);  

  digitalWrite(PINO_MOTOR_B1, HIGH);
  digitalWrite(PINO_MOTOR_B2, LOW);
  analogWrite(PINO_PWM_MOTOR_B, PWM_MINIMO);

  // Log
  // Serial.println("Inicializando Motores Invertidos...");
}

void pararMotores() {
  // Seta aceleração em 0
  analogWrite(PINO_PWM_MOTOR_A, 0);
  analogWrite(PINO_PWM_MOTOR_B, 0); 

  // Log
  // Serial.println("Parando motores...");
}

void desligarMotores() {
  // Desliga fisicamente a ponte H
  digitalWrite(PINO_MOTOR_A1, LOW);
  digitalWrite(PINO_MOTOR_A2, LOW);

  digitalWrite(PINO_MOTOR_B1, LOW);
  digitalWrite(PINO_MOTOR_B2, LOW);
}

void aceleracaoConjunta(int porcentagem_pwm) {
  /* Acelera os dois motores à mesma porcentagem de pwm */

  // Verifica a porcentagem recebida
  if (!pwmValido(porcentagem_pwm)) {
    return;
  }

  // Converte para um valor analógico e envia aos motores
  int pwm_convertido = map(porcentagem_pwm, 0, 100, PWM_MINIMO, PWM_MAXIMO);
  analogWrite(PINO_PWM_MOTOR_A, pwm_convertido);
  analogWrite(PINO_PWM_MOTOR_B, pwm_convertido);
}

void aceleracaoConjuntaGradual(int tempo) {
  /* Demonstra o funcionamento dos motores com uma aceleração gradual pelo tempo recebido */
  
  int pwm = PWM_MINIMO;
  for (pwm; pwm <= PWM_MAXIMO; pwm += 25)
  {
    String mensagem = "Acelerando motores a " + String(pwm) + " PWM";
    Serial.println(mensagem);
    analogWrite(PINO_PWM_MOTOR_A, pwm);
    analogWrite(PINO_PWM_MOTOR_B, pwm);
    espera(tempo);
  }
}

void aceleracaoDiferencial(int pwm_a, int pwm_b) {
  /* Acelera os motores com porcentagens diferentes */

  // Verifica as porcentagens recebidas
  if (!pwmValido(pwm_a)) {
    Serial.println("PWM A inválido.");
    return;
  }
  if (!pwmValido(pwm_b)) {
    Serial.println("PWM B inválido.");
    return;
  }

  // Converte para um valor analógico e envia aos motores
  int pwm_a_convertido = map(pwm_a, 0, 100, PWM_MINIMO, PWM_MAXIMO);
  int pwm_b_convertido = map(pwm_b, 0, 100, PWM_MINIMO, PWM_MAXIMO);
  analogWrite(PINO_PWM_MOTOR_A, pwm_a_convertido);
  analogWrite(PINO_PWM_MOTOR_B, pwm_b_convertido);
}

void realizarParadaRapida() {
  // Inverte o sentido de rotação dos motores, acelera para trás por um instante para diminuir a velocidade, 
  // desliga a aceleração dos motores e retorna para o sentido normal de rotação
  setarMotoresParaTras();
  aceleracaoConjunta(100);
  pararMotores();
  setarMotoresEmFrente();
}

bool pwmValido(int porcentagem_pwm) {
  if (porcentagem_pwm < 0 || porcentagem_pwm > 100) {
    Serial.println("Porcentagem inválida (permitido: 0-100)");
    return false;
  } else {
    return true;
  }
}
