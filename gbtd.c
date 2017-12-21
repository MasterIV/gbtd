#include <gb/gb.h>
#include <stdio.h>

#include "background.tiles"
#include "lanes.map"

int xpos;
int dir;
int i;

void main() {
    printf("Hello Roman!");
    printf("\n\nPress Start");
    printf("\n\n\n\n\n\n\nKilroy was here.");

    SPRITES_8x16;
    set_sprite_data(0, 10, background);
  
  	for(i =0; i < 1; i++)
    	set_sprite_tile(i, i);
  
    move_sprite(0, 75, 75);
  
  
    SHOW_SPRITES;

    xpos = 75; 
    dir = 1; 

    while(1) {
        move_sprite(0, xpos, 75);
  		set_sprite_prop(0, xpos > 75 ? S_PALETTE : 0 );

        if(dir==1) {
            xpos += 1;
            if(xpos>110) dir = 0;
        } else {
            xpos -= 1;
            if(xpos<40) dir = 1;
        }

        delay(10);
    }
}
