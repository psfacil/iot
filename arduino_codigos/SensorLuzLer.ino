//pino analog in (que o sensor esta ligado, que a placa vai receber o sinal)
int sensor = 1;

//pino digital/PWM onde o sinal digital ou PWM sera enviado
int pino = 3;

void setup() {
  Serial.begin(9600);
  pinMode(pino,OUTPUT);
}

void loop() {
  // lendo o valor do sensor que pode ser de 0 a 1023 (analogico)
  int valorSensor = analogRead(sensor);

  // lendo valor PWM convertido
  int valorPWM = map(valorSensor, 0,1023,255,0);

  // escrevendo na saida digital porem sinal PWM (nao eh 0/1, varia de 0 a 255, sai pela porta digital, como se fosse um amplificador classe D sinal quadrado)
  analogWrite(pino, valorPWM);

   // Exibindo o valores no monitor
  //Serial.println(valorSensor);
  Serial.println(valorPWM);

  delay(1);
}
