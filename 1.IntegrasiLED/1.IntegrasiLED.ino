//Koding untuk Wemos D1 R1

#define ledMerah D12  //definisi pin D12 
#define ledBiru D13   //definisi pinD13

void setup(){
  pinMode(ledMerah, OUTPUT);  //mengubah mode pin menjadi output
  pinMode(ledBiru, OUTPUT);   //mengubah mode pin menjadi output
}

void loop(){
  digitalWrite(ledMerah, HIGH); //menyalakan LED
  delay(1000);
  digitalWrite(ledBiru, HIGH);  //menyalakan LED
  delay(1000);
  digitalWrite(ledMerah, LOW);  //mematikan LED
  delay(1000);
  digitalWrite(ledBiru, LOW);   //mematikan LED
  delay(1000);
}