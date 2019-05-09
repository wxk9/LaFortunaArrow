//
//  game.c
//  tasks
//
//  Created by Wenxin Liu on 28/04/2019.
//  Copyright © 2019 Wenxin Liu. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "rios.h"
#include "ruota.h"
#include "os.h"

int check_switches(int);
void setNum(int*);
void buttonTrack(char*);
void startGame(void);
void displayString(int);

char direction[5];
int score = 0;

int main(void) {
    os_init();
    startGame();

    return 0;
}


void startGame(){
    int result = (rand() % 4) + 1;
    
    char snum[255];
    
    while(1){
        //show direction
        setNum(&result);
        displayString(result);
        _delay_ms(1000);
        buttonTrack(direction);
        
        //show score
        clear_screen();
        itoa(score, snum, 10);
        display_string_xy(snum, 10, 10);
        _delay_ms(500);

        clear_screen();
        display_string_xy(snum, 10, 10);
        
        if(score < -2){
            clear_screen();
            display_string_xy("YOU LOSE", LCDHEIGHT/2-20, LCDWIDTH/2);
            display_string_xy(snum, LCDHEIGHT/2, LCDWIDTH/2+10);
//            _delay_ms(1000);
            break;
        }
        if(score > 3){
            display_string_xy("SCORING", LCDHEIGHT/2-10, LCDWIDTH/2);
            _delay_ms(1000);
            clear_screen();
            display_string_xy(snum, 10, 10);
        }
    }
}

//change number
void setNum(int* numToChange){
    *numToChange = (rand() % 4) + 1;
}

/*
    1 = North
    2 = South
    3 = East
    4 = West
 */
void displayString(int num){
    switch (num) {
        case 1:
            strcpy(direction, "NORTH");
            break;
        case 2:
            strcpy(direction, "SOUTH");
            break;
        case 3:
            strcpy(direction, "EAST");
            break;
        case 4:
            strcpy(direction, "WEST");
            break;
        default:
            break;
    }

    display_string_xy(direction, LCDHEIGHT/2-10, LCDWIDTH/2);
}

void buttonTrack(char dir[]){

    if (get_switch_press(_BV(SWN)) && strcmp(dir, "NORTH") == 0) {
        score++;
    }

    else if (get_switch_press(_BV(SWE)) && strcmp(dir, "EAST") == 0) {
        score++;
    }

    else if (get_switch_press(_BV(SWS)) && strcmp(dir, "SOUTH") == 0) {
        score++;
    }

    else if (get_switch_press(_BV(SWW)) && strcmp(dir, "WEST") == 0) {
        score++;
    }
    else{
        score--;
    }
}
