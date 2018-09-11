#define ROW_1 13
#define ROW_2 8
#define ROW_3 A3
#define ROW_4 10
#define ROW_5 5
#define ROW_6 A2
#define ROW_7 4
#define ROW_8 A0

#define COL_1 9
#define COL_2 3
#define COL_3 2
#define COL_4 12
#define COL_5 A1
#define COL_6 11
#define COL_7 7
#define COL_8 6

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const int buttonPin =A4;
// The display buffer
byte one[] = {B00000000,B00011000,B00010000,B00010000,B00010000,B00111000,B00000000,B00000000};
byte two[] = {B00000000,B00011100,B00010000,B00011100,B00000100,B00011100,B00000000,B00000000};
byte three[] = {B00000000,B00011100,B00010000,B00011000,B00010000,B00011100,B00000000,B00000000};
byte four[] = {B00000000,B00101000,B00101000,B00111000,B00100000,B00100000,B00000000,B00000000};
byte five[] = {B00000000,B00111000,B00001000,B00111000,B00100000,B00111000,B00000000,B00000000};
byte six[] = {B00000000,B00001100,B00000100,B00011100,B00010100,B00011100,B00000000,B00000000};
byte seven[] = {B00000000,B00111000,B00100000,B00100000,B00100000,B00100000,B00000000,B00000000};
byte eight[] = {B00000000,B00111000,B00101000,B00111000,B00101000,B00111000,B00000000,B00000000};
byte nine[] = {B00000000,B00111000,B00101000,B00111000,B00100000,B00100000,B00000000,B00000000};
byte ten[] = {B00000000,B00111010,B00101010,B00101010,B00101010,B00111010,B00000000,B00000000};
byte eleven[] = {B00000000,B00010100,B00010100,B00010100,B00010100,B00010100,B00000000,B00000000};
byte twelve[] = {B00000000,B01110100,B01000100,B01110100,B00010100,B01110100,B00000000,B00000000};
byte thirteen[] ={B00000000,B01110100,B01000100,B01100100,B01000100,B01110100,B00000000,B00000000};
byte fourteen[] = {B00000000,B01010100,B01010100,B01110100,B01000100,B01000100,B00000000,B00000000};
byte fifteen[] = {B00000000,B01110100,B00010100,B01110100,B01000100,B01110100,B00000000,B00000000};
byte sixteen[] = {B00000000,B00010100,B00010100,B01110100,B01010100,B01110100,B00000000,B00000000};
byte seventeen[] = {B00000000,B01110100,B01000100,B01000100,B01000100,B01000100,B00000000,B00000000};
byte eighteen[] = {B00000000,B01110100,B01010100,B01110100,B01010100,B01110100,B00000000,B00000000};
byte nineteen[] = {B00000000,B01110100,B01010100,B01110100,B01000100,B01000100,B00000000,B00000000};
byte twenty[] = {B00000000,B01110111,B01010100,B01010111,B01010001,B01110111,B00000000,B00000000};
float timeCount = 0;
int lapCount=0;
int state=0;
int buttonState = 0;
void setup() {
    // Open serial port
    Serial.begin(9600);
      pinMode(buttonPin, INPUT);
    // Set all used pins to OUTPUT
    // This is very important! If the pins are set to input
    // the display will be very dim.
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() {
//read the pushbuttons with a simple antibounce
 buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH) {
  state=1;
  
 }
 if (buttonState == LOW &&state ==1) {
  
  lapCount += 1; 
  state=0;
 }
delay(1);
if(lapCount ==  1){drawScreen(one);} 
else if (lapCount ==  2){drawScreen(two);}
else if (lapCount ==  3){drawScreen(three);}
else if (lapCount ==  4){drawScreen(four);}
else if (lapCount ==  5){drawScreen(five);}
else if (lapCount ==  6){drawScreen(six);}
else if (lapCount ==  7){drawScreen(seven);}
else if (lapCount ==  8){drawScreen(eight);}
else if (lapCount ==  9){drawScreen(nine);}
else if (lapCount ==  10){drawScreen(ten);}
else if (lapCount ==  11){drawScreen(eleven);}
else if (lapCount ==  12){drawScreen(twelve);}
else if (lapCount ==  13){drawScreen(thirteen);}
else if (lapCount ==  14){drawScreen(fourteen);}
else if (lapCount ==  15){drawScreen(fifteen);}
else if (lapCount ==  16){drawScreen(sixteen);}
else if (lapCount ==  17){drawScreen(seventeen);}
else if (lapCount ==  18){drawScreen(eighteen);}
else if (lapCount ==  19){drawScreen(nineteen);}
else if (lapCount ==  20){drawScreen(twenty);}
else if (lapCount >  20) {lapCount=1;}
}
 void  drawScreen(byte buffer2[]){
     
    
   // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i]); // Set columns for this specific row
        
        digitalWrite(rows[i], HIGH);
        delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
        
    }
}


void setColumns(byte b) {
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
    
    // If the polarity of your matrix is the opposite of mine
    // remove all the '~' above.
}
