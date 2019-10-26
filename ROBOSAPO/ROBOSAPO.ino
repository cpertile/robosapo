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

// Sensores de Linha
#define PINO_ANALOGICO_SENSOR_CENTRAL A4
#define PINO_ANALOGICO_SENSOR_ESQUERDO A7
#define PINO_ANALOGICO_SENSOR_DIREITO A0
bool esquerdoNaLinha = true;
bool centralNaLinha = true;
bool direitoNaLinha = true;

// Parâmetros gerais
#define PWM_MINIMO 0
#define PWM_MAXIMO 255
float pwm_a = 25;
float pwm_b = 16;

// PID
float Kp = 3;
float Ki = 1;
float Kd = 3;
float PID = 0;
float erro_anterior = 0;
float erro_integral = 0;

void setup() {
  Serial.begin(9600);
  inicializarMotores();
  inicializarSeguidores();
  espera(1);
}

void loop() {
  lerSensores();
  calcularPID();
  aplicarPID();
}

void espera(float segundos) {
  if (segundos < 0 || segundos > 10) {
    Serial.println("Espera inválida (permitido: 0-10)");
    return;
  }
  
  int ms = segundos * 1000;
  
  String mensagem = "Aplicando delay de " + String(ms) + " ms...";
  Serial.println(mensagem);
  delay(ms);
}
