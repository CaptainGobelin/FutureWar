#ifndef CONST_H
#define CONST_H

//Paths
#define OPTION_PATH "usr/ini.txt"
#define TEXTURES_PATH "dat/"
#define SAVE_PATH "usr/sav/"
#define FONT_PATH "dat/font/"

//Window
#define L_WINDOW 512
#define H_WINDOW 360
#define GRID_X 21
#define GRID_Y 14
#define CELL_SIZE 24
#define SPRITE_SIZE 24
#define WINDOW_NAME "Super Future War"

//Animations
#define CAMERA_SPEED 6
#define UNITS_SPEED 5

//States
#define NORMAL_STATE 0
#define REFRESH_STATE 1
#define MOVE_STATE 2
#define ATTACK_STATE 3

//Inputs
#define NO_INPUT -1
#define INVALID_INPUT 0
#define CLOSE_INPUT 1
#define ANY_KEY_INPUT 2
#define UP_INPUT 3
#define DOWN_INPUT 4
#define LEFT_INPUT 5
#define RIGHT_INPUT 6
#define M_INPUT 7
#define ENTER_INPUT 8
#define ESCAPE_INPUT 9
#define DELETE_INPUT 10
#define Q_INPUT 11
#define Y_INPUT 12
#define N_INPUT 13
#define I_INPUT 14
#define P_INPUT 15
#define LEFT_CLICK_INPUT 16
#define RIGHT_CLICK_INPUT 17

//Menu inputs
#define INIT_CHOICE 10
#define TO_SESSION 11
#define TO_MAIN_MENU 12
#define TO_GAME_SESSION 13
#define TO_CONTINUE 14
#define REDO 15

//Messages
#define MESS_LINES 21
#define MESS_SPACE 11
#define MESS_X 30
#define MESS_Y 138

//Armies
#define HJMU_ARMY 0
#define MECHA_ARMY 1

//Units
#define HJMU_SOLDIER_UNIT 0
#define HJMU_HEAVY_UNIT 1
#define MECHS_SOLDIER_UNIT 1000
#define MECHS_HEAVY_UNIT 1001
#define FEDS_SOLDIER_UNIT 2000
#define FEDS_HEAVY_UNIT 2001

//Graphic Layers
#define BACKGROUND_LAYER 1
#define SUB_UNIT_LAYER 2
#define UNITS_LAYER 3
#define EFFECTS_LAYER 4
#define INTERFACE_LAYER 5

//Save File
#define END_OF_FILE -99999

#endif