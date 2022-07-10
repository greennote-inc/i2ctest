#include <M5Core2.h>

void setup()
{
  M5.begin();
  Wire.begin(21, 22);
  M5.Lcd.setTextColor(YELLOW);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("M5StackFire I2C Tester");

  delay(3000);
  M5.Lcd.fillScreen(BLACK);
}

int textColor = YELLOW;

void loop()
{
  int address;
  int error;
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("scanning Address [HEX]");
  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      M5.Lcd.print(address, HEX);
      M5.Lcd.print(" ");
    }
    else if (error == 1)
    {
      M5.Lcd.print("_");
    }
    else if (error == 2)
    {
      M5.Lcd.print(".");
    }
    else
    {
      M5.Lcd.print("^");
    }
    delay(10);
  }

  if (textColor == YELLOW)
  {
    textColor = CYAN;
  }
  else
    textColor = YELLOW;
  M5.Lcd.setTextColor(textColor, BLACK);
}
