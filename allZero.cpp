bool allZero(int MATRIX[][COL]){
    bool ZERO = true;
    for(int i = 0 ; i < ROW ; ++i){
        for(int j = 0 ; j < COL ; ++j){
            if(MATRIX[i][j] != 0){
                ZERO = false;
            }
        }
    }
    return ZERO;
}