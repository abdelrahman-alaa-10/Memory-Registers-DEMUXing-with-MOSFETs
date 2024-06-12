#define write0 8
#define write1 9

const int clock=2;
const int read3 = 10;
const int read2 = 11;
const int read1 = 12;
const int read0 = 13;
volatile int registerValue;

int value0;
int value1;

int bit0;
int bit1;
int bit2;
int bit3;

void readClock() {
  bit0 = digitalRead(read0);
  bit1 = digitalRead(read1);
  bit2 = digitalRead(read2);
  bit3 = digitalRead(read3);
  registerValue = (bit3 << 3) | (bit2 << 2) | (bit1 << 1) | bit0;
}

void setup() {
  Serial.begin(9600);

  pinMode(clock , OUTPUT);
  pinMode(write0, OUTPUT);
  pinMode(write1, OUTPUT);
  pinMode(read0 , INPUT);
  pinMode(read1 , INPUT);
  pinMode(read2 , INPUT);
  pinMode(read3 , INPUT);
  
  attachInterrupt(digitalPinToInterrupt(clock), readClock, RISING);
  //randomSeed(analogRead(0));
}

void loop() {
  value0 = 1;
  value1 = 1;
  Serial.println("Input values will be");
  Serial.println(value0);
  Serial.println(value1);
  delay(1000);
  digitalWrite(write0 ,value0);
  digitalWrite(write1,value1);
  delay(1000);

  digitalWrite(clock, HIGH);
  delay(1000); 
  digitalWrite(clock, LOW); 
  delay(1000);
  Serial.println("Output will be");
  Serial.print(bit3);
  Serial.print(bit2);
  Serial.print(bit1);
  Serial.println(bit0);
  Serial.println(registerValue);
  Serial.println("*********************************************");
 
}
