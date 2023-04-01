#include "project2_header.h"

int DISPLAY_LEFT(int matrix[][COL], int DISPLAY_LEFT , int LOWER_BOUND)//will need to call hidden matrix
{
    DISPLAY_LEFT = LOWER_BOUND;
    for(int i = 0; i < ROW ; ++i ){
        for(int j = 0 ; j < COL ; ++j){
            if(LOWER_BOUND > matrix[i][j]){
                LOWER_BOUND = matrix[i][j];
            }
        }
    }
    DISPLAY_LEFT = LOWER_BOUND;
    return DISPLAY_LEFT;
}
