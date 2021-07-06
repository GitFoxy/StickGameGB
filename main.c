#include <gb/gb.h>
#include <stdio.h>
#include "TileGame.h"
#include "MapGame.h"

uint8_t count;
uint8_t oldcount;

void main(){
    set_bkg_data(0, 22, StickTiles);
    set_bkg_tiles(0, 0, StickMapWidth, StickMapHeight, StickMap);

    set_sprite_data(0, 5, StickTiles);
    set_sprite_tile(0, 1);
    //set_sprite_tile(1, 4);
    move_sprite(0, 84, 96);
    move_sprite(1, 91, 96);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    while(1){
        switch(joypad()){
            case 0x02U:
                scroll_bkg(-1, 0);
                set_sprite_prop(0, S_FLIPX);
                set_sprite_tile(1, 0);
            break;
            
            case 0x01U:
                scroll_bkg(1, 0);
                set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
                set_sprite_tile(1, 0);
            break;

            case 0x20U:
                set_sprite_tile(1, 4);
            break;

            case 0x02U + 0x20U:
                scroll_bkg(-1, 0);
                set_sprite_prop(0, S_FLIPX);
                set_sprite_tile(1, 4);
            break;
            
            case 0x01U + 0x20U:
                scroll_bkg(1, 0);
                set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
                set_sprite_tile(1, 4);
            break;

            default:
            set_sprite_tile(1, 0);
            break;
        }
       
        delay(100);
    }
}