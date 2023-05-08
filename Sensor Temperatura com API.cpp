#include "WiFi.h"
#include <DHTesp.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* server = "api.thingspeak.com";
String apiKey ="J3E50TEQQPNHKTTW";

#define LEDPIN1 12
#define LEDPIN2 14
#define DHT_PIN 15 // Definindo pino de dados do sensor

DHTesp dhtSensor; // Definindo o objeto do sensor

void setup() {
  Serial.begin(115200);

  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  Serial.println("Pinos configurados para o ESP32!");

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

  delay(5000); // this speeds up the simulation
}
