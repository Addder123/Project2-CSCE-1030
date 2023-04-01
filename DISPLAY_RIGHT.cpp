#include "project2_header.h"

int DISPLAY_RIGHT(int matrix[][COL], int DISPLAY_RIGHT , int UPPER_BOUND)//will need to call hidden matrix
{
    int UPPER_BOUND = matrix[0][0];
    for(int i = 0; i < ROW ; ++i ){
        for(int j = 0 ; j < COL ; ++j){
            if(UPPER_BOUND < matrix[i][j]){
                UPPER_BOUND = matrix[i][j];
            }
        }
    }
    DISPLAY_RIGHT = UPPER_BOUND;
    return DISPLAY_RIGHT;
}