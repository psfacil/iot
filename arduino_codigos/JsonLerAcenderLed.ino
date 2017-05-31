#include <ArduinoJson.h>

const int LED = 3;
const int analog = 1;
char nextChar = 0;
String valor;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.setTimeout(50);
}

void loop() {
  if(Serial.available() > 0) {
    char texto[200];
    Serial.readBytesUntil('\n', texto, 200);

    // criar o buffer de Json
    StaticJsonBuffer<200> buff;

    // decodificar o json que esta no texto
    JsonObject& obj = buff.parseObject(texto);

    //verificar se o objeto foi criado, escrever o valor no LED
    if(obj.success()) {
      int led = obj["led"];
      analogWrite(LED, led);
      Serial.println(String("Valor do LED: ") + led);
    }
  }
}
