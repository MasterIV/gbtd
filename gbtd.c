#include <gb/gb.h>
#include <stdio.h>
#include <rand.h>

#include "background.tiles"
#include "objects.tiles"
#include "lanes.map"


void main() {
  	unsigned int ypos, xpos;
  
    SPRITES_8x16;
  
    set_sprite_data(0, 24, objects);
  	set_bkg_data(0, 20, background);
  
    VBK_REG = 1;
	VBK_REG = 0;
  
	set_bkg_tiles(0, 0, 17, 30, lanes);
  
    set_sprite_tile(0, 4);
    move_sprite(0, 75, 160);
  
    SHOW_SPRITES;   
  	SHOW_BKG;
  	DISPLAY_ON;
  
    ypos = 160;
  	xpos = 75;

    while(1) {
        move_sprite(0, xpos, ypos -= 1);

        if(ypos < 1) {
		  	xpos = rand();
		  	if( xpos < 16 ) xpos = 16;
		  	if( xpos > 120 ) xpos = 120;
    		ypos = 160;
        }

        delay(10);
    }
}
