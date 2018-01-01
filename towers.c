unsigned char tower_index;

void tower_place(unsigned char lane, unsigned char row) {
  int offset, i;

  if(tower_index < 3 || tower_index > 30 )
  	tower_index = 3;
  
  offset = row * 51 + lane * 3 + 1;
  
  for(i = 0; i <9; i++)
  	lanes[offset+(i%3)+(i/3)*17] = tower_index+i;
  
  set_bkg_tiles(0, 0, 17, 30, lanes);
  tower_index += 9;
}
