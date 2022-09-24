void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter the password");
}

void relay_high(String pass);

char rx_byte = 0;
String rx_str = "";

void loop() {
  if (Serial.available() > 0) { 
    rx_byte = Serial.read();       // get the character
    if (rx_byte != '\n') {
      rx_str += rx_byte;
    }
    else {
      relay_high(rx_str);   
      rx_str = "";  //string reuse.
      Serial.println("");
    }
  }
}

void relay_high(String pass){
  
  if (pass == "9001"){
    Serial.println("\nBlink the LED.");
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(5000);               
    digitalWrite(LED_BUILTIN, LOW);    
  }
  
  else {
    Serial.println("\nPassword does not match.");
  }
}
