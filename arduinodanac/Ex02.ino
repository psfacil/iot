/* Herbert Santos       RM75742
 * Jheymerson Barbosa   RM77286
 * Marcelo Fernando     RM76919
 * Raphael Mota Freschi RM75719
 * Vitor Cunha de Deus  RM76746
*/



#include <ArduinoJson.h>
const int GREEN = 5;
const int RED = 3;
const int BLUE = 9;
const int LUZ = A2;
const int TAMANHO = 200;
void setup() {
Serial.begin(9600);
Serial.setTimeout(10); //1000ms é muito tempo
//pinMode(LED,OUTPUT);
}
void loop() {
if (Serial.available() > 0) {
//Lê o texto disponível na porta serial:

char texto[TAMANHO];
Serial.readBytesUntil('\n', texto, TAMANHO);
//Grava o texto recebido como JSON
StaticJsonBuffer<TAMANHO> jsonBuffer;
JsonObject& json = jsonBuffer.parseObject(texto);

if(json.success()) {
  if(json.containsKey("GREEN")){
    analogWrite(GREEN, json["GREEN"]);
    
  }
   if(json.containsKey("BLUE")){
    analogWrite(BLUE, json["BLUE"]);
    
    }
    if(json.containsKey("RED")){
    analogWrite(RED, json["RED"]);
    
    }
    delay(1000);
}

}
StaticJsonBuffer<TAMANHO> jsonBuffer;
JsonObject& json = jsonBuffer.createObject();
json["luz"] = analogRead(LUZ);
json.printTo(Serial); Serial.println();
delay(2000);
}
