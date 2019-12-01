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

// Constantes PID
float Kp = 4;
float Ki = 1;
float Kd = 3;
float PID = 0;
float erro_anterior = 0;
float erro_integral = 0;

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

// Fotoresistores
#define PINO_FOTORESISTOR_CENTRAL A0
#define PINO_FOTORESISTOR_ESQUERDO A1
#define PINO_FOTORESISTOR_DIREITO A2

// Variáveis de controle geral
bool andando = false;
bool cuboCarregado = false;
bool detectadoFimDeLinha = false;

// Controle de Estágios
#define ESTAGIO_INICIAL 0
#define ESTAGIO_TRANSPORTE 1
#define ESTAGIO_RETORNO 2
int estagioAtual = ESTAGIO_INICIAL;

void setup() {
  Serial.begin(9600);
  inicializarSeguidores();
  inicializarMotores();
  espera(1);
}

void loop() {

  switch(estagioAtual) {
    case ESTAGIO_INICIAL:
    Serial.println("Estagio inicial");
    break;

    case ESTAGIO_TRANSPORTE:
    Serial.println("Estagio Transporte");
    break;

    case ESTAGIO_RETORNO:
    Serial.println("Estagio retorno");
    break; 
    
    default: ESTAGIO_INICIAL;
  }

  espera(2);
  proximoEstagio();

  // // Verificar presença ou não de obstáculo
  // obstaculoDetectado = lerDetectorObstaculo();

  // // Leitura carregamento cubo
  // cuboCarregado = verificarCuboCarregado();
  
  // if (obstaculoDetectado) {
  //   // Serial.println("Obstaculo detectado");
  //   realizarParadaRapida();
  // } else {
  //   // Serial.println("Caminho Livre");
  //   // Fazer leitura da linha
  //   lerSensoresLinha();
  //   detectadoFimDeLinha = verificarFimDeLinha();
  //   if (detectadoFimDeLinha) {
  //     // Serial.println("Detectado fim de linha");
  //     realizarParadaRapida();
  //   } else if (cuboCarregado) {
  //     // Serial.println("Acelerando e calculando PID");
  //     setarMotoresEmFrente();
  //     calcularPID();
  //     aplicarPID();
  //     andando = true;
  //   }
  // }
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
