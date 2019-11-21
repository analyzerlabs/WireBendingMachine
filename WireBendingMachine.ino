
#include "knob.h"

//UTFT myGLCD(ITDB32S,38,39,40,41);
knob grafico;
void setup()
{
  grafico = new knob(160, 160, 100, letraSecundaria);
  randomSeed(analogRead(0));
  // Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
}

void loop()
{
  int buf[318];
  int x, x2;
  int y, y2;
  int r;

  // Clear the screen and draw the frame

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(1, 15, 318, 224);
  TouchInit();
  // Draw some filled, rounded rectangles
  for (int i = 1; i < 6; i++)
  {
    switch (i)
    {
      case 1:
        myGLCD.setColor(255, 0, 255);
        break;
      case 2:
        myGLCD.setColor(255, 0, 0);
        break;
      case 3:
        myGLCD.setColor(0, 255, 0);
        break;
      case 4:
        myGLCD.setColor(0, 0, 255);
        break;
      case 5:
        myGLCD.setColor(255, 255, 0);
        break;
    }
    myGLCD.fillRoundRect(190 - (i * 20), 30 + (i * 20), 250 - (i * 20), 90 + (i * 20));
  }

  delay(2000);

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(1, 15, 318, 224);

  // Draw some filled circles
  for (int i = 1; i < 6; i++)
  {
    switch (i)
    {
      case 1:
        myGLCD.setColor(255, 0, 255);
        break;
      case 2:
        myGLCD.setColor(255, 0, 0);
        break;
      case 3:
        myGLCD.setColor(0, 255, 0);
        break;
      case 4:
        myGLCD.setColor(0, 0, 255);
        break;
      case 5:
        myGLCD.setColor(255, 255, 0);
        break;
    }
    myGLCD.fillCircle(100 + (i * 20), 60 + (i * 20), 30);
  }

  delay(2000);

  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(1, 15, 318, 224);

}
