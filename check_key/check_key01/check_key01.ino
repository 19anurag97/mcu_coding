#include <Keypad.h>
#include <String.h>

const int ledPin =  15;
const char *OPEN_PASS = "1234";
const char *CLOSE_PASS = "5678";

char otp[] = "";

const byte n_rows = 4;
const byte n_cols = 4;

void check_pass(const char *str1){
  
  int o_value = strcmp(str1, OPEN_PASS);
  int c_value = strcmp(str1, CLOSE_PASS);
  
  if(o_value==0){
    Serial.println(str1);
    Serial.println("\n OPEN..............\n");
    digitalWrite(ledPin, HIGH);
  }
  
  else if(c_value==0) {
    Serial.println(str1);
    Serial.println("\n CLOSE................\n");
    digitalWrite(ledPin, LOW);
  }

  else if(OPEN_PASS != str1 && CLOSE_PASS != str1){
    Serial.println("\n WRONG INPUT ENTERED................\n");
  }
}
 
char keys[n_rows][n_cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte colPins[n_rows] = {D3, D2, D1, D0};
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
