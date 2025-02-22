// Pomodore study timer on an LCD screen

#include <LiquidCrystal.h>

// button and Led - green: ON, red: PAUSED, blue: REST
const int redLedPin = 13;
const int greenLedPin = 8;
const int blueLedPin = 6;
const int buttonPin = 7;
int buttonState = 0;
int lastButtonState;

// debounce on button
unsigned long lastTimeButtonChanged = millis();
unsigned long desbounceDuration = 50;

// pomodoro decleratons
int seconds = 0;
int minutes = 0;
int study = 25;
int rest = 5;
bool studying = true;

// tracking time
unsigned long lastSecondUpdate = 0;

// keeping track on what run we are on so we can display starting text
bool firstRun = true;

// define lcd pins
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2); 

// keping track of clock state, false meaning the clock isn't going, used to see wheter we paused or not
bool clockState = false;

void setup() {
  // lcd initialise
  lcd_1.begin(16, 2);

  // led pin
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  // button pin
  pinMode(buttonPin, INPUT);
  lastButtonState = digitalRead(buttonPin);
}

void loop() {
  // when we press the button, the below code run, when we press it again, it stops and pauses
  if (millis() - lastTimeButtonChanged >= desbounceDuration){
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState){
      lastButtonState = buttonState;
      if (buttonState == LOW){
        if (clockState == false){
          if (firstRun){
           firstRun = false;
          }
           clockState = true;
          lcd_1.clear(); // clear screen everytime button state is changed
        } else {
          clockState = false;
        }
      }
    }
  }
  if (clockState == true){
    // when the clock starts going, green is on, red is off
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    // position of 'Pomodoro' sign
    lcd_1.setCursor(4, 0);
    lcd_1.print("Pomodoro");

    // position of time
    lcd_1.setCursor(0, 1);
    
    // track flag for study mode or rest mode
    if (studying){
      digitalWrite(blueLedPin, LOW);
      // displaying and formatting the minutes and seconds
      if (minutes < study){
        lcd_1.print("Study: ");
        lcd_1.print(minutes);
        lcd_1.print(":");
        lcd_1.print(seconds);
        if (millis() - lastSecondUpdate >= 1000){
          lastSecondUpdate = millis(); // reset the seconds timer
          seconds++;
          if (seconds == 60) {
            minutes += 1;
            seconds = 0;
          }
        }
      } else {
        studying = false;
        lcd_1.clear();
        minutes = 0;
        seconds = 0;
      }
    } else if (studying == false){ // initiate rest period
      digitalWrite(blueLedPin, HIGH);
      // displaying and formatting the minutes and seconds
      if (minutes < rest){
        lcd_1.print("Rest: ");
        lcd_1.print(minutes);
        lcd_1.print(":");
        lcd_1.print(seconds);
        if (millis() - lastSecondUpdate >= 1000){
          lastSecondUpdate = millis();
          seconds++;
          if (seconds == 60) {
            minutes += 1;
            seconds = 0;
          }
        }
        
      } else {
        studying = true; // reset the screen and time ready for study period
        
        minutes = 0;
        seconds = 0;
      }
    } 
  } else {
    if (firstRun){
      // turn off both LEDs a the very start
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, LOW);
      // display starting text
      lcd_1.setCursor(0, 0);
      lcd_1.print("Happy Studying:)");
      lcd_1.setCursor(0, 1);
      lcd_1.print("Click to Start->");
    } else {
      // when the clock is paused, red is on, green is off
      digitalWrite(greenLedPin, LOW);
      digitalWrite(redLedPin, HIGH);
      // display "paused" sign
      lcd_1.setCursor(0, 0);
      lcd_1.print("Pomodoro: Paused");
    }
  }
  
}
  

  







