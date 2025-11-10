//Kode program untuk Wemos D1 R1

#define SW1 D2 
#define SW2 D3 

void setup() {
  Serial.begin(9600);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(SW1) == LOW){
    Serial.println("Kondisi SW1 : ON   ");
  }
    
  if(digitalRead(SW2) == LOW){
    Serial.println("Kondisi SW2 : ON  ");
  }

  if(digitalRead(SW1) == LOW && digitalRead(SW2) == LOW){
    Serial.println("Kondisi SW1 : ON  ");
    Serial.println("Kondisi SW2 : ON  ");
  }
}
