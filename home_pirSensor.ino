#define sensor_pin 8
#define out1 3
#define out2 4
#define doNothing 10
bool firstTime ;
int sensor_value ;
unsigned long preMillis=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor_pin,INPUT);
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(2,OUTPUT);
  firstTime = true;
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor_value = digitalRead(sensor_pin);
  //Serial.println(sensor_value);
  if(firstTime){
    waitLoop();
    sensor_value = digitalRead(sensor_pin);
    delay(100);
    firstTime=false;
    }
    
  if(sensor_value==1 && firstTime!=true){
    turnOn();
    while(sensor_value!=0){
      waitLoop();
      sensor_value = digitalRead(sensor_pin);
      }   
    }
  
}

void turnOn(){
   digitalWrite(out1,HIGH);
   digitalWrite(out2,HIGH);
   delay(1350);
   digitalWrite(out1,LOW);
   digitalWrite(out2,LOW);
 }

void waitLoop(){
  unsigned long currentMillis = millis()/1000;
     while ((currentMillis - preMillis) <= doNothing) {
      //Serial.println("wait");
      analogWrite(2,128);
      currentMillis = millis()/1000;
      }
    preMillis = currentMillis ;
    analogWrite(2,0);
  }
