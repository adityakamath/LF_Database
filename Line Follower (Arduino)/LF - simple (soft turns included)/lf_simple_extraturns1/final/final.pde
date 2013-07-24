
int m1=2;
int m11=3;
int m2=4;
int m22=5;
int s1,s2,s3,s4,s5,s6;

void setup()
{
  pinMode(m1,OUTPUT);
  pinMode(m11,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m22,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int s3b=600,s3w=200,s4b=500,s4w=100,s5b=50,s5w=40,s6b=1000,s6w=0;
  s1=analogRead(A0);
  s2=analogRead(A1);
  s3=analogRead(A2);
  s4=analogRead(A3);
  s5=analogRead(A4);
  s6=analogRead(A5);
  
    if(s3<s3w&&s4<s4w&&s5>s5b)
  {
    Serial.println("straight");
    digitalWrite(m1,HIGH);
    digitalWrite(m11,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m22,LOW);
  }
  else
  if(s3>s3b&&s4<s4w&&s5<s5w)
  {
    Serial.println("soft left");
    digitalWrite(m1,LOW);
    digitalWrite(m11,HIGH);
    digitalWrite(m2,HIGH);
    digitalWrite(m22,LOW);
  }
  else
  if(s3<s3w&&s4>s4b&&s5<s5w)
  {
    Serial.println("soft right");
    digitalWrite(m1,HIGH);
    digitalWrite(m11,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m22,HIGH);
  }

  else
 if(s3>s3b&&s4>s4b&&s5>s5b)
  {
    Serial.println("straight");
    digitalWrite(m1,HIGH);
    digitalWrite(m11,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m22,LOW);
  }
}
