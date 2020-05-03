#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

/** Initializes everything, clears the screen, draws "hello" and a square */
int main() {
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  clearScreen(COLOR_BLACK);

  drawCube();
  drawSquare(96,40);
  drawTriangle(96,100);
  drawDiamond(32,120);
}

void drawCube() {
  for(int i = 0; i < 40; i++) {
    for(int j = 0; j < 40; j++) {
      if(i < 20) drawPixel(11+j+i,29-i,COLOR_RED);//Top
      if(i < 20) drawPixel(50+i,69-i-j,COLOR_GREEN);//Side
      drawPixel(10+i,30+j,COLOR_BLUE);//Front
    }
  }
}
void drawSquare(int x, int y) {
  for(int i = 0; i < 40; i++) {
    for(int j = 0; j < 40; j++) { 
      drawPixel((x-20)+i,(y-20)+j,COLOR_PINK); 
    }
  }
}
void drawTriangle(int x, int y) {
  static int k = 0;
  for(int i = 0; i < 40; i++) {
    if(i != 0 && i % 2 == 0) k++;
    for(int j = 0; j < i; j++) {
      drawPixel(x-k+j,y+i,COLOR_GREEN); 
    }
  }
}
void drawDiamond(int x, int y) {
  for(int i = 0; i < 20; i++) {
    for(int j = 0; j < i; j++) {
      drawPixel(x+i-j,(y-20)+i,COLOR_RED);
      drawPixel(x-i+j,(y+20)-i,COLOR_RED); 
     drawPixel((x-20)+i,y-i+j,COLOR_RED);
     drawPixel((x+20)-i,y+i-j,COLOR_RED);
    }
  }
}
