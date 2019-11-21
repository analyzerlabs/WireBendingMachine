#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#include "variables.h"
#include <UTFTGLUE.h>              //use GLUE class and constructor
UTFTGLUE myGLCD(0, A2, A1, A3, A4, A0);
class knob {
    private:
        float R  ;
        float r  ;
        int C[3] = {0,0,0};
        int S = 1;
        int posx,posy;
        int w=320,h=240;
    public:
        knob::knob(int x, int y, int size,int col[]){
            for(int i=0;i<3;i++)this->C[i] = col[i];
            this->S = size;
            this->posx = x;
            this->posy = y;
            this->R = 1.0*S/100*(this->w+this->h)/20;
            this->r = 1.0*S/100*(this->w+this->h)/100;
            init();
        }
        void knob::fill(byte c[]){
            myGLCD.setColor(c[1],c[2],c[3]);
        }
        void knob::text(String p, int x, int y){
            myGLCD.print(p, x, y);
        }
        void knob::tohex(byte color[]){
            byte R=color[0], G=color[1], B=color[2];
            long RGB = ((long)R << 16L) | ((long)G << 8L) | (long)B;
            return RGB;
          }
        void knob::init(){
            fill(lineButton);
            myGLCD.fillCircle(this->posx, this->posy, 2*this->R+5,tohex(lineButton));
            fill(fondoPrincipal);
            myGLCD.fillCircle(this->posx, this->posy, 2*this->R-5,tohex(lineButton));
            fill(letraSecundaria);
            textSize(smallLetters);
            text("REMAINING", posx, posy+2*smallLetters);
        }
        
        void knob::move(int value){
            init();
            float aux=93; 
            for (float i=0; i<value*2*PI/100; i=i+(PI/360)) {
              ellipse(posx-R*cos(-(i+PI/2)), posy+R*sin(-(i+PI/2)), r, r);
              aux=aux+0.4;
              color C2 = C + color(0,int(aux/3),0); 
              fill(C2);
              stroke(C2);
            }
            stroke(white);
            fill(white);
            textAlign(CENTER, CENTER);
            textSize(bigLetters);
            text(str(value)+"%", posx, posy-smallLetters);
        }
        void knob::set(int value, int max) {
        
        }
};
