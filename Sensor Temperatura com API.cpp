#include "WiFi.h"
#include <DHTesp.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* server = "api.thingspeak.com";
String apiKey ="EDI6NC60AQ01RUG6";

#define DHT_PIN 15 // Definindo pino de dados do sensor

DHTesp dhtSensor; // Definindo o objeto do sensor

void setup() {
  Serial.begin(9600);

  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  Serial.println("Objeto Iniciado!");

  WiFi.begin(ssid,password);
  Serial.println("Iniciando Conexão, aguarde!");

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!\n");
}

void loop() {

  TempAndHumidity  data = dhtSensor.getTempAndHumidity();

  float temperatura=0;
  temperatura = data.temperature;

  float umidade=0;
  umidade = data.humidity;

  Serial.println("\nTemperatura: " + String(temperatura) + "°C");
  Serial.println("Umidade: " + String(umidade) + "%");

  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha ao ler os dados do sensor!");
    return;
  } else {
    WiFiClient client;
    if (client.connect(server, 80)) {
      String postStr = "api_key=" + apiKey;
      postStr += "&field1=";
      postStr += String(temperatura);
      postStr += "&field2=";
      postStr += String(umidade);
      postStr += "\r\n\r\n";
      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);
      Serial.print("Temperature: ");
      Serial.print(temperatura);
      Serial.print(" degrees Celcius, Humidity: ");
      Serial.print(umidade);
      Serial.println("%. Send to ThingSpeak.");
      delay(500); // Delay para permitir que os dados sejam totalmente enviados antes de encerrar a conexão
      client.stop();
    } else {
      Serial.println("Falha ao conectar ao ThingSpeak");
    }
  }
}
