// led_btn

const int ledPin = 13;
const int buttonPin = 7;

int buttonState = 0;
int lastButtonState;
int ledState = LOW;

// debounce on button
unsigned long lastTimeButtonChanged = millis();
unsigned long desbounceDuration = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  lastButtonState = digitalRead(buttonPin);
}
void loop() {
  // always waiting more than 50ms after a state change before doing another state change, canceling out any potential bouncing
  if (millis() - lastTimeButtonChanged >= desbounceDuration){
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState){
      lastTimeButtonChanged = millis(); // storing the time since the buttonState changed
      lastButtonState = buttonState;
      if (buttonState == LOW){
        if (ledState == HIGH){ // if LED is currently on when we press the button, it will turn off, and vice versa
          ledState = LOW;
        } else {
          ledState = HIGH;
        }
        digitalWrite(ledPin, ledState);

      } 
    }
  }
  
}
