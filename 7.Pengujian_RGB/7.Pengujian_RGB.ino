// Definisi Pin sesuai routing KasgarIoT R1
int pinMerah = D7;
int pinBiru  = D6;
int pinHijau = D8;

void setup() {
  Serial.begin(9600);
  Serial.println("Pengujian RGB LED Dimulai...");
  pinMode(pinMerah, OUTPUT);
  pinMode(pinBiru, OUTPUT);
  pinMode(pinHijau, OUTPUT);
}

void loop() {
  // 1. Nyalakan warna Merah saja
  digitalWrite(pinMerah, HIGH);
  digitalWrite(pinBiru, LOW);
  digitalWrite(pinHijau, LOW);
  Serial.println("Warna RGB: MERAH");
  delay(1000);

  // 2. Nyalakan warna Hijau saja 
  digitalWrite(pinMerah, LOW);
  digitalWrite(pinBiru, LOW);
  digitalWrite(pinHijau, HIGH);
  Serial.println("Warna RGB: HIJAU");
  delay(1000);

  // 3. Nyalakan warna Biru saja 
  digitalWrite(pinMerah, LOW);
  digitalWrite(pinBiru, HIGH);
  digitalWrite(pinHijau, LOW);
  Serial.println("Warna RGB: BIRU");
  delay(1000);
}
