UBYTE joypad_prev;

struct Cursor {
  unsigned char lane;
  unsigned char row;
} cursor;

void cursor_update() {
  UBYTE keys, diff;
  int cx, cy;
  
  keys = joypad();
  if(keys != joypad_prev) {
	diff = ( joypad_prev ^ keys ) & keys;
	joypad_prev = keys;
	
	switch(diff) {
	  case J_UP: if(cursor.row > 0) cursor.row--; break;
	  case J_DOWN: if(cursor.row < 9) cursor.row++; break;
	  case J_LEFT: if(cursor.lane > 0) cursor.lane--; break;
	  case J_RIGHT: if(cursor.lane < 4) cursor.lane++; break;
	  case J_A: tower_place(cursor.lane, cursor.row); break;
	}

	cx = 16 + cursor.lane * 24;
	cy = 16 + cursor.row * 24;

	move_sprite(0, cx, cy);
	move_sprite(1, cx+16, cy);
	move_sprite(2, cx, cy+8);
	move_sprite(3, cx+16, cy+8);
  }
}

void cursor_init() {
  cursor.lane = 0;
  cursor.row = 0;
  
  set_sprite_tile(0, 2);
  set_sprite_tile(1, 2);
  set_sprite_tile(2, 2);
  set_sprite_tile(3, 2);
  
  set_sprite_prop(1, S_FLIPX);
  set_sprite_prop(2, S_FLIPY);
  set_sprite_prop(3, S_FLIPX | S_FLIPY);
  
  joypad_prev = 1;
  cursor_update();
}
