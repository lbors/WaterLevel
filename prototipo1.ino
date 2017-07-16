#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define trigger 6
#define echo 7
#define led 10
#define buzzer 9

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(trigger, echo);
char form;
int forma;
float a, b, distance, volume, maximo;

void start(){
  tone(buzzer, 1000,500);
  digitalWrite(led, HIGH);  
  Serial.print("Formato:\n1: Paralelepipedo\n2: Tronco de cone\n3: Cubo\n");
  delay(1000);
  digitalWrite(led, LOW);
  //form = Serial.read();
  form = '2'; //facilitando as coisas
  forma = form - '0';
  Serial.println(forma);

  Serial.print("Lendo a");
  delay(2000);
  //a = distancia();
  //a = 36.0; //adaptado ao do agostinho
  a = 16.0;
  //gira_motor();
  Serial.print("Lendo b");
  delay(2000);
  //b = distancia();
  //b = 24.5; //adaptado ao do agostinho;
  b = 0.0;
  delay(1000);
  //maximo = teste(); //para uso no trabalho
  maximo = 7238.02; //facilitando as coisas
}
void gira_motor(){
	
	//a ser feito
}
void alarme(){
  digitalWrite(led, 0);
  if(volume <= (maximo*0.15) || volume >= (maximo*0.85)){
    digitalWrite(led, 1);
    tone(buzzer, 1000, 200); 
  }
}
float paralele_cubo(float x, float y, int z){
  float vol = x*y*z; 
  return vol;
  }
float tronco(float x, int z){
  float vol = 3.1415*(x*x)*z; 
  return vol;
  }

  
int distancia(){
    int i = 0;
    distance = 0.0;
    while(i<5){
      distance = ultrasonic.Ranging(CM) + distance;
      delay(50);
      i++;
    }
    distance = distance/5.0;
  return distance;
  }
  
  
float teste(){
  float valor;
  if (forma == 3 || forma == 1)
    valor = paralele_cubo(a, b, distancia());
  else
    valor = tronco(a, distancia()); 


  return valor;
}
  
  
void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  start();
  
  
}
 
void loop(){
    
    Serial.print("\nVolume(L): ");
	  volume = maximo - teste();
    float show = volume/1000.0;
    Serial.print(show);
    alarme();
    delay(500);
    
 }
