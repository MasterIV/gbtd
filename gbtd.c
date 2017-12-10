#include <gb/gb.h>
#include <stdio.h>
#include "foo.c"

int xpos;
int dir;

void main() {
    printf("Hello World!");
    printf("\n\nPress Start");

    SPRITES_8x8;
    set_sprite_data(0, 8, foo);
    set_sprite_tile(0, 0);
    move_sprite(0, 75, 75);
    SHOW_SPRITES;

    xpos = 75;
    dir = 1;

    while(1) {
        move_sprite(0, xpos, 75);

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
