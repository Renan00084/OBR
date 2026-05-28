void verde();
void desvioE();
float obstaculo();

byte ire = 31, ird = 30; //31 fio branco e 32 fio cinza

/*byte ire = A0, ird = A1;*/

byte OUTe = 34, S2e = 32, S3e = 33, pulseRe = 0, pulseGe = 0, pulseBe = 0;

byte trigger = 35, echo = 36;
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

  pinMode(S2e, OUTPUT);
  pinMode(S3e, OUTPUT);
  pinMode(OUTe, INPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

}
//Branco: entre 0 e 50/ Preto: maior que 100 / Verde: entra 50 e 100
void loop() {
  leituraIre = digitalRead(ire);
  leituraIrd = digitalRead(ird);
  Serial.println(leituraIre);
  Serial.println(leituraIrd);

  if(((leituraIre == HIGH) && (leituraIrd == HIGH)) || ((leituraIre == LOW) && (leituraIrd == LOW))){
    //reto

    if(obstaculo() < 15){
      desvioE();

    }

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

    }else{
      if(((leituraIre == LOW) && (leituraIrd == HIGH))){
        //curva direita

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

      }
    }
  }
}

void verde(){
  //Seleciona leitura com filtro para vermelho
  digitalWrite(S2e,LOW);
  digitalWrite(S3e,LOW);
  //Lê duração do pulso em LOW
  pulseRe = pulseIn(OUTe, LOW);
  //Imprime via serial
  Serial.print(" RED = ");
  Serial.print(pulseRe);
  Serial.print(" | ");

  //Seleciona leitura com filtro para verde
  digitalWrite(S2e,HIGH);
  digitalWrite(S3e,HIGH);
  //Lê duração do pulso em LOW
  pulseGe = pulseIn(OUTe, LOW);
  //Imprime via serial
  Serial.print("GREEN = ");
  Serial.print(pulseGe);
  Serial.print(" | ");
  

  //Seleciona leitura com filtro para azul
  digitalWrite(S2e, LOW);
  digitalWrite(S3e,HIGH);
  //Lê duração do pulso em LOW
  pulseBe = pulseIn(OUTe, LOW);
  //Imprime via serial
  Serial.print("BLUE = ");
  Serial.println(pulseBe);

  if((pulseGe < pulseRe) && (pulseGe < pulseBe)){
    for(byte i = 0; i < 300; i++){
      analogWrite(enable1, 100); // Esquerda Frente
      digitalWrite(sentido1, HIGH);
      digitalWrite(sentido2, LOW);

      analogWrite(enable2, 100); // Esquerda Atras
      digitalWrite(sentido3, LOW);
      digitalWrite(sentido4, HIGH);

      analogWrite(enable3, 100); // Direita Atras
      digitalWrite(sentido5, HIGH);
      digitalWrite(sentido6, LOW);

      analogWrite(enable4, 100); // Direita Frente
      digitalWrite(sentido7, HIGH);
      digitalWrite(sentido8, LOW);


    }

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

  delay(1200);

}