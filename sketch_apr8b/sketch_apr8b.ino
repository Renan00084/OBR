void verde();
void desvioE();
void desvioD();
float obstaculo();

byte ire = 31, ird = 30; //31 fio branco e 32 fio cinza

/*byte ire = A0, ird = A1;*/

byte OUTd = 34, S2d = 32, S3d = 33, pulseRd = 0, pulseGd = 0, pulseBd = 0;

byte trigger = 35, echo = 36, cont = 0;
float duration, distance;

byte sentido1 = 22, sentido2 = 23, enable1 = 2;
byte sentido3 = 24, sentido4 = 25, enable2 = 3;
byte sentido5 = 26, sentido6 = 27, enable3 = 4;
byte sentido7 = 28, sentido8 = 29, enable4 = 5;
byte leituraIre, leituraIrd;

void setup() {
  pinMode(ire,INPUT);
  pinMode(ird,INPUT);
  pinMode(leituraIre,INPUT);
  pinMode(leituraIrd,INPUT);

  pinMode(sentido1, OUTPUT);
  pinMode(sentido2, OUTPUT);
  pinMode(enable1, OUTPUT);

  pinMode(sentido3, OUTPUT);
  pinMode(sentido4, OUTPUT);
  pinMode(enable2, OUTPUT);

  pinMode(sentido5, OUTPUT);
  pinMode(sentido6, OUTPUT);
  pinMode(enable3, OUTPUT);

  pinMode(sentido7, OUTPUT);
  pinMode(sentido8, OUTPUT);
  pinMode(enable4, OUTPUT);

  pinMode(S2d, OUTPUT);
  pinMode(S3d, OUTPUT);
  pinMode(OUTd, INPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(115200);

}
//Branco: entre 0 e 50/ Preto: maior que 100 / Verde: entra 50 e 100
void loop() {
  leituraIre = digitalRead(ire);
  leituraIrd = digitalRead(ird);

  if(((leituraIre == HIGH) && (leituraIrd == HIGH)) || ((leituraIre == LOW) && (leituraIrd == LOW))){
    //reto

    verde();

    /*if(obstaculo() < 15){
      cont++;
      if(cont % 2 == 0){
        desvioD();

      }else{
        desvioE();

      }  

    }*/

    analogWrite(enable1, 100); // Esquerda Frente
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    analogWrite(enable2, 255); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, HIGH);

    analogWrite(enable3, 255); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, HIGH);

    analogWrite(enable4, 100); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, HIGH);

  }else{
    if(((leituraIre == HIGH) && (leituraIrd == LOW))){
      //curva esquerda

      verde();

      analogWrite(enable1, 255); // Esquerda Frente
      digitalWrite(sentido1, LOW);
      digitalWrite(sentido2, HIGH);

      digitalWrite(enable2, HIGH); // Esquerda Atras
      digitalWrite(sentido3, HIGH);
      digitalWrite(sentido4, LOW);

      digitalWrite(enable3, HIGH); // Direita Atras
      digitalWrite(sentido5, LOW);
      digitalWrite(sentido6, HIGH);

      analogWrite(enable4, 100); // Direita Frente
      digitalWrite(sentido7, HIGH);
      digitalWrite(sentido8, LOW);

      delay(300);

    }else{
      if(((leituraIre == LOW) && (leituraIrd == HIGH))){
        //curva direita

        verde();

        analogWrite(enable1, 100); // Esquerda Frente
        digitalWrite(sentido1, HIGH);
        digitalWrite(sentido2, LOW);

        digitalWrite(enable2, HIGH); // Esquerda Atras
        digitalWrite(sentido3, LOW);
        digitalWrite(sentido4, HIGH);

        digitalWrite(enable3, HIGH); // Direita Atras
        digitalWrite(sentido5, HIGH);
        digitalWrite(sentido6, LOW);

        analogWrite(enable4, 255); // Direita Frente
        digitalWrite(sentido7, HIGH);
        digitalWrite(sentido8, LOW);

        delay(300);

      }
    }
  }
}

void verde(){
  //Seleciona leitura com filtro para vermelho
  digitalWrite(S2d,LOW);
  digitalWrite(S3d,LOW);
  delayMicroseconds(50);
  //Lê duração do pulso em LOW
  pulseRd = pulseIn(OUTd, LOW, 25000);
  //Imprime via serial
  Serial.print(" RED = ");
  Serial.print(pulseRd);
  Serial.print(" | ");

  //Seleciona leitura com filtro para verde
  digitalWrite(S2d,HIGH);
  digitalWrite(S3d,HIGH);
  delayMicroseconds(50);
  //Lê duração do pulso em LOW
  pulseGd = pulseIn(OUTd, LOW, 25000);
  //Imprime via serial
  Serial.print("GREEN = ");
  Serial.print(pulseGd);
  Serial.print(" | ");
  

  //Seleciona leitura com filtro para azul
  digitalWrite(S2d, LOW);
  digitalWrite(S3d,HIGH);
  delayMicroseconds(50);
  //Lê duração do pulso em LOW
  pulseBd = pulseIn(OUTd, LOW, 25000);
  //Imprime via serial
  Serial.print("BLUE = ");
  Serial.println(pulseBd);

  if((pulseGd < pulseBd) && (pulseGd < pulseRd) && (pulseGd > 20) && (pulseGd < 60)){
    analogWrite(enable1, 0); // Esquerda Frente
    digitalWrite(sentido1, LOW);
    digitalWrite(sentido2, LOW);

    analogWrite(enable2, 0); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, LOW);

    analogWrite(enable3, 0); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, LOW);

    analogWrite(enable4, 0); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, LOW);

    delay(1000);

    analogWrite(enable1, 100); // Esquerda Frente
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    analogWrite(enable2, 255); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, HIGH);

    analogWrite(enable3, 255); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, HIGH);

    analogWrite(enable4, 100); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, HIGH);

    delay(350);

    analogWrite(enable1, 255); // Esquerda Frente
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    digitalWrite(enable2, HIGH); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, HIGH);

    digitalWrite(enable3, HIGH); // Direita Atras
    digitalWrite(sentido5, HIGH);
    digitalWrite(sentido6, LOW);

    analogWrite(enable4, 255); // Direita Frente
    digitalWrite(sentido7, HIGH);
    digitalWrite(sentido8, LOW);

    delay(1000);


  }

}

float obstaculo(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration*.0343)/2; //0.0343 é a velocidade do som em cm/μs
  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;

}

/*void desvioE{
  bool sair = false;
  
  analogWrite(enable1, 0); // Esquerda Frente
  digitalWrite(sentido1, LOW);
  digitalWrite(sentido2, LOW);

  analogWrite(enable2, 0); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, LOW);

  analogWrite(enable3, 0); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, LOW);

  analogWrite(enable4, 0); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, LOW);

  delay(1000);

  analogWrite(enable1, 255); // Esquerda Frente
  digitalWrite(sentido1, LOW);
  digitalWrite(sentido2, HIGH);

  analogWrite(enable2, 255); // Esquerda Atras
  digitalWrite(sentido3, HIGH);
  digitalWrite(sentido4, LOW);

  analogWrite(enable3, 255); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  analogWrite(enable4, 100); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(800); //Feito

  analogWrite(enable1, 100); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  analogWrite(enable2, 255); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  analogWrite(enable3, 255); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  analogWrite(enable4, 100); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(1000); //Feito

  analogWrite(enable1, 100); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  analogWrite(enable2, 255); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  analogWrite(enable3, 255); // Direita Atras
  digitalWrite(sentido5, HIGH);
  digitalWrite(sentido6, LOW);

  analogWrite(enable4, 100); // Direita Frente
  digitalWrite(sentido7, HIGH);
  digitalWrite(sentido8, LOW);

  delay(1600); //Feito

  for(int i =0; i<800; i++){
    leituraIre = digitalRead(ire);
    leituraIrd = digitalRead(ird);

    if((ire == HIGH) && (ird == HIGH)){
      sair = true;
      i = 801;

    }else{
      analogWrite(enable1, 100); // Esquerda Frente
      digitalWrite(sentido1, HIGH);
      digitalWrite(sentido2, LOW);

      analogWrite(enable2, 255); // Esquerda Atras
      digitalWrite(sentido3, LOW);
      digitalWrite(sentido4, HIGH);

      analogWrite(enable3, 255); // Direita Atras
      digitalWrite(sentido5, LOW);
      digitalWrite(sentido6, HIGH);

      analogWrite(enable4, 100); // Direita Frente
      digitalWrite(sentido7, LOW);
      digitalWrite(sentido8, HIGH);

    }

  }

  if(sair = true){
    analogWrite(enable1, 255); // Esquerda Frente
    digitalWrite(sentido1, LOW);
    digitalWrite(sentido2, HIGH);

    analogWrite(enable2, 255); // Esquerda Atras
    digitalWrite(sentido3, HIGH);
    digitalWrite(sentido4, LOW);

    analogWrite(enable3, 255); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, HIGH);

    analogWrite(enable4, 100); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, HIGH);

    delay(800); //Feito

    analogWrite(enable1, 100); // Esquerda Frente
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    analogWrite(enable2, 255); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, HIGH);

    analogWrite(enable3, 255); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, HIGH);

    analogWrite(enable4, 100); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, HIGH);

    delay(1000); //Feito

  }else{
    analogWrite(enable1, 100); // Esquerda Frente
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    analogWrite(enable2, 255); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, HIGH);

    analogWrite(enable3, 255); // Direita Atras
    digitalWrite(sentido5, HIGH);
    digitalWrite(sentido6, LOW);

    analogWrite(enable4, 100); // Direita Frente
    digitalWrite(sentido7, HIGH);
    digitalWrite(sentido8, LOW);

    delay(1600);

    analogWrite(enable1, 100); // Esquerda Frente
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    analogWrite(enable2, 255); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, HIGH);

    analogWrite(enable3, 255); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, HIGH);

    analogWrite(enable4, 100); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, HIGH);

    delay(800);

    analogWrite(enable1, 100); // Esquerda Frente
    digitalWrite(sentido1, LOW);
    digitalWrite(sentido2, HIGH);

    analogWrite(enable2, 255); // Esquerda Atras
    digitalWrite(sentido3, HIGH);
    digitalWrite(sentido4, LOW);

    analogWrite(enable3, 255); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, HIGH);

    analogWrite(enable4, 100); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, HIGH);

    delay(1000);

  }

}*/

void desvioE(){
  analogWrite(enable1, 0); // Esquerda Frente
  digitalWrite(sentido1, LOW);
  digitalWrite(sentido2, LOW);

  analogWrite(enable2, 0); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, LOW);

  analogWrite(enable3, 0); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, LOW);

  analogWrite(enable4, 0); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, LOW);

  delay(1000);

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, LOW);
  digitalWrite(sentido2, HIGH);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, HIGH);
  digitalWrite(sentido4, LOW);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(800); //Feito

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(1600); //Feito

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, HIGH);
  digitalWrite(sentido6, LOW);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, HIGH);
  digitalWrite(sentido8, LOW);

  delay(1000); //Feito

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(1300);

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, HIGH);
  digitalWrite(sentido6, LOW);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, HIGH);
  digitalWrite(sentido8, LOW);

  delay(1200);

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(600);

}

void desvioD(){
  analogWrite(enable1, 0); // Esquerda Frente
  digitalWrite(sentido1, LOW);
  digitalWrite(sentido2, LOW);

  analogWrite(enable2, 0); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, LOW);

  analogWrite(enable3, 0); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, LOW);

  analogWrite(enable4, 0); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, LOW);

  delay(1000);

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, HIGH);
  digitalWrite(sentido6, LOW);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, HIGH);
  digitalWrite(sentido8, LOW);

  delay(1000); //Feito

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(1600); //Feito

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, LOW);
  digitalWrite(sentido2, HIGH);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, HIGH);
  digitalWrite(sentido4, LOW);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(800); //Feito

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(1200);

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, LOW);
  digitalWrite(sentido2, HIGH);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, HIGH);
  digitalWrite(sentido4, LOW);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(800);

  digitalWrite(enable1, HIGH); // Esquerda Frente
  digitalWrite(sentido1, HIGH);
  digitalWrite(sentido2, LOW);

  digitalWrite(enable2, HIGH); // Esquerda Atras
  digitalWrite(sentido3, LOW);
  digitalWrite(sentido4, HIGH);

  digitalWrite(enable3, HIGH); // Direita Atras
  digitalWrite(sentido5, LOW);
  digitalWrite(sentido6, HIGH);

  digitalWrite(enable4, HIGH); // Direita Frente
  digitalWrite(sentido7, LOW);
  digitalWrite(sentido8, HIGH);

  delay(900);


}