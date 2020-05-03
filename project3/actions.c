#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "buzzer.h"



void action1() {
  buzzer_set_period(1000);
  drawSquare(64,120);
  //r_on();
}
void action2() {
  buzzer_set_period(750);
  drawTriangle(64,120);
  //g_on();
}
void action3() {
  buzzer_set_period(500);
  drawDiamond(64,120);
  //both_on();
}
void action4() {
  main();
}
