#define Pecho A1
#define Ptrig A0
#define EntS0 A2
#define EntS1 A3
#define EntS2 A4
long duracion, distancia;
int PinSalidaA = 2;     
int PinSalidaB = 3;
int PinSalidaC = 4;
int A=5;
int B=6;
int C=7;
int D=8;
int E=9;
int F=10;
int G=11;

int output[3] = {0, 0, 0};

void setup(){
  Serial.begin (9600);
  pinMode(Pecho , INPUT);
  pinMode(Ptrig , OUTPUT);
  pinMode(PinSalidaA, OUTPUT);
  pinMode(PinSalidaB, OUTPUT);
  pinMode(PinSalidaC, OUTPUT);
  
  pinMode(EntS0, INPUT);
  pinMode(EntS1, INPUT);
  pinMode(EntS2, INPUT);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}
void loop(){
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2)/29;
  
  if (distancia >= 0 && distancia <=5){
    setBinaryOutput(0b000);
  }
  if (distancia > 5 && distancia <=10){
    setBinaryOutput(0b001);
  }
  if (distancia > 10 && distancia <= 15){
    setBinaryOutput(0b011);
  }
  if (distancia > 15 && distancia <=20){
    setBinaryOutput(0b010);
  }
  if (distancia > 20 && distancia <=25){
    setBinaryOutput(0b110);
  }
  if (distancia > 25 && distancia <=30){
    setBinaryOutput(0b111);
  }
  if (distancia > 30 && distancia <=35){
    setBinaryOutput(0b101);
  }
  if (distancia >= 35 && distancia <=40){
    setBinaryOutput(0b100);
  }
  
  int EstS2 = digitalRead(EntS2);
  int EstS1 = digitalRead(EntS1);
  int EstS0 = digitalRead(EntS0);
  
  setDisplayNumber(EstS2, EstS1, EstS0);
  
  Serial.print("Gray Output: ");
  for (int i = 3; i >= 0; i--) {
    Serial.print(output[i]);
  }
  
  Serial.println();
  digitalWrite(PinSalidaA, output[2]);
  digitalWrite(PinSalidaB, output[1]);
  digitalWrite(PinSalidaC, output[0]);
  delay(500);
}


void setBinaryOutput(byte binaryValue) {
  // Descomponer el valor binario en los elementos del array
  for (int i = 0; i < 3; i++) {
    output[i] = (binaryValue >> i) & 0x01;
  }
}

void setDisplayNumber(int EstS2, int EstS1, int EstS0) {
  if (EstS2 == 0 && EstS1 ==1 && EstS0 ==1){
    //Codigo para 0
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  Serial.println("DecOutput = 0");
  }
  if (EstS2 == 1 && EstS1 ==0 && EstS0 ==0){
    //Codigo para 1
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.println("DecOutput = 1");
  }
  if (EstS2 == 1 && EstS1 ==1 && EstS0 ==0){
    //Codigo para 2
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  Serial.println("DecOutput = 2");
  }
  if (EstS2 == 1 && EstS1 ==0 && EstS0 ==1){
    //Codigo para 3
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  Serial.println("DecOutput = 3");
  }
  if (EstS2 == 0 && EstS1 ==0 && EstS0 ==1){
    //Codigo para 4
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  Serial.println("DecOutput = 4");
  }
  if (EstS2 == 0 && EstS1 ==1 && EstS0 ==0){
    //Codigo para 5
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  Serial.println("DecOutput = 5");
  }
  if (EstS2 == 0 && EstS1 ==0 && EstS0 ==0){
    //Codigo para 6
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  Serial.println("DecOutput = 6");
  }
  if (EstS2 == 1 && EstS1 ==1 && EstS0 ==1){
    //Codigo para 7
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  Serial.println("DecOutput = 7");
  }
}