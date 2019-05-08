#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID "Campus Boulevard"
#define WIFI_PASSWORD ""




void setup() {
  
  
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("conectando");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("conectado: ");
  Serial.println(WiFi.localIP());

}
int x = 0;
void loop() {
  sendData("count=" + (++x));
  delay(3000);
}


void sendData(String data){
  StaticJsonBuffer<200> doc;
  HTTPClient http;
  String link = "http://10.35.215.140:8080/get.php?" + data;
  Serial.print("Enviando link: ");
  Serial.println(link);
  http.begin(link);
  int code = http.GET();
  String retorno = http.getString();
  Serial.println(retorno);
  JsonObject& root = doc.parseObject(retorno);
  int saida = root["registrar"];
  Serial.println(saida);
  Serial.println(code);
  http.end();
}
