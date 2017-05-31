#include "DHT.h"
#define DHTPIN A1 // pino que estamos conectando
#define DHTTYPE DHT11 // DHT11

// instanciar objeto do sensor
DHT dht (DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  // a leitura da temperatura e umidade pode levar 250ms
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t) || isnan(h)) {
    Serial.println("Erro ao ler DHT, estava esperando float");
  } else {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print(" C");
  }

  delay(1000);
}
