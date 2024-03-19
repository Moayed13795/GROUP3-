int pinA = 13;
int pinB = 12;
int pinC = 11;
int pinD = 10;
int pinE = 9;
int pinF = 8;
int pinG = 7;
int i = 0;
int j = 0;
int Arduino_Pins[7] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG};
int Segment_Pins[10][7] = {{1, 1, 1, 1, 1, 1, 0}, 
{0, 1, 1, 0, 0, 0, 0}, 
{1, 1, 0, 1, 1, 0, 1}, 
 {1, 1, 1, 1, 0, 0, 1}, 
{0, 1, 1, 0, 0, 1, 1},
{1, 0, 1, 1, 0, 1, 1}, 
{1, 0, 1, 1, 1, 1, 1}, 
{1, 1, 1, 0, 0, 0, 0},
 {1, 1, 1, 1, 1, 1, 1}, 
{1, 1, 1, 1, 0, 1, 1}, 
};

void setup() {

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
 
   for (j = 0; j<7; j++)
  {
    digitalWrite(Arduino_Pins[j], Segment_Pins[i][j]);
  }

  if(digitalRead(2)==0)
  {
    while(digitalRead(2)==0)
    {
      
    }
    i++;
  }
  if(i == 10)
  {
    i = 0;
  }
  delay(100);
}
