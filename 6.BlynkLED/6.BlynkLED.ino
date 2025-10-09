#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "SESUAIKAN"
#define BLYNK_TEMPLATE_NAME "SESUAIKAN"
#define BLYNK_AUTH_TOKEN "SESUAIKAN"
#define ledBiru D13 //pin LED Biru
#define ledMerah D12 //pin LED Merah

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SESUAIKAN";
char pass[] = "SESUAIKAN";

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(ledBiru, OUTPUT);
  pinMode(ledMerah, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  Serial.print("V0 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledBiru, pinValue);
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  Serial.print("V1 Switch value is: ");
  Serial.println(pinValue);

  digitalWrite(ledMerah, pinValue);
}