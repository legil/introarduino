//IMPROVED : Turn on LED when button is pressed and keep it on after button is released

const int LED = 13; // the pin for the LED
const int BUTTON = 7; //the input pin where the pushbutton is connected

int val  = 0; // val will be used to store the state of the input pin

int old_val = 0; // this variable stores the previous value of "val"

int state = 0; // 0 = LED OFF and 1 = LED ON

void setup(){
  pinMode(LED, OUTPUT); // tells Arduino that LED is an output
  pinMode(BUTTON, INPUT); // tells Arduino that BUTTON is an input
  }
  
//checks if there was a transition
void loop(){
  val = digitalRead(BUTTON); //reads new input value and stores it as "val"
  
  if ((val == HIGH) && (old_val == LOW)){
    state = 1 - state;
    }
    
    old_val = val; //val is now old, lets store it
    
    if(state == 1){
      digitalWrite(LED, HIGH); //Turn LED ON when new state equals 1
      } else {
        digitalWrite(LED, LOW);
      }
  }
        
      
    
  
