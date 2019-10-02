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

// Detector de Obstáculos
#define PINO_TRIGGER 12
#define PINO_ECHO 13

// Parâmetros gerais
#define ACELERACAO 20
#define PWM_MINIMO 0
#define PWM_MAXIMO 255
#define PWM_A 25
#define PWM_B 16

void setup() {
  Serial.begin(9600);
  InicializarMotores();
}

void loop() {
  GetDistanciaObstaculo();
  AceleracaoDiferencial(PWM_A, PWM_B);
  Espera(2);
  GetDistanciaObstaculo();
  CurvaEsquerda();
  Espera(2);
  GetDistanciaObstaculo();
  CurvaDireita();
  Espera(2);
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
