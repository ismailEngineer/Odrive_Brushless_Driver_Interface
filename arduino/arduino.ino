/*
ODrive App script 
Ismail HAMRONI - Thierry Roquette
*/

String message;
String info;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

int getBleMessage()
{
  if (Serial.available()>0 )
  {
    message  = Serial.readString();
    info = message[0];
    Serial.print("Reaceived message : "); Serial.println(message);
    Serial.print("Reaceived INFO : "); Serial.println(info);
  }
  return 0;  
}

int decryptMessageBle(String data)
{
 
  return 0;
}

int errorcode = 0;




void loop() 
{
  // put your main code here, to run repeatedly:
  errorcode = getBleMessage();
}
