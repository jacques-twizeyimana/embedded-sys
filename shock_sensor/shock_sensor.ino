int LED=13;

int shockSensorInput=3;    // Define pin for shock sensor

int val;  // Define Variable val that will be used to stored sensor read value

int shockstate = 0;



void setup(){

  pinMode(LED,OUTPUT);

  pinMode(shockSensorInput,INPUT); // Define shock sensor as input

}



void loop(){

  val=digitalRead(shockSensorInput);

  /*

   * With this type of shockSensorInput Sensor val is HIGH when no shock is detected.

   * And val is LOW when a shock is detected.

   * In this code we implement toogle switching

   * At the first shock the LED will be switched ON and state is changed from initial 0 to 1

   * Still in the state 1 when another shock occurs LED will be switched OFF and the state is set back to initial state

   */



  if(shockstate == 0 && val==LOW){// when there is shock 

    shockstate = 1;

    digitalWrite(LED,HIGH);

    delay(1000);

  }

  else if(shockstate == 1 && val==LOW){

    digitalWrite(LED,LOW);

    shockstate = 0;

    delay(1000);

  }

}
