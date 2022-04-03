#define POTANTIOMETRE A0
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor = analogRead(POTANTIOMETRE);
  Serial.println(sensor);
  delay(1);

  String percentage = String(sensor * 100 / 1024);
  String lcd_s = percentage + "%";
  lcd.print(lcd_s);
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
