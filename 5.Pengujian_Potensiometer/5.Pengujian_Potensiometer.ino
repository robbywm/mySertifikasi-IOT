int potPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Pengujian Potensiometer Dimulai...");
}

void loop() {
  int nilaiPot = analogRead(potPin);
  
  Serial.print("Nilai Potensiometer: ");
  Serial.println(nilaiPot);
  
  delay(500);
}
