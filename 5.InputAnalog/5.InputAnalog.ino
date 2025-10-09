#define pot A0   //mendefinisikan pin analog

void setup() {
  Serial.begin(9600);   //mengatur baud rate
}

void loop() {
  int a = analogRead(pot);   //membaca data analog dan menyimpannya pada variabel a
  Serial.print("Nilai Analog : ");
  Serial.println(a);   //menuliskan nilai variabel a pada serial monitor
  delay(100);
}