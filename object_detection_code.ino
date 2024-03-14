const int trig = 12;
const int echo = 13;

const int VIBRATINGMOTOR1 = 8;
const int VIBRATINGMOTOR2 = 7;
const int VIBRATINGMOTOR3 = 6;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
  pinMode(VIBRATINGMOTOR1 , OUTPUT);
  pinMode(VIBRATINGMOTOR2 , OUTPUT);
  pinMode(VIBRATINGMOTOR3 , OUTPUT);

  
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  

  if ( distance <= 100 )
  {
    digitalWrite(VIBRATINGMOTOR1, HIGH);
    digitalWrite(VIBRATINGMOTOR2, HIGH);
    digitalWrite(VIBRATINGMOTOR3, HIGH);
  }
  else
  {
    digitalWrite(VIBRATINGMOTOR1, LOW);
  }
  if ( distance <= 150 )
  {
    digitalWrite(VIBRATINGMOTOR2, HIGH);
  }
  else
  {
    digitalWrite(VIBRATINGMOTOR2, LOW);
  }
  if ( distance <= 200 )
  {
    digitalWrite(VIBRATINGMOTOR3, HIGH);
  }
  else
  {
    digitalWrite(VIBRATINGMOTOR3, LOW);
  }
}
 