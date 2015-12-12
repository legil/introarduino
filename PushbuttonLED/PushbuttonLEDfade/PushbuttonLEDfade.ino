//Example 05: Turn on LED when the button is pressed  and keep it on after it is released 
// includes simple debouncing
//If the brightness is held, brightness changes 

  const int LED = 9; // the pin for the LED
  const int BUTTON = 7; // input pin of pushbutton
  
  int val = 0; // stores the state of the input pin
  int old_val = 0; // stroes the previous state of "val"
  int state = 0; // 0 = LED OFF, 1 = LED ON

  int brightness = 128; // stores the brightness value
  unsigned long startTime = 0; // when did we begin pressing?

  
  
void setup() {
  pinMode(LED, OUTPUT); // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // BUTTON is an input
}

void loop() {
  val = digitalRead(BUTTON); // read input value and store it 

  // check if there was a transition
  if ((val == HIGH) && (old_val == LOW)){
    state = 1 - state; // changes the state fromoff to on or vice-versa

    startTime = millis(); // millis() is the Arduino clock, it returns how many milliseconds have passed since the board has been reset
                          // this line remembers when the button was last pressed
 

  delay(10);

  //check whether the button is being held down
    if((val == HIGH) && (old_val == HIGH)){
      
      //if the button is held for more than 500ms,
        if (state == 1 && (millis() - startTime) > 500){
          brightness++; // increment brightness by 1

          
          delay(10); // delay to avoid brightness going up to fast

        if(brightness > 255) // (255 being the max brightness)
          brightness = 0; //if we go over 255, let's go back to 0
        }
    }
}

old_val = val; //val is now old, let's store it

if (state == 1){
  analogWrite(LED, brightness); //turn LED ON at the current brightness level
} else {
    analogWrite(LED, 0); //turn LED OFF
  }
}

