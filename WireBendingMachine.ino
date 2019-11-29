#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
#include <TouchScreen.h>
#define MINPRESSURE 200
#define MAXPRESSURE 1000
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>

#include <FreeDefaultFonts.h>

#define BLACK   0x001F
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define fondoPrincipal 0xFFFFFF

// ALL Touch panels and wiring is DIFFERENT
// copy-paste results from TouchScreen_Calibr_native.ino

const int XP = 7, YP = A2, XM = A1, YM = 6; //ID=0x9341
const int TS_LEFT = 969, TS_RT = 156, TS_TOP = 885, TS_BOT = 153;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

Adafruit_GFX_Button on_btn, off_btn;

int pixel_x, pixel_y;     //Touch_getXY() updates global vars
bool Touch_getXY(void)
{
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
        pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
    }
    return pressed;
}



void setup(void)
{
    Serial.begin(9600);
    uint16_t ID = tft.readID();
    Serial.print("TFT ID = 0x");
    Serial.println(ID, HEX);
    Serial.println("Calibrate for your Touch Panel");
    if (ID == 0xD3D3) ID = 0x9486; // write-only shield
    tft.begin(ID);
    tft.setRotation(0);            //
    tft.fillScreen(BLACK);
    on_btn.initButton(&tft,   60 , 250 , 100, 40, WHITE , CYAN, BLACK, "INICIAR",  2);
    off_btn.initButton(&tft, 180 , 250 , 100, 40, WHITE , CYAN, BLACK, "OFF", 2);
    on_btn.drawButton(false);
    off_btn.drawButton(false);
    tft.drawCircle(40, 40, 20, RED);
    knob(40,40,1);
    showmsgXY(5, 290, 1, &FreeSans9pt7b, " WIRE  BENDING  MACHINE !");
}
void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg)
{
    int16_t x1, y1;
    uint16_t wid, ht;
    tft.drawFastHLine(0, y, tft.width(), WHITE);
    tft.setFont(f);
    tft.setCursor(x, y);
    tft.setTextColor(GREEN);
    tft.setTextSize(sz);
    tft.print(msg);
    delay(1000);
}

void knob(int posx,int posy, int size){
     tft.drawCircle(posx, posy, 40, MAGENTA);
  }

/* two buttons are quite simple
 */
void loop(void)
{
    bool down = Touch_getXY();
    on_btn.press(down && on_btn.contains(pixel_x, pixel_y));
    off_btn.press(down && off_btn.contains(pixel_x, pixel_y));
    
    if (on_btn.justReleased())
        on_btn.drawButton();
        
    if (off_btn.justReleased())
        off_btn.drawButton();
        
    if (on_btn.justPressed()) {
        on_btn.drawButton(true);
        tft.fillCircle(40, 40, 20, GREEN);
    }
    if (off_btn.justPressed()) {
        off_btn.drawButton(true);
        tft.fillCircle(40, 40, 20, RED);
    }

}
