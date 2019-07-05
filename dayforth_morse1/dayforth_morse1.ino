class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};

Morse::Morse(int pin)
{
  pinMode(pin,OUTPUT);
  _pin=pin;
  _dottime=250;
}

void Morse::dot()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::dash()
{
  digitalWrite(_pin,HIGH);
  delay(_dottime*4);
  digitalWrite(_pin,LOW);
  delay(_dottime);
}

void Morse::c_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*3);
}

void Morse::w_space()
{
  digitalWrite(_pin,LOW);
  delay(_dottime*7);
}

Morse morse(13);

char MORSE[][4] = {
  {'.', '-', '*', '*'}, //A
  {'-', '.', '.', '.'}, //B
  {'-', '.', '-', '.'}, //C
  {'-', '.', '.', '*'}, //D
  {'.', '*', '*', '*'}, //E
  {'.', '.', '-', '.'}, //F
  {'-', '-', '.', '*'}, //G
  {'.', '.', '.', '.'}, //H
  {'.', '.', '*', '*'}, //I
  {'.', '-', '-', '-'}, //J
  {'-', '.', '-', '*'}, //K
  {'.', '-', '.', '.'}, //L
  {'-', '-', '*', '*'}, //M
  {'-', '.', '*', '*'}, //N
  {'-', '-', '-', '*'}, //O
  {'.', '-', '-', '.'}, //P
  {'-', '-', '.', '-'}, //Q
  {'.', '-', '.', '*'}, //R
  {'.', '.', '.', '*'}, //S
  {'-', '*', '*', '*'}, //T
  {'.', '.', '-', '*'}, //U
  {'.', '.', '.', '-'}, //V
  {'.', '-', '-', '*'}, //W
  {'-', '.', '.', '-'}, //X
  {'-', '.', '-', '-'}, //Y
  {'-', '-', '.', '.'}  //Z
};

void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int income;
  String str = "";  
  String morse_s = "";  
  int i, t , temp = 0;
  int n = 0;  
  while (Serial.available() > 0)
  {
    temp = 1;  
    str += char(Serial.read());  
    delay(2);  
    n++;
  }

  if (temp)
  {
    for (i = 0; i < n; i++)
    {
      for (t = 0; t < 4; t++)
      {
        if (str[i] >= 97 && str[i] <= 122)
        {
          morse_s += char(MORSE[int(str[i] - 97)][t]);
        }
      }
      morse_s += ' ';
    }
    Serial.println(morse_s);  
   for (i = 0; morse_s[i]!='\0' ; i++)
    {
      if (morse_s[i] == '.')
      {
        digitalWrite(13,HIGH);
        delay(250);
        digitalWrite(13,LOW);
        delay(250);
      }
      else if (morse_s[i] == '-'){
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
      }
      else if (morse_s[i] == ' ')
      {
        
        digitalWrite(13,LOW);
        delay(1750);
      }
      if (morse_s[i] != ' ' && str[i] != '*')
        {
        
        digitalWrite(13,LOW);
        delay(750);
      }
    }
    
    delay(2);
  }
}
