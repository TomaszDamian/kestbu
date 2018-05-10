int ljosA = 9;
int takkiA = 10;
int ljosB = 7;
int takkiB = 8;
int ljosSW = 5;
int takkiSW = 6;

int takkiA_stada;
int takkiB_stada;

int takkiSW_stada = HIGH;  // Takkinn er tengdur �annig a� hann er alltaf HIGH og ver�ur LOW �egar �tt er � hann.
int takkiSW_stada_adur = LOW;  // Takkinn hefur bara tv�r st��ur. Ef sta�an er n�na HIGH �� hefur s��asta sta�a �ar � undan veri� LOW.
int ljosSW_stada = HIGH; // H�r hefur LED-i� bara tv�r st��ur kveikt e�a sl�kkt, ef er n�na sl�kkt �� hefur �a� veri� kveikt �ar � undan.

void setup() {
	pinMode(ljosA,OUTPUT);
  pinMode(takkiA,INPUT);
  pinMode(ljosB,OUTPUT);
  pinMode(takkiB,INPUT);
  pinMode(ljosSW,OUTPUT);
  pinMode(takkiSW,INPUT);
}

void loop() {
  // Takki A er tengdur �annig a� pinni 10 er alltaf me� LOW nema �egar �tt er � takkann �� f�r pinni 10 HIGH
  takkiA_stada = digitalRead(takkiA);
  if(takkiA_stada == HIGH) {
  	digitalWrite(ljosA,HIGH);
  } else {
  	digitalWrite(ljosA,LOW);
  }
  
  // Takki B er tengdur �annig a� pinni 8 er alltaf me� HIGH nema �egar �tt er � takkann �� f�r pinni 8 LOW
  takkiB_stada = digitalRead(takkiB);
  if(takkiB_stada == LOW) {
  	digitalWrite(ljosB,HIGH);
  } else {
  	digitalWrite(ljosB,LOW);
  }
  
  // Takki SW er tengdur eins og Takki B �.e. er alltaf HIGH nema �egar �tt er � takkann
  takkiSW_stada = digitalRead(takkiSW); // Er almennt HIGH
  // Ef takkiSW er HIGH (sem hann er almennt) og var ��ur LOW viljum vi� breyta st��unni.
  // �etta er gert til a� breytingin ver�i �egar vi� sleppum takkanum.
  if(takkiSW_stada == HIGH && takkiSW_stada_adur == LOW) {
  //if(takkiSW_stada == LOW) {  // pr�fa�u a� afkommenta �essa l�nu og kommenta � sta�in l�nuna h�r fyrir ofan og sj��u hvort virkar betur.
    if(ljosSW_stada == HIGH) {
    	ljosSW_stada = LOW;
    } else {
    	ljosSW_stada = HIGH;
    }
  }

  digitalWrite(ljosSW,ljosSW_stada);
  takkiSW_stada_adur = takkiSW_stada;
}

