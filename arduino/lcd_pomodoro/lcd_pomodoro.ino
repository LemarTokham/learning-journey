#include <LiquidCrystal.h>


int seconds = 0;
int minutes = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
  // lcd initialise
  lcd_1.begin(16, 2);
  lcd_1.setCursor(4, 0);
  lcd_1.print("Pomodoro");

}

void loop() {
  lcd_1.setCursor(0, 1)
  lcd_1.print(seconds);
  

}
