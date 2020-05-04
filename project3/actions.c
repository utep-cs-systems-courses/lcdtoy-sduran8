#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "buzzer.h"
#include "led.h"

static int shape = 0; //Square = 0, Triangle = 1, Diamond = 2
static int color = 0; //RED = 0, BLUE = 1, YELLOW = 2

void changeShape() {
  buzzer_set_period(1000);
  switch(shape) {
  case 0: clearScreen(COLOR_BLACK); drawSquare(64,80,COLOR_WHITE); shape++; break;
  case 1: clearScreen(COLOR_BLACK); drawTriangle(64,80,COLOR_WHITE); shape++; break;
  case 2: clearScreen(COLOR_BLACK); drawDiamond(64,80,COLOR_WHITE); shape = 0; break;
  }
}
void changeColor() {
  buzzer_set_period(750);
  for(;;) {
    //The method for identicating shapes is the shapes # + 1
    //Ex: Square = 0, so 1 identifies square 
    if(shape == 1) {
      if(color == 0) {drawSquare(64,80,COLOR_RED); color++; break;}
      if(color == 1) {drawSquare(64,80,COLOR_BLUE); color++; break;}
      if(color == 2) {drawSquare(64,80,COLOR_YELLOW); color = 0; break;}
    }
    if(shape == 2) {
      if(color == 0) {drawTriangle(64,80,COLOR_RED); color++; break;}
      if(color == 1) {drawTriangle(64,80,COLOR_BLUE); color++; break;}
      if(color == 2) {drawTriangle(64,80,COLOR_YELLOW); color = 0; break;}
    }
    if(shape == 0) {
      if(color == 0) {drawDiamond(64,80,COLOR_RED); color++; break;}
      if(color == 1) {drawDiamond(64,80,COLOR_BLUE); color++; break;}
      if(color == 2) {drawDiamond(64,80,COLOR_YELLOW); color = 0; break;}
    }
  }
  toggle_green();
}
void mirrorShape() {
  buzzer_set_period(500);
  //For the method the identiication of shapes is the shapes # + 1
  switch(shape) {
  case 1: drawSquare(64,40,COLOR_WHITE); drawSquare(64,120,COLOR_WHITE); drawSquare(24,80,COLOR_WHITE); drawSquare(104,80,COLOR_WHITE); break;
  case 2: drawTriangle(64,40,COLOR_WHITE); drawTriangle(64,120,COLOR_WHITE); drawTriangle(24,80,COLOR_WHITE); drawTriangle(104,80,COLOR_WHITE); break;
  case 0: drawDiamond(64,40,COLOR_WHITE); drawDiamond(64,120,COLOR_WHITE); drawDiamond(24,80,COLOR_WHITE); drawDiamond(104,80,COLOR_WHITE); break;
  }
}
void shutOff() {
  clearScreen(COLOR_BLACK);
  drawString5x7(20,40,"Shutting Down...",COLOR_GREEN,COLOR_BLACK);
  drawCube(32,100);
  r_on();
  or_sr(0x18); //Shut off CPU
}
