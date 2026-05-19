#define S2 6
#define S3 7
#define OUT 8

void medirCor();

int pulse = 0, pulseR = 0, pulseG = 0, pulseB = 0;
int ledR = 3, ledG = 2, ledB = 4;

void setup(){
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);
  Serial.begin(115200);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

} 

void loop(){
  medirCor();
  delay(741);

}

void medirCor(){
  //Seleciona leitura com filtro para vermelho
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  //Lê duração do pulso em LOW
  pulseR = pulseIn(OUT, LOW);
  //Imprime via serial
  Serial.print(" RED = ");
  Serial.print(pulseR);
  Serial.print(" | ");
  delay(20);

  //Seleciona leitura com filtro para verde
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  //Lê duração do pulso em LOW
  pulseG = pulseIn(OUT, LOW);
  //Imprime via serial
  Serial.print("GREEN = ");
  Serial.print(pulseG);
  Serial.print(" | ");
  delay(20);

  //Seleciona leitura com filtro para azul
  digitalWrite(S2, LOW);
  digitalWrite(S3,HIGH);
  //Lê duração do pulso em LOW
  pulseB = pulseIn(OUT, LOW);
  //Imprime via serial
  Serial.print("BLUE = ");
  Serial.println(pulseB);
  delay(20);

  if((pulseR < pulseG) && (pulseR < pulseB)){
    digitalWrite(ledR, HIGH);
    delay (1000);
    digitalWrite(ledR,LOW);

  }else{
    if((pulseG < pulseR) && (pulseG < pulseB)){
      digitalWrite(ledG, HIGH);
      delay (1000);
      digitalWrite(ledG,LOW);


    }else{
      if((pulseB < pulseR) && (pulseB < pulseG)){
        digitalWrite(ledB, HIGH);
        delay (1000);
        digitalWrite(ledB,LOW);


      }
    }
  }

}
