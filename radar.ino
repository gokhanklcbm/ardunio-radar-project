  #include <Servo.h>. 

// Ultrasonik Sinyal pinleri
const int trigPin = 10;
const int echoPin = 11;
const byte led1 = 44;
const byte led2 = 42;
const byte led3 = 40;
const byte led4 = 38;
const byte buzzer = 26;
const byte buton = 22; //buzer buton siyah
const byte buton2 = 24; // açma kapama buton2 kırmızı
// tam tersi led sistemi , button 2 atama kapatma açma buzzer performans
long duration;
int distance;
int control;

Servo myServo; 

void setup() {
  pinMode(buton , INPUT);
  pinMode(buton2, INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
  pinMode(led4 , OUTPUT);
  pinMode(buzzer , OUTPUT);
  Serial.begin(9600);
  myServo.attach(12); // Servo motor sinyal pini
  myServo.write(90);
  control = 0;

      
    
}
void loop() {

  while(control == 0){
 
    if(digitalRead(buton2) == HIGH){
       control = 1;
       delay(150);
    }
    delay(20);
  }

  if(control == 1){
  for(int i=0;i<=180;i++){  
  myServo.write(i); 
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  if(distance>0 && distance <=40){
  digitalWrite(buzzer , 1);}
 if (distance>0 && distance <=10)
    {
      
      
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 0);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
    
    }
    else if (distance >10 && distance <=20)
    {
      
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      
    }
    else if (distance >20 && distance <=30)
    {
     
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 0);
    
    }
    else if (distance >40)
    {
      
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
    }
    if (digitalRead(buton) == 1)
    {
       digitalWrite(buzzer , 0);
      
      }
    if(digitalRead(buton2) == HIGH){
      control = 0;
      delay(100);
      break;
    }
  }
  }
  if(control == 1){
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  if(distance>0 && distance <=40){
  digitalWrite(buzzer , 1);}
 if (distance>0 && distance <=10)
    {
      
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 0);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
    
    }
    else if (distance >10 && distance <=20)
    {
      
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      
    }
    else if (distance >20 && distance <=30)
    {
      
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 0);
    
    }
    else if (distance >30)
    {
      
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
    }
      if (digitalRead(buton) == 1)
    {
       digitalWrite(buzzer , 0);
      
      }
      if(digitalRead(buton2) == HIGH){
        control = 0;
        delay(100);
        break;
      }
  }
  }
  
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
