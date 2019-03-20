int ljosA = 9;
int takkiA = 10;
int ljosB = 7;
int takkiB = 8;
int ljosSW = 5;
int takkiSW = 6;

int takkiA_stada;
int takkiB_stada;

int takkiSW_stada = HIGH;  // Takkinn er tengdur þannig að hann er alltaf HIGH og verður LOW þegar ýtt er á hann.
int takkiSW_stada_adur = LOW;  // Takkinn hefur bara tvær stöður. Ef staðan er núna HIGH þá hefur sí'asta staða þar á undan verið LOW.
int ljosSW_stada = HIGH; // Hér hefur LED-ið bara tvær stöður, kveikt eða slökkt, ef núna er slökkt þá hefur það verið kveikt þar á undan.

void setup() {
  pinMode(ljosA,OUTPUT);
  pinMode(takkiA,INPUT);
  pinMode(ljosB,OUTPUT);
  pinMode(takkiB,INPUT);
  pinMode(ljosSW,OUTPUT);
  pinMode(takkiSW,INPUT);
}

void loop() {
  // Takki A er tengdur þannig að pinni 10 er alltaf með LOW nema þegar ýtt er á takkann þá fær pinni 10 HIGH
  takkiA_stada = digitalRead(takkiA);
  if(takkiA_stada == HIGH) {
  	digitalWrite(ljosA,HIGH);
  } else {
  	digitalWrite(ljosA,LOW);
  }
  
  // Takki B er tengdur þannig að pinni 8 er alltaf með HIGH nema þegar ýtt er á takkann þá fær pinni 8 LOW
  takkiB_stada = digitalRead(takkiB);
  if(takkiB_stada == LOW) {
  	digitalWrite(ljosB,HIGH);
  } else {
  	digitalWrite(ljosB,LOW);
  }
  
  // Takki SW er tengdur eins og Takki B þ.e. er alltaf HIGH nema þegar ýtt er á takkann
  takkiSW_stada = digitalRead(takkiSW); // Er almennt HIGH
  // Ef takkiSW er HIGH (sem hann er almennt) og var áður LOW viljum við breyta stöðunni.
  // þetta er gert til að breytingin verði þegar við sleppum takkanum.
  if(takkiSW_stada == HIGH && takkiSW_stada_adur == LOW) {
  //if(takkiSW_stada == LOW) {  // prófaðu að afkommenta þessa línu og kommenta í staðin línuna hér fyrir ofan og sjáðu hvort virkar betur.
    if(ljosSW_stada == HIGH) {
    	ljosSW_stada = LOW;
    } else {
    	ljosSW_stada = HIGH;
    }
  }

  digitalWrite(ljosSW,ljosSW_stada);
  takkiSW_stada_adur = takkiSW_stada;
}

