#include <gb/gb.h>
#include <stdio.h>
#include "TileGame.h"
#include "MapGame.h"

uint32_t count;
uint32_t oldcount;

uint8_t enemyX[10];
uint8_t collisionSword();

uint8_t collisionSword(){ //collision detection with sword
     for(uint8_t i = 1; i <= 10; i++){
         if((enemyX[i] <= 77) || (enemyX[i] >= 98)){
             return 0;
         } else{
         return 1;
         }
     }  
}

void main(){
    set_bkg_data(0, 22, StickTiles);
    set_bkg_tiles(0, 0, StickMapWidth, StickMapHeight, StickMap);
    move_bkg(10, 0);

    set_sprite_data(0, 5, StickTiles);
    set_sprite_tile(0, 1); //main character
    set_sprite_tile(1, 0); //blank for sword
    
    set_sprite_tile(2, 2); //enemy 1
    set_sprite_tile(3, 2); //enemy 2
    
    move_sprite(0, 84, 96); //move main character
    move_sprite(1, 91, 96); //move sword
    //move_sprite(2, 162, 96); //move enemy 1 off-screen
    //move_sprite(3, 1, 96); //move enemy 2 off-screen

    enemyX[1] = 162;


    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    while(1){
        if(collisionSword() == 1){
            enemyX[1] = 170;
        }
        
        move_sprite(2, enemyX[1], 96);
        
        switch(joypad()){
            case 0x02U: //go left
                scroll_bkg(-1, 0);
                set_sprite_prop(0, S_FLIPX);
                set_sprite_tile(1, 0);
            break;
            
            case 0x01U: //go right
                enemyX[1] = enemyX[1] - 2;
                scroll_bkg(1, 0);
                set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
                set_sprite_tile(1, 0);
            break;

            case 0x20U: //get sword
                enemyX[1]--;
                set_sprite_tile(1, 4);
            break;

            case 0x02U + 0x20U:
                scroll_bkg(-1, 0);
                set_sprite_prop(0, S_FLIPX);
                set_sprite_tile(1, 4);
            break;
            
            case 0x01U + 0x20U:
                enemyX[1] = enemyX[1] - 2;
                scroll_bkg(1, 0);
                set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
                set_sprite_tile(1, 4);
            break;

            default:
            enemyX[1]--;
            set_sprite_tile(1, 0);
            break;
        }
       
        delay(50);
        //count++;
    }
}