#define led_verde 2
#define led_amarillo 4
#define led_rojo 7
#define led_p 6
#define boton_pasarPeaton 3
#define potenciometro 1


int tiempo = 0;
boolean valor_pasarPeaton = LOW;
boolean valor_led_p = LOW;
boolean verde;
int valorPot;

void setup() {
  valorPot = 0;
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_p, OUTPUT);
  pinMode(boton_pasarPeaton, INPUT);
  Serial.begin(9600);
}

void loop() {
  Verde();
  Amarillo();
  Rojo();
}
void Verde(){
    verde = true;
    valorPot = analogRead(potenciometro)*5;
    Serial.println(valorPot);
    tiempo = 0;
   // digitalWrite(led_verde,HIGH); 
    //delay(valorPot);
    while(digitalRead(boton_pasarPeaton) != LOW && tiempo<=valorPot){
      Serial.println("entro");
          digitalWrite(led_verde,HIGH); 
          delay(10);  
          tiempo +=10;
    } 
    digitalWrite(led_verde,LOW);  
    delay(200);
    digitalWrite(led_verde,HIGH); 
    delay(500);
    digitalWrite(led_verde,LOW);  
    delay(200);
    digitalWrite(led_verde,HIGH); 
    delay(500);          
    digitalWrite(led_verde,LOW);  
    delay(200); 
    verde = false;
}

void Amarillo(){
  digitalWrite(led_amarillo,HIGH); 
    delay(500);                 
    digitalWrite(led_amarillo,LOW);  
    delay(200);  
}
void Rojo(){
   digitalWrite(led_rojo,HIGH); 
    digitalWrite(led_p,HIGH); 
    delay(2000);             
    digitalWrite(led_rojo,LOW); 
    digitalWrite(led_p,LOW); 
    delay(500);
}
               
