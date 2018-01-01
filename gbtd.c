#include <gb/gb.h>
#include <stdio.h>
#include <rand.h>

#include "background.tiles"
#include "objects.tiles"
#include "lanes.map"

#include "towers.c"
#include "cursor.c"

void init() {
  cursor_init();
}

void update() {
  cursor_update();
  delay(10);
}


void main() {
  SPRITES_8x16;

  set_sprite_data(0, 24, objects);
  set_bkg_data(0, 40, background);

  VBK_REG = 1;
  VBK_REG = 0;

  set_bkg_tiles(0, 0, 17, 30, lanes);
  
  init();

  SHOW_SPRITES;   
  SHOW_BKG;
  DISPLAY_ON;
  
  while(1) {
	update();
  }
}
