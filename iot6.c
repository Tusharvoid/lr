int tsensor;


void setup()
{



pinMode(A3, INPUT);
pinMode(12,OUTPUT); 
pinMode(13,OUTPUT);

}


void loop()
 {

tsensor=analogRead(A3);

if(tsensor>=200)


{

digitalWrite(13, HIGH); 
tone(12,500,50);

}

digitalWrite(13, LOW);

