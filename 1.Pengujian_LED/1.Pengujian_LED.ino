int ledPin = D4;
void setup() {
  Serial.begin(9600);
  Serial.println("Pengujian LED D4 Kasgar IoTShield Dimulai...");
  pinMode(ledPin, OUTPUT);
}
void loop() {
  digitalWrite(ledPin, LOW); 
  Serial.println("LED Menyala");
  delay(1000);
  digitalWrite(ledPin, HIGH);
  Serial.println("LED Padam");
  delay(1000);
}
