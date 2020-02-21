//P0 Led Red
//P1 Led green
//P2 
//P3 Switch
//P4
//P5 - Piezo sensor

int pinGr = 0; 
int pinRe = 1; 

int waitmin = 2000;
int waitmax = 4000;
int targettimemin = 500;
int targettimemax = 1500;
int treshold = 300; //Piezo dedetion treshold

void setup()
{
  pinMode(pinGr, OUTPUT);
  pinMode(pinRe, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  //Enable debug serial
  Serial.begin(9600);
}
int enabled = 0;
int czas;

void loop()
{
  blinkgr(); //Blink both light to sygnalize turning on
  //Check mode select swich
  if (digitalRead(3) == 0) statyka(); 
  dynamika();
}

//Dynamic shooting mode
int dynamika()
{ 
  while(true){
    if(enabled == 1) 
    {
      if(piezo() == 1) {
        blinkg();
        enabled=0;  
      } else {
        delay(10);
        czas = czas - 10;
      }
    } else {
      czas=random(targettimemin,targettimemax);
      delay(random(waitmin,waitmax));
      enabled=1;
      digitalWrite(pinGr, HIGH);
    }

    if(czas<0){
      digitalWrite(pinGr, LOW);
      blinkr();
      enabled=0;
    }
  }
}

//Hit detection mode
int statyka()
{ 
  digitalWrite(pinGr, LOW);
  digitalWrite(pinRe, LOW);
  while(true){ 
    if(piezo()==1) blinkgr();
    delay(10);    
  }
}

//Check sensor
int piezo()
{
  int read_value = analogRead(2);
  if(read_value > treshold) { 
    Serial.println(read_value);
    return 1;
  }
  return 0;
}  
  
//Blink green led
int blinkg()
{
  for(int i=0;i<5;i++){
    digitalWrite(pinGr, HIGH);
    delay(200); 
    digitalWrite(pinGr, LOW);
    delay(200); 
  }
}  

//Blink red led
int blinkr()
{
  for(int i=0;i<5;i++){
    digitalWrite(pinRe, HIGH);
    delay(200); 
    digitalWrite(pinRe, LOW);
    delay(200); 
  }
}

//blink both leds
int blinkgr()
{
  for(int i=0;i<5;i++){
    digitalWrite(pinGr, HIGH);
    digitalWrite(pinRe, LOW);
    delay(200); 
    digitalWrite(pinGr, LOW);
    digitalWrite(pinRe, HIGH);  
    delay(200); 
  }
  digitalWrite(pinGr, LOW);
  digitalWrite(pinRe, LOW);
}
