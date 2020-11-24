//This is the code for the artwork "Licht, Liebe, Leben" ("Light, Life, Love" a quote from J.G. Herder)  by baitishan. November 2020.
 
int LdrSensorValue = 0;
int LdrSensorPin = A1;
int light = 0;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600); //configure serial to talk to computer
    pinMode(10, OUTPUT); // configure digital pin 10 as an output
    pinMode(9, OUTPUT); // configure digital pin 9 as an output
}

void loop() {
    // put your main code here, to run repeatedly:
    light = analogRead(A1); // read and save value from PR
    
    Serial.println(light); // print current light value
    
    
    if(light > 500) { // If it is bright...
        Serial.println("It is quite light!");
        digitalWrite(10,LOW); //turn left LED off
        digitalWrite(9,LOW); // turn right LED off
   
    }
    else { // If it's dark...
        Serial.println("It is pretty dark!But there is still Light, Life and Love!"); 
        for (int fadeValue = 0; fadeValue <=255; fadeValue ++) {
    analogWrite(10, fadeValue);
    analogWrite(9, fadeValue);
    delay(10);
    Serial.println(fadeValue);
  }
for (int fadeValue = 255; fadeValue >=0; fadeValue --) {
   analogWrite(10, fadeValue);
   analogWrite(9, fadeValue);
   delay(10);
   Serial.println(fadeValue);
  }
    }
    delay(1000); // don't spam the computer!
}