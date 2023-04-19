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

String getBleMessage()
{
  if (Serial.available()>0 )
  {
    message  = Serial.readString();
    info = message[0];
    Serial.print("Reaceived message : "); Serial.println(message);
    Serial.print("Reaceived INFO : "); Serial.println(info);
    return message;  
  }
  else return ("");
  
}

String decryptMessageBle(String data, int n, float* cu, float* vel)
{
  String info="";
  String mode="";
  int flag_mode = 0;
  int edge = 0;
  float velocity;
  float current;
  int j = 0;
  
  for (int i=0;i<n;i++)
  { 
    if (data[i] != '|') 
    { 
      info.concat("e");info[j]= data[i];
      
      if (flag_mode == 0) 
      {
        mode.concat("e"); mode[j] = info[j];
      }
      
      Serial.print("CHAR : "); Serial.println(info[j]);
      j = j + 1;
    }
    else 
    {  //Serial.print("INFO : "); Serial.println(info);
       //Serial.print("EDGE : "); Serial.println(edge);
       //Serial.print("LENGTH : "); Serial.println(strlen(mode.c_str()));
      if (edge == 0)
      {
        //Serial.print("MODE DETECTED : "); Serial.println(mode);
        info = "";
        flag_mode = 1;
        j = 0;
      }
      else if (edge == 1)
      {
        //Serial.print("SETTING --> CURRENT : "); Serial.println(info);
        current = info.toFloat();
        info = "";
        j = 0;
      }
      else if (edge == 2)
      {
        //Serial.print("SETTING --> VELOCITY : "); Serial.println(info);
        velocity = info.toFloat();
        info = "";
        j = 0;
      }
      edge = edge + 1;
    }
  }
  //Serial.print("MODE DETECTED : "); Serial.println(mode);
  //Serial.print("SETTING --> CURRENT : "); Serial.println(current);
  //Serial.print("SETTING --> VELOCITY : "); Serial.println(velocity);
  *cu = current;
  *vel = velocity;
  return mode;
}

String empty_string(String data, int n)
{
  for( int k = 0;k<n;k++) data[k]='\0';
  return data;
}

String errorcode;
String mode;
int n=0;
float cu, vel;
void loop() 
{
  // put your main code here, to run repeatedly:
  errorcode = getBleMessage();
  for ( n = 0; errorcode[n]; n++);
  //Serial.print("DATA : "); Serial.println(errorcode);
  //errorcode = empty_string(errorcode,n);
  //errorcode = "";
  //Serial.print("DATA : "); Serial.println(errorcode);
  mode = decryptMessageBle(errorcode,n,&cu,&vel);
  if (strlen(mode.c_str()) > 1)
  {
  Serial.print("MODE DETECTED : "); Serial.println(mode);
  Serial.print("SETTING --> CURRENT : "); Serial.println(cu);
  Serial.print("SETTING --> VELOCITY : "); Serial.println(vel);
  }
  
  errorcode = "";
}
