#define pin1_2 7 //Out
#define pin3_4 5 //Out
#define pin5_6 3 //In
#define pin7_8 4 //In
#define pin9_10 6 //Out
#define pin11_12 8 //Out
#define pin9 9 //In
#define pin10 10 //In

int val[12][8] = {
        {1,0,0,0,0,0,1,0},//1
        {1,0,0,0,0,0,0,1},//2
        {0,1,0,0,0,0,1,0},//3
        {0,1,0,0,0,0,0,1},//4
        {0,0,1,0,0,0,1,0},//5
        {0,0,1,0,0,0,0,1},//6
        {0,0,0,1,0,0,1,0},//7
        {0,0,0,1,0,0,0,1},//8
        {0,0,0,0,1,0,1,0},//9
        {0,0,0,0,1,0,0,1},//10
        {0,0,0,0,0,1,1,0},//11
        {0,0,0,0,0,1,1,1},};//12

int digit[8] = {
          pin1_2,
          pin3_4,
          pin5_6,
          pin7_8,
          pin9_10,
          pin11_12,
          pin9,
          pin10};


void setup() {

  Serial.begin(9600);

  pinMode(pin1_2, OUTPUT);
  pinMode(pin3_4, OUTPUT);
  
  pinMode(pin5_6, OUTPUT);
  pinMode(pin7_8, OUTPUT);

  pinMode(pin9_10, OUTPUT);
  pinMode(pin11_12, OUTPUT);

  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  
}

char c;
int leds = -1;

void lightLed(int leds){

  int p = 258;
  for(int i = 0; i < 12; i++){
    if(i  == leds - 1){
      for(int j = 0; j < 8; j++){

        p = val[i][j];
        digitalWrite(digit[j], p);

        //если регулировать для одинакового свечения//
        // if (val[i][j] == 1){
        //   p = 120;
        // }
        // else {p = 0;}
        // analogWrite(digit[j], p);
                  
      }        
    }            
  }
  delay(5);
}

int arr[] = {};

void loop() {   

  for(int i = 0; i < 4; i++){

    if (Serial.available() > 0){
    
      c = Serial.read();
      leds = c - '0';
      arr[i] = leds;                  
  }
  lightLed(arr[i]);
  } 
}
    

    
    
    
  
    
 
