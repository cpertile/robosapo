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

// Detector de Obstáculos
#define PINO_TRIGGER 40
#define PINO_ECHO 41
bool obstaculoDetectado = false;

// Sensores de Linha
#define PINO_SENSOR_CENTRAL 3
#define PINO_SENSOR_ESQUERDO 2
#define PINO_SENSOR_DIREITO 4
bool esquerdoNaLinha = true;
bool centralNaLinha = true;
bool direitoNaLinha = true;

// Parâmetros gerais de PWM
#define PWM_MINIMO 0
#define PWM_MAXIMO 255
float pwm_a = 17;
float pwm_b = 21;

// Constantes PID
float Kp = 10.5;
float Ki = 1.1;
float Kd = 9.5;
float PID = 0;
float erro_anterior = 0;
float erro_integral = 0;

// Variáveis de controle geral
bool andando = false;
bool cuboCarregado = false;
bool detectadoFimDeLinha = false;

void setup() {
  Serial.begin(9600);
  inicializarSeguidores();
  inicializarMotores();
  espera(1);
}

void loop() {
  // Verificar presença ou não de obstáculo
  obstaculoDetectado = lerDetectorObstaculo();

  if (obstaculoDetectado) {
    realizarParadaRapida();
  } else {
    // Fazer leitura da linha
    lerSensoresLinha();
    detectadoFimDeLinha = verificarFimDeLinha();
    if (detectadoFimDeLinha) {
      realizarParadaRapida();
    } else {
      setarMotoresEmFrente();
      calcularPID();
      aplicarPID();
      andando = true;
    }
  }
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
