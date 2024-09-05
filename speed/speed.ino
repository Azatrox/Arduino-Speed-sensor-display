/*  So this is code for a speed sensor using two light gates and a TM1638 display using the included library made by Ricardo Batista. This program outputs the speed of an object in km/h m/s cm/ms but only shows it on the 
display in km/h
⠀⠀⢀⡀⠀⠀⠀⠀⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠞⠋⠙⢳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠸⣷⡀⠀⣿⡄⢹⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡾⠁⠀⠀⠀⠀⢻⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣰⡇⠀⠹⣧⠀⣻⣧⠀⠉⠀⠀⠀⠀⠀⠀⢀⣀⣤⠤⠶⠒⠛⠓⠒⠒⠲⠦⢤⣌⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠘⣿⡀⠀⢻⣷⠛⠻⣇⠀⠘⠗⠀⣠⡴⠞⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠦⣤⡴⠞⠛⠋⠉⠛⢷⠀⠀⠀⠀
⠀⠘⣷⣴⠿⢿⣆⠀⠙⠃⠀⣠⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢶⣄⠀⠀⠀⢸⠇⠀⠀⠀
⠀⢠⣿⡇⠀⢨⣿⡆⠀⢀⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡀⢀⡿⠀⠀⠀⠀
⠀⠈⠀⠛⠀⠀⠀⠀⢠⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣾⠃⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣆⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠛⠲⢦⣄
⠀⠀⠀⠀⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⣿
⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⣾⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⡆⠀⠀⠀⠀⠀⢸⣇⣤⠞⠁
⠀⠀⠀⠀⠀⠀⠘⡇⠀⠀⠀⠀⠀⠹⢿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣿⡿⠃⠀⠀⠀⠀⠀⢸⠋⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣀⠀⠀⢀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠘⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠿⠿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠛⢷⡀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠓⠚⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠁⠀⢸⡇⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠞⠛⠲⠶⠶⠛⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠲⠤⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡤⢴⡞⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⠼⠯⣉⡉⠛⠒⠒⠒⠒⠒⠛⢋⠉⠉⠹⣆⡼⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⣄⠀⠀⠈⠁⠀⠀⠀⠀⠀⣰⠋⠀⢀⡀⢹⡏⢳⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠏⠳⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠁⠀⠀⣷⡿⢶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡤⣴⠒⠞⠙⡆⠀⠀⠀⠀⡼⠙⠶⠲⡤⢄⣸⠛⠲⠷⣟⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡀⠀⠀⠀⠀⣽⠀⠀⠀⠀⡇⠀⠀⠀⠀⢸⡟⠀⠀⠀⣨⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢤⣀⢀⣰⠃⠀⠀⠀⠀⢹⣄⠀⢀⣴⡿⠤⠴⠖⠚⠉⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠛⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
int enter = 6; // Is High when nothing is interupting the sensor starts the program by saving the time sice start of the program in the variable a
int leave= 13; // Is High when nothing is interupting the sensor starts calculations by saving the time sice start of the program in the variable b
int supply = 2; // Is always High to suplly power to the light gates
int data = 10; 
int clock = 9; 
int strobe = 8;
int a = 0; // variable in which i save the current time since start of the program
int b = 0; // variable in which i save the current time since start of the program
float S = 0; //speed in cm/ms
float d = 5; //distance in cm
float t = 0; //time elapsed between a and b in milliseconds
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
  c = true;
  a = millis();
}

void Snapshot2()
{
  b = millis();
}

void matht()// calculates the time passed between entry and exit calls maths
{
  t = b - a;
  maths();
}
void maths()//Calculates the speed of the object and outputs all relevant variables calls visual output
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
void visualoutput()//does what it says on the tin
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
  digitalWrite(supply, HIGH);//need power
  while(e == false)//control varible so that the program does not repeat itself was to lazy to write a reset function
  {

    if (digitalRead(enter) == HIGH && c == false) //just spams ready until something interupts the entrance
    {
      Serial.println("READY");
    }
    if (digitalRead(enter) == LOW && c == false)//if the first gate is interrupted it saves the current time since start of the programm in a variable and sets c to true so there is no time travel
    {
      Snapshot1();
    }
    if (digitalRead(leave) == LOW && c == true)//does the same thing apart from the time travel bit and then calls matht
    {
     Snapshot2();
      matht();
      break; 
    }
  }  
}
