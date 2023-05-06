// Programa para ler o sensor de luminosidade

int ledVermelho=8;
int ledAmarelo=9;
int ledVerde=10;
float LDR=A0;
int valorLDR=0;

int minimo=30;
int maximo=50;

void setup() {

  Serial.begin(9600);
  pinMode(ledVermelho,OUTPUT);
  pinMode(ledAmarelo,OUTPUT);
  pinMode(ledVerde,OUTPUT);

  pinMode(LDR,INPUT);
}

void loop(){


  valorLDR = analogRead(LDR);
  
  if (valorLDR < minimo){ apagarLeds(); digitalWrite(ledVermelho, HIGH); }
  
  if (valorLDR >= minimo && valorLDR < maximo){ apagarLeds(); digitalWrite(ledAmarelo, HIGH);  }
  
  if (valorLDR >=maximo ){ apagarLeds(); digitalWrite(ledVerde, HIGH); } 
  
  Serial.print(valorLDR);
}

void apagarLeds(){

    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);

}
