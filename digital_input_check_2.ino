#define SIZE 500
#define PASS 2

short int data[SIZE];
int pass;
int index;
int ocra_value;
int captureflag;
int timerflag;
int printflag;
int del;
int offset;
void empty(){
  
}

void setup() {

TCCR1A = 0;
TCCR1B = 0;
TCCR1B = (1<<CS10)|(1<<WGM12);
ocra_value = 4;
OCR1A = 2000;


EICRA = 0b00000101;
TIMSK1 = (1<<OCIE1A);

EIMSK = 0b00000011;
Serial.begin(9600);

Serial.println("Digital Signal capture");
Serial.print("Enter the freq:  512000\n");
Serial.println("Instruction::");
Serial.println("1. use a Serial monitor reader");
Serial.println("2.export the data ");
Serial.println("3.use the C program to extract the data" );
Serial.println("4.use the excel file to generate the graph\n");


captureflag = 0;
timerflag = 0;
}

void loop() {
  //don't use interrupt in loop section

  if (captureflag && timerflag){
    index -=offset;
    offset +=index;
    while(index--){
      Serial.println(data[index]);
    }
    captureflag = 0;
    timerflag = 0;
    Serial.println("new data in 1Sec");
    delay(1000);
    Serial.println("ready");
  }
}

ISR(TIMER1_COMPA_vect){
  //Serial.println(millis());
  if (captureflag && !timerflag ) {
    
    if (index >= offset) {
      data[index-offset] = (PIND&0b11111100)>>2;
      ++index;
    }
    if (index<offset) index++;
    
    if (index-offset == SIZE) {
      timerflag = 1;
      
      
     
    }
    
  }
  
}

ISR(INT0_vect){
  captureflag = 1;

}

ISR(INT1_vect){
  captureflag = 1;
  
}
