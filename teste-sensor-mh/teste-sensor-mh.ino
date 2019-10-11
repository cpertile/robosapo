#define PINO_ANALOGICO_MH_1 A15
#define PINO_DIGITAL_MH_1 7

#define PINO_ANALOGICO_MH_2 A8

void setup() {
  // put your setup code here, to run once:
 pinMode(PINO_ANALOGICO_MH_1, INPUT);
 pinMode(PINO_ANALOGICO_MH_2, INPUT);
 pinMode(PINO_DIGITAL_MH_1, INPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int leituraAnalogica1 = analogRead(PINO_ANALOGICO_MH_1);
  int leituraAnalogica2 = analogRead(PINO_ANALOGICO_MH_2);

  Serial.println("---------");
  Serial.print(leituraAnalogica2);
  Serial.print(" / ");
  Serial.println(leituraAnalogica1);
  

  delay(500);
}
