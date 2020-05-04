#include <msp430.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"


void main(void) {
  g_on();
  configureClocks();
  switch_init();
  buzzer_init();
  lcd_init();
  led_init();
  
  clearScreen(COLOR_BLACK);
  drawString5x7(44,30,"Welcome",COLOR_GREEN,COLOR_BLACK);
  drawString5x7(47,40,"to the",COLOR_GREEN,COLOR_BLACK);
  drawString5x7(34,50,"Simulation",COLOR_GREEN,COLOR_BLACK);

  enableWDTInterrupts();
  or_sr(0x18);
} 
