#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

int tempPin = A0;
int pulsePin = A1;

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  int tempValue = analogRead(tempPin);
  float voltage = tempValue * (5.0 / 1023.0);
  float temperature = voltage * 100;

  int pulseValue = analogRead(pulsePin);
  int bpm = map(pulseValue, 0, 1023, 60, 100);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperature);

  lcd.setCursor(0,1);
  lcd.print("Pulse:");
  lcd.print(bpm);

  delay(1000);
}
