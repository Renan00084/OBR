byte ire = 31, ird = 30;

byte led = 32;

byte sentido1 = 22, sentido2 = 23, enable1 = 2;
byte sentido3 = 24, sentido4 = 25, enable2 = 3;
byte sentido5 = 26, sentido6 = 27, enable3 = 4;
byte sentido7 = 28, sentido8 = 29, enable4 = 5;

byte leituraIre, leituraIrd;

void setup() {
  Serial.begin(9600);
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

  pinMode(led, OUTPUT);

}
//Branco: entre 0 e 50/ Preto: maior que 100 / Verde: entra 50 e 100
void loop() {
  digitalWrite(led, HIGH);

  leituraIre = digitalRead(ire);
  leituraIrd = digitalRead(ird);
  Serial.println(leituraIre);
  Serial.println(leituraIrd);

  if(((leituraIre == HIGH) && (leituraIrd == HIGH)) || ((leituraIre == LOW) && (leituraIrd == LOW))){
    //reto
    analogWrite(enable1, 200); // Esquerda Frente
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    digitalWrite(enable2, HIGH); // Esquerda Atras
    digitalWrite(sentido3, LOW);
    digitalWrite(sentido4, HIGH);

    digitalWrite(enable3, HIGH); // Direita Atras
    digitalWrite(sentido5, LOW);
    digitalWrite(sentido6, HIGH);

    analogWrite(enable4, 120); // Direita Frente
    digitalWrite(sentido7, LOW);
    digitalWrite(sentido8, HIGH);

  }else{
    if(((leituraIre == HIGH) && (leituraIrd == LOW))){
      //curva esquerda

      analogWrite(enable1, 200); // Esquerda Frente
      digitalWrite(sentido1, LOW);
      digitalWrite(sentido2, HIGH);

      digitalWrite(enable2, HIGH); // Esquerda Atras
      digitalWrite(sentido3, HIGH);
      digitalWrite(sentido4, LOW);

      digitalWrite(enable3, LOW); // Direita Atras
      digitalWrite(sentido5, LOW);
      digitalWrite(sentido6, HIGH);

      analogWrite(enable4, 0); // Direita Frente
      digitalWrite(sentido7, HIGH);
      digitalWrite(sentido8, LOW);

    }else{
      if(((leituraIre == LOW) && (leituraIrd == HIGH))){
        //curva direita

        analogWrite(enable1, 0); // Esquerda Frente
        digitalWrite(sentido1, HIGH);
        digitalWrite(sentido2, LOW);

        digitalWrite(enable2, LOW); // Esquerda Atras
        digitalWrite(sentido3, LOW);
        digitalWrite(sentido4, HIGH);

        digitalWrite(enable3, HIGH); // Direita Atras
        digitalWrite(sentido5, HIGH);
        digitalWrite(sentido6, LOW);

        analogWrite(enable4, 120); // Direita Frente
        digitalWrite(sentido7, LOW);
        digitalWrite(sentido8, HIGH);

      }
    }
  }

  /*if(((leituraIre < 300) && (leituraIre > 100)) && ((leituraIrd < 300) && (leituraIrd > 100)) || ((leituraIre > 800) && (leituraIrd > 800))){
    //ligar os motores no mesmo sentido
    analogWrite(enable1, 100);
    digitalWrite(sentido1, HIGH);
    digitalWrite(sentido2, LOW);

    analogWrite(enable2, 100);
    digitalWrite(sentido3, HIGH);
    digitalWrite(sentido4, LOW);

    analogWrite(enable3, 100);
    digitalWrite(sentido5, HIGH);
    digitalWrite(sentido6, LOW);

    analogWrite(enable4, 100);
    digitalWrite(sentido7, HIGH);
    digitalWrite(sentido8, LOW);

    /*Serial.println("reto");
    Serial.println(leituraIre);
    Serial.println(leituraIrd);

  }else{
    if(((leituraIre < 300) && (leituraIre > 100)) && (leituraIrd > 800)){
      //curva para direita: troca o sentido das rodas da direita
      analogWrite(enable1, 100);
      digitalWrite(sentido1, HIGH);
      digitalWrite(sentido2, LOW);

      analogWrite(enable2, 100);
      digitalWrite(sentido3, HIGH);
      digitalWrite(sentido4, LOW);

      analogWrite(enable3, 100);
      digitalWrite(sentido5, HIGH);
      digitalWrite(sentido6, LOW);

      analogWrite(enable4, 100);
      digitalWrite(sentido7, HIGH);
      digitalWrite(sentido8, LOW);

      /*Serial.println("direita");
      Serial.println(leituraIre);
      Serial.println(leituraIrd);
      delay(1000);


    }else{
      if((leituraIre > 800) && ((leituraIrd < 300) && (leituraIrd > 100))){
        //curva pra esquerda: troca o sentido das rodas da esquerda

        analogWrite(enable1, 100);
        digitalWrite(sentido1, HIGH);
        digitalWrite(sentido2, LOW);

        analogWrite(enable2, 100);
        digitalWrite(sentido3, HIGH);
        digitalWrite(sentido4, LOW);

        analogWrite(enable3, 100);
        digitalWrite(sentido5, HIGH);
        digitalWrite(sentido6, LOW);

        analogWrite(enable4, 100);
        digitalWrite(sentido7, HIGH);
        digitalWrite(sentido8, LOW);

        /*Serial.println("esquerda");
        Serial.println(leituraIre);
        Serial.println(leituraIrd);
        delay(1000);


      }

    }

  }*/

  // Ambos os sensores ficam high quando idenifica preto

}