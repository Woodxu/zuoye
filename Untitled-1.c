int pinInterrupt=2;
int tick=0;
int state=0;
void myfunc()
{
  tick=-1;
  Serial.print(tick);
}
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8,OUTPUT);
  
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  attachInterrupt(pinInterrupt,myfunc,CHANGE);
}
byte income=0;
void loop()
{
  Serial.println(tick++);
  if(tick==10)
    tick=0;
  income=tick-'0';
  digitalWrite(8, LOW);
  digitalWrite(2, income&0x1);
  digitalWrite(3, (income>>1)&0x1);
  digitalWrite(4, (income>>2)&0x1);
  digitalWrite(5, (income>>3)&0x1);
  digitalWrite(8, HIGH);
  state=~state;
  digitalWrite(13, state);
  delay(1000); // Wait for 1000 millisecond(s)
}