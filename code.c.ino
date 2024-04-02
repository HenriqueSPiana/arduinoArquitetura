#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8); 


int ledPin =6;
int sensorPin=9;
int leitura = 0;


void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(19200);
  mySerial.begin(19200);
  delay(1000);
  Serial.println("Initializing...");
  delay(1000);

}
void loop()
{

 leitura = digitalRead(sensorPin);
  if (leitura ==HIGH){
    digitalWrite(ledPin,HIGH);
    delay(500);  
    mySerial.println("AT"); 
    updateSerial();
    mySerial.println("AT+CMGF=1"); 
    updateSerial();
    mySerial.println("AT+CMGS=\"+5527997219684\"");
    updateSerial();
    mySerial.print("Alerta");
    updateSerial();
    mySerial.write(26);
  } 
  else{
    digitalWrite(ledPin,LOW);
  }
}

void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available())
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}