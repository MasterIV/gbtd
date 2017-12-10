#include <gb/gb.h>
#include <stdio.h>
#include "foo.c"

void main() {
    printf("Hello World!");
    printf("\n\nPress Start");

    SPRITES_8x8;
    set_sprite_data(0, 8, foo);
    set_sprite_tile(0, 0);
    move_sprite(0, 75, 75);
    SHOW_SPRITES;
}
