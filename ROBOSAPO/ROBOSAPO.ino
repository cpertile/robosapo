/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

// Motor A
#define PINO_PWM_MOTOR_A 5
#define PINO_MOTOR_A1 3
#define PINO_MOTOR_A2 4

// Motor B
#define PINO_PWM_MOTOR_B 6
#define PINO_MOTOR_B1 7
#define PINO_MOTOR_B2 8

// Parâmetros gerais
#define ACELERACAO 20
#define PWM_MINIMO 0
#define PWM_MAXIMO 255
 
void setup() {
  Serial.begin(9600);
  
  Serial.println("Inicializando Motor A...");
  pinMode(PINO_PWM_MOTOR_A, OUTPUT);
  pinMode(PINO_MOTOR_A1, OUTPUT);
  pinMode(PINO_MOTOR_A2, OUTPUT);

  // Inicializando Motor A em 0% no sentido necessário
  analogWrite(PINO_PWM_MOTOR_A, PWM_MINIMO);
  digitalWrite(PINO_MOTOR_A1, LOW);
  digitalWrite(PINO_MOTOR_A2, HIGH);
 
  Serial.println("Inicializando Motor B...");
  pinMode(PINO_PWM_MOTOR_B, OUTPUT);
  pinMode(PINO_MOTOR_B1, OUTPUT);
  pinMode(PINO_MOTOR_B2, OUTPUT);

  // Inicializando Motor B em 0% no sentido necessário
  analogWrite(PINO_PWM_MOTOR_B, PWM_MINIMO);
  digitalWrite(PINO_MOTOR_B1, HIGH);
  digitalWrite(PINO_MOTOR_B2, LOW);
}

void loop() {
//  AcelerarMotores(ACELERACAO);
//  Espera(1);
//  PararMotores();
//  Espera(0.5);

  AcelerarGradualmente(2);

//  AcelerarTotal();
}

void Espera(float segundos) {
  if (segundos < 0 || segundos > 10) {
    Serial.println("Espera inválida (permitido: 0-10)");
    return;
  }
  
  int ms = segundos * 1000;
  
  String mensagem = "Aplicando delay de " + String(ms) + " ms...";
  Serial.println(mensagem);
  delay(ms);
}
