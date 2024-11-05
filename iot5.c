int pir_sensor=0;

void setup()

{

pinMode(2, INPUT); 
pinMode(13,OUTPUT); 
pinMode(12,OUTPUT);

}

void loop()

{

pir_sensor=digitalRead(2);

if(pir_sensor==HIGH)

{ digitalWrite(13,HIGH);
 tone(12,500,50);

} digitalWrite(13, LOW);

}