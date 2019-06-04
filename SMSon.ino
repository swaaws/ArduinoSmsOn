#define PINNUMBER "5837" //The Pin from SIM
#define nr 9 // output Pin
#define caractar '1' // sms content turns pin on

#include <GSM.h>
GSM gsmAccess;
GSM_SMS sms;

char senderNumber[20];  

void setup() 
{
  pinMode(nr, OUTPUT);
  pinMode(nr, LOW);
  boolean notConnected = true;
  while(notConnected)
  {
    if(gsmAccess.begin(PINNUMBER)==GSM_READY)
      notConnected = false;
    else
    {
      delay(1000);
    }
  }
}

void loop() 
{
  char c;
  pinMode(nr,LOW);
  
    if (sms.available())
    {
    sms.remoteNumber(senderNumber, 20);

   if(sms.peek()=='#')
       {

      sms.flush();
    }
  }
      while(c=sms.read()){

      if(c==caractar){
    pinMode(nr, HIGH);
    delay(240000);
    pinMode(nr, LOW);
  }   

    sms.flush();

  }
pinMode(nr,LOW);
  delay(1500);

}
