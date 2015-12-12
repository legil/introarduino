//Turn on LED when the button is pressed and keep it lit after releasing pushbutton

const int LED = 13; // the pin for the LED
const int BUTTON = 7; // the input pin where the pushbutton is stored

int val = 0; //val will be used to store the state of the input pin
int state = 0; //state = 0 when LED is OFF, state = 1 when LED is ON

void setup(){
  pinMode(LED, OUTPUT); //tell Arduino LED is an output
  pinMode(BUTTON, INPUT); //tell Arduino BUTTON is an input
}
  
void loop(){
  val = digitalRead(BUTTON); //read input value and store it
  
  //check if is HIGH(button is pressed), and change the state
  if (val == HIGH){
    state = 1-state;
    }
    
  if (state == 1){
    digitalWrite(LED, HIGH);
    } else {
    digitalWrite(LED, LOW);
    }
  }

