


void setup() {
  // put your setup code here, to run once:

for (int a = 8; a < 12 ; a++) {
pinMode(a,OUTPUT);

}
}

void loop() {
  // put your main code here, to run repeatedly:

for (int x = 0; x <= 3 ; x++) {

digitalWrite(9,HIGH);
digitalWrite(11,HIGH);
delay(300);
digitalWrite(8,HIGH);
digitalWrite(10,HIGH);
delay(500);
digitalWrite(9,LOW);
digitalWrite(11,LOW);
delay(300);
digitalWrite(8,LOW);
digitalWrite(10,LOW);
delay(500);

}

for (int y = 0; y <= 3 ; y++) {

digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);
digitalWrite(11,HIGH);
delay(500);
digitalWrite(11,LOW);
delay(200);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
delay(200);
digitalWrite(10,HIGH);
digitalWrite(9,LOW);
delay(200);
digitalWrite(9,HIGH);
digitalWrite(8,LOW);
delay(200);
digitalWrite(8,HIGH);
digitalWrite(9,LOW);
delay(200);
digitalWrite(9,HIGH);
digitalWrite(10,LOW);
delay(200);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
delay(200);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
digitalWrite(10,LOW);
digitalWrite(11,LOW);

}
delay(1000);

}
