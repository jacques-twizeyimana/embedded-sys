int GREENLED = 13; // Use the onboard Uno LED
int REDlED = 12;

int detectorPin1 = 7; 
int detectorPin2 = 8; 

int isWhiteAt1 = HIGH; // HIGH MEANS WE DIDN'T DETECT WHITE
int isWhiteAt2 = HIGH; // HIGH MEANS WE DIDN'T DETECT WHITE

void setup(){

    pinMode(GREENLED, OUTPUT);
    pinMode(REDlED, OUTPUT);

    pinMode(detectorPin1, INPUT);
    pinMode(detectorPin2, INPUT);

    Serial.begin(9600);

}

void loop(){

    isWhiteAt1 = digitalRead(detectorPin1);
    isWhiteAt2 = digitalRead(detectorPin2);

    if (isWhiteAt1 == LOW && isWhiteAt2 == LOW){

        Serial.println("WHITE DETECTED IN ALL!");
        digitalWrite(GREENLED, HIGH);
        digitalWrite(REDlED, HIGH);
        delay(100);
         digitalWrite(GREENLED, LOW);
        digitalWrite(REDlED, LOW);
        delay(100);
        
    }

    else if(isWhiteAt1 == LOW && isWhiteAt2 == HIGH){
        Serial.println("WHITE DETECTED AT 2!");
        digitalWrite(GREENLED, HIGH);
        delay(100);
         digitalWrite(GREENLED, LOW);
        delay(100);
        
    }

        else if(isWhiteAt1 == HIGH && isWhiteAt2 == LOW){
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
