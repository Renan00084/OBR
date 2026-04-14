byte ire = A0, ird = A1;

byte leituraIre, leituraIrd;

void setup() {
  Serial.begin(9600);
  pinMode(ire,INPUT);
  pinMode(ird,INPUT);
  pinMode(leituraIre,INPUT);
  pinMode(leituraIrd,INPUT);

}
//Branco: entre 0 e 50/ Preto: maior que 100 / Verde: entra 50 e 100
void loop() {
  /*leituraIre = analogRead(ire);
  leituraIrd = analogRead(ird);
    delay(1000);
    Serial.println(leituraIre);
    Serial.println(leituraIrd);

  if(((leituraIre < 300) && (leituraIre > 100)) && ((leituraIrd < 300) && (leituraIrd > 100)) || ((leituraIre > 800) && (leituraIrd > 800))){
    //ligar os motores no mesmo sentido
    Serial.println("reto");
    Serial.println(leituraIre);
    Serial.println(leituraIrd);
    delay(1000);

  }else{
    if(((leituraIre < 300) && (leituraIre > 100)) && (leituraIrd > 800)){
      //curva para direita: troca o sentido das rodas da direita
      Serial.println("direita");
      Serial.println(leituraIre);
      Serial.println(leituraIrd);
      delay(1000);


    }else{
      if((leituraIre > 800) && ((leituraIrd < 300) && (leituraIrd > 100))){
        //curva pra esquerda: troca o sentido das rodas da esquerda
        Serial.println("esquerda");
        Serial.println(leituraIre);
        Serial.println(leituraIrd);
        delay(1000);


      }

    }

  }*/
  
  

}


