/*
 * S.A.P.O. - Seguidor Autônomo de Percurso Orientado
 */

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
  calibrarFotoResistores();
  espera(3);
}

void loop() {
  switch(estagioAtual) {
    // Aguardar carregamento do cubo
    case ESTAGIO_INICIAL: 
    Serial.println("Estágio inicial");
      cuboCarregado = verificarCuboCarregado();

      if (cuboCarregado) {
        // Ativar eletroímã
        avancarEstagio();
      }
      break;

    case ESTAGIO_TRANSPORTE:
    Serial.println("Estágio transporte");
      // Verificar presença ou não de obstáculo
      obstaculoDetectado = lerDetectorObstaculo();

      if (obstaculoDetectado) {
        realizarParadaRapida();
        while(obstaculoDetectado) {
          obstaculoDetectado = lerDetectorObstaculo();
        }
      }
      
      // Fazer leitura da linha
      lerSensoresLinha();
      detectadoFimDeLinha = verificarFimDeLinha();
      // Se detectado o fim da linha, parar o robô e aguardar descarregamento
      if (detectadoFimDeLinha) {
        realizarParadaRapida();
        // Desligar eletroímã
        while (cuboCarregado) {
          cuboCarregado = verificarCuboCarregado();
        }
        avancarEstagio();
        break;
      }

      // Caso não tenha detectado obstáculo e nem o fim da linha, deve seguir o percurso
      calcularPID();
      aplicarPID();
      break;

    case ESTAGIO_RETORNO:
    Serial.println("Estágio retorno");
      // Verificar presença ou não de obstáculo
      obstaculoDetectado = lerDetectorObstaculo();

      if (obstaculoDetectado) {
        realizarParadaRapida();
        break;
      }

      // Fazer leitura da linha
      lerSensoresLinha();
      detectadoFimDeLinha = verificarFimDeLinha();
      // Se detectado o fim da linha, parar o robô
      if (detectadoFimDeLinha) {
        realizarParadaRapida();
        avancarEstagio();
        break;
      }

      // Caso não tenha detectado obstáculo e nem o fim da linha, deve seguir o percurso
      calcularPID();
      aplicarPID();
      break;
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
