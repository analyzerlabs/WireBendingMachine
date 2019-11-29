#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
             //use GLUE class and constructor

UTFTGLUE myGLCD(0, A2, A1, A3, A4, A0);

int R  ;
int r  ;
int C[3] = {0,0,0};
int S = 1;
int posx,posy;
int w=320,h=240;

void knobFill(byte c[]){
            myGLCD.setColor(c[1],c[2],c[3]);
}

void knobInit(){
  
            knobFill(lineButton);
            myGLCD.fillCircle(1, 1, 1,RED);
            knobFill(fondoPrincipal);
            myGLCD.fillCircle(posx, posy, 2*R-5,CYAN);
            knobFill(letraSecundaria);
            textSize(smallLetters);
            text("REMAINING", posx, posy+2*smallLetters);
}

void knob(int x, int y, int size,int col[]){
            for(int i=0;i<3;i++)C[i] = col[i];
            S = size;
            posx = x;
            posy = y;
            R = 1.0*S/100*(w+h)/20;
            r = 1.0*S/100*(w+h)/100;
            knobInit();
        }
        

        
void knobText(String p, int x, int y){
            myGLCD.print(p, x, y);
}

int tohex(byte color[]){
            byte R=color[0], G=color[1], B=color[2];
            long RGB = ((long)R << 16L) | ((long)G << 8L) | (long)B;
            return RGB;
}

        
void knobMove(int value){
            init();
            float aux=93; 
            for (float i=0; i<value*2*PI/100; i=i+(PI/360)) {
              ellipse(posx-R*cos(-(i+PI/2)), posy+R*sin(-(i+PI/2)), r, r);
              aux=aux+0.4;
              color C2 = C + color(0,int(aux/3),0); 
              knobFill(C2);
              stroke(C2);
            }
            stroke(white);
            knobFill(white);
            textAlign(CENTER, CENTER);
            textSize(bigLetters);
            text(str(value)+"%", posx, posy-smallLetters);
}

void knobset(int value, int max) {
        
}
