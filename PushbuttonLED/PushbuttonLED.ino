const int LED = 13;   //the pin for the LED
const int BUTTON = 7; //the input pin where the
                      // pushbutton is connected

int val = 0;          // val will be used to stroe the state 
                      //of the input pin

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);       //tell arduino LED is an output
  pinMode(BUTTON, INPUT);    //and BUTTON is an input

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(BUTTON); //read input value and store it

  //check whether the input is HIGH (button pressed)
  if (val == HIGH){
    digitalWrite(LED, HIGH); //turn LED ON
  } else{
    digitalWrite(LED, LOW);
  }
}
