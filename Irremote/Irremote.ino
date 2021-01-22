 #include <IRremote.h>
 
int GREENLED = 13; // Use the onboard Uno LED
int REDlED = 12;

int isObstaclePin1 = 7; // This is our input pin
int isObstaclePin2 = 8; // This is our input pin

int isObstacleAt1 = HIGH; // HIGH MEANS NO OBSTACLE
int isObstacleAt2 = HIGH; // HIGH MEANS NO OBSTACLE

void setup(){

    pinMode(GREENLED, OUTPUT);
    pinMode(REDlED, OUTPUT);

    pinMode(isObstaclePin1, INPUT);
    pinMode(isObstaclePin2, INPUT);

    Serial.begin(9600);

}

void loop(){

    isObstacleAt1 = digitalRead(isObstaclePin1);
    isObstacleAt2 = digitalRead(isObstaclePin2);

    if (isObstacleAt1 == LOW && isObstacleAt2 == LOW){

        Serial.println("WHITE DETECTED IN ALL!");
        digitalWrite(GREENLED, HIGH);
        digitalWrite(REDlED, HIGH);
        delay(100);
         digitalWrite(GREENLED, LOW);
        digitalWrite(REDlED, LOW);
        delay(100);
        
    }

    else if(isObstacleAt1 == LOW && isObstacleAt2 == HIGH){
        Serial.println("WHITE DETECTED AT 2!");
        digitalWrite(GREENLED, HIGH);
        delay(100);
         digitalWrite(GREENLED, LOW);
        delay(100);
        
    }

        else if(isObstacleAt1 == HIGH && isObstacleAt2 == LOW){
        Serial.println("WHITE DETECTED AT 1");
        digitalWrite(REDlED, HIGH);
        delay(100);
         digitalWrite(REDlED, LOW);
        delay(100);
        
        }

    else {
      digitalWrite(GREENLED, LOW);
      digitalWrite(REDlED, LOW);
    }

    delay(200);

}
