int btnPin = D3;
int ledPin = D4;

void setup() {
  Serial.begin(9600);
  Serial.println("Pengujian Interaksi Tombol dan LED Dimulai...");
  
  pinMode(btnPin, INPUT_PULLUP); 
  pinMode(ledPin, OUTPUT);   
}

void loop() {
  int statusBtn = digitalRead(btnPin);

  if (statusBtn == LOW) {
    digitalWrite(ledPin, LOW); 
    Serial.println("Tombol Ditekan -> LED Menyala");
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Tombol Dilepas -> LED Padam");
  }
   // Sedikit jeda (debounce) agar pembacaan stabil
  delay(100);
}