#include <Keypad.h>
#include <String.h>

const int ledPin1 =  15;
const int ledPin2 =  3;

const char *OPEN_PASS1 = "1234";
const char *OPEN_PASS2 = "4321";
const char *CLOSE_PASS = "5678";

char otp[] = "";

const byte n_rows = 4;
const byte n_cols = 3;

void check_pass(const char *str1){
  
  int o1_value = strcmp(str1, OPEN_PASS1);
  int o2_value = strcmp(str1, OPEN_PASS2);
  int c_value = strcmp(str1, CLOSE_PASS);
  
  if(o1_value==0){
    Serial.println(str1);
    Serial.println("\n OPEN LED1..............\n");
    digitalWrite(ledPin1, HIGH);
    delay(3000);
    digitalWrite(ledPin1, LOW);
  }

  else if(o2_value==0){
    Serial.println(str1);
    Serial.println("\n OPEN LED2..............\n");
    digitalWrite(ledPin2, HIGH);
    delay(3000);
    digitalWrite(ledPin2, LOW);
  }
  /*
  else if(c_value==0) {
    Serial.println(str1);
    Serial.println("\n CLOSE................\n");
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }*/
  
  else if(OPEN_PASS1 != str1 && OPEN_PASS2 != str1){
    Serial.println("\n WRONG INPUT ENTERED................\n");
  }
}
 
char keys[n_rows][n_cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
 
byte colPins[n_rows] = {D3, D2, D1};
byte rowPins[n_cols] = {D7, D6, D5, D4};
 
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 
 
void setup(){
  
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

}
 
void loop(){
  
  int count = 0;
  while (count < 4){
    char myKey = myKeypad.waitForKey();
    Serial.println(myKey);
    *(otp+count) = myKey;
    count++;
    delay(400);
  }
  *(otp+4) = NULL;
  check_pass(otp);
  Serial.println(otp);
  
}
