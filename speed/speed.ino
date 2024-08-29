// so this is code for a speed sensor using two light gates and a disply using the included library








int enter = 6;
int leave= 13;
int supply = 2;
int data = 10;
int clock = 9;
int strobe = 8;
int a = 0;
int b = 0;
float S = 0; //speed in cm/ms
float d = 5; //distance in cm
float t = 0; //time elapsed in milliseconds
float kmh = 0;//speed in km/h
float ms = 0;//speed in m/s
bool c = false;
bool e = false;
char string[] = "display text";
int base = 0;
char displayStr[9];
void setup()
{
  pinMode(enter, INPUT);
  pinMode(leave, INPUT);
  pinMode(supply, OUTPUT);
  Serial.begin(600); 
}
TM1638 modul(data, clock, strobe);
TM1638 module = TM1638(data, clock, strobe);
void Snapshot1()
{
  c = false;
  a = millis();
}

void Snapshot2()
{
  b = millis();
}

void matht()
{
  t = b - a;
  maths();
}
void maths()
{
  if (t == 0)
  {
    Serial.print("You tried to divide by zero HAHA");
    e = true;
    return;

  }
  S = d / t;
  e = true;
  kmh = S * 36;
  ms = S * 10;
  e = true;
  Serial.print("S =");
  Serial.println(S);
  Serial.print("kmh =");
  Serial.println(kmh);
  Serial.print("ms =");
  Serial.println(ms);
  Serial.print("t =");
  Serial.println(t);
  Serial.print("a =");
  Serial.println(a);
  Serial.print("b =");
  Serial.println(b);
  visualoutput();
}
void visualoutput()
{
        
    dtostrf(kmh, 8, 2, displayStr); 

    
    module.setDisplayToString(displayStr);

    base++;
    if (base == sizeof(displayStr) - 8) {
        base = -8;

    }
}

void loop()
{
  digitalWrite(supply, HIGH);
  while(e == false)
  {

    if (digitalRead(enter) == HIGH && c == false)
    {
      Serial.println("READY");
    }
    if (digitalRead(enter) == LOW && c == false)
    {
      Snapshot1();
    }
    if (digitalRead(leave) == LOW)
    {
     Snapshot2();
      matht();
      break; 
    }
  }  
}
