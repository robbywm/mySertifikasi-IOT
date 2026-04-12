int btnPin = D3;

void setup() {
  Serial.begin(9600);
  Serial.println("Pengujian User Button Dimulai...");
  pinMode(btnPin, INPUT_PULLUP);
}

void loop() {
  int statusBtn = digitalRead(btnPin);

  Serial.print("Status User Button (D3): ");
  Serial.println(statusBtn); // Akan bernilai 0 jika ditekan, 1 jika dilepas

  delay(500);
}
