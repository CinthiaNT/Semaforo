// Se definen los diferentes componentes utilizados en el pin correspondiente
#define led_verde 7
#define led_amarillo 6
#define led_rojo 5
#define led_pR 3
#define led_pV 4
#define buzzer 9
#define boton_pasarPeaton 2
#define potenciometro 1


int tiempo = 0;  //Inicializamos tiempo en 0. Esta variable nos ayudara a controlar el cambio
                 // cuando se presiona el boton de peaton
int valorPot = 0;   //Variable para controlar el tiempo que durara el semaforo en verde

void setup() {
  //Definimos los leds y el buzzer como pin de salida
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_pV, OUTPUT);
  pinMode(led_pR,OUTPUT);
  pinMode(buzzer,OUTPUT);
  //Definimos boton que controla el semaforo de peaton como pin de entrada
  pinMode(boton_pasarPeaton, INPUT);
  Serial.begin(9600);
}

void loop() {
  Verde();
  Amarillo();
  Rojo();
}
void Verde(){
    // El tiempo que marca el potenciometro lo multiplicamos 5 veces para aumentar el tiempo
    valorPot = analogRead(potenciometro)*5;
    // Se imprime en consola este valor
    Serial.println(valorPot);
    tiempo = 0;
    //Ciclo que ayuda a realizar el cambio cuando se presiona el boton
    while(digitalRead(boton_pasarPeaton) !=+ LOW && tiempo<=valorPot){
      Serial.println("entro");
          digitalWrite(led_verde,HIGH); 
          digitalWrite(led_pR,HIGH);
          delay(10);  
          tiempo +=10;
    } 
    // Se realiza un parpadeo para avisar que el semaforo cambiara de estado
    // El verde para semaforo de autos y el rojo para semaforo peatonal
    digitalWrite(led_verde,LOW);  
    digitalWrite(led_pR,LOW);
    delay(200);
    
    digitalWrite(led_verde,HIGH); 
    digitalWrite(led_pR,HIGH);
    delay(500);
    digitalWrite(led_verde,LOW);  
    digitalWrite(led_pR,LOW);
    delay(200);
    
    digitalWrite(led_verde,HIGH); 
    digitalWrite(led_pR,HIGH);
    delay(500);          
    digitalWrite(led_verde,LOW);
    digitalWrite(led_pR,LOW);  
    delay(200); 
}

void Amarillo(){
  // Se declara un tiempo para el led naranja que avisa que el estado de semaforo cambiara a rojo
    digitalWrite(led_amarillo,HIGH); 
    delay(500);                 
    digitalWrite(led_amarillo,LOW);  
    delay(200);  
}
void Rojo(){
    // Se declara el tiempo que el semaforo de autos durara en rojo y el de peatones en verde
    digitalWrite(led_rojo,HIGH); 
    digitalWrite(led_pV,HIGH); }
    //Se hace una llamada al metodo que genera sonido cuando el peaton puede avanzar
    sonido();  
    delay(2000);           
    digitalWrite(led_rojo,LOW); 
    digitalWrite(led_pV,LOW); 
    delay(500);
}

void sonido(){
  //Este metodo es el que controla el tiempo que el sonido se escuchara
     analogWrite(buzzer,128); //emite sonido
     delay(2000); //espera medio segundo
     digitalWrite(buzzer, LOW); //deja de emitir
     delay(500);//espera medio segundo
}
               
