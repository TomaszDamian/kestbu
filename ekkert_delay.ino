int takki = 10; // tengdur sem almennt HIGH
int takkaljos = 9;
int blikkljos = 2;

int takki_stada = HIGH; 
int blikktimi = 1000; 
unsigned long lidinn_blikk_timi = 0; // int er bara 16 bita, long er 32 bita
int blikkljos_stada = HIGH; // viljum vi� byrja me� blikklj�si� kveikt e�a sl�kt?


void setup() {
	pinMode(takki, INPUT);
  	pinMode(takkaljos, OUTPUT);
  	pinMode(blikkljos, OUTPUT);
}

void loop() {
  unsigned long timi_nuna = millis(); // millis() skilar fj�lda millisek�ndna s��an forriti� byrja�i a� keyra
  
  if((timi_nuna - lidinn_blikk_timi) >= blikktimi) { // hvernig m�tti leysa �etta me� modulus?
  	
    lidinn_blikk_timi = timi_nuna; // geymum n�verandi t�matalningu
    
    if(blikkljos_stada == LOW) { // v�xlum st��unni � lj�sunum
    	blikkljos_stada = HIGH;
    } else {
    	blikkljos_stada = LOW;
    }
  }
  digitalWrite(blikkljos, blikkljos_stada);
  
  takki_stada = digitalRead(takki);  
  if(takki_stada == LOW) {
  	digitalWrite(takkaljos, HIGH);
  }
}