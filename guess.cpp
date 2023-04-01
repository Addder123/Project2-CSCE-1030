void(int MATRIX[][COL] , int HIDDEN_MATRIX[][COL] , int SHOW_LEFT , int SHOW_RIGHT , int& LIFE_POINTS){
    int guess;
    bool CHECK = false;
    std::cout << "Please enter a number: ";
    std::cin >> guess; 
    

for(int i = 0 ; i < ROW ; ++i){
        for(int j = 0 ; j < COL ; ++j){
            if(MATRIX[i][j] == guess){
                std::cout << "Good job! " << guess << " was correct!\n"; 
                ELIM_ROW = i;
                ELIM_COL = j;
                ELIMINATE(MATRIX , HIDDEN_MATRIX , ELIM_ROW , ELIM_COL);
                if(SHOW_LEFT == -1 || SHOW_RIGHT == -1){
                    LIFE_POINTS += 5;
                }
                else{
                    LIFE_POINTS +=1;
                }
                std::cout << "You earn " << LIFE_POINTS << " points\n";
                CHECK = TRUE;
            }
        }
    }
    if(GUESS == false){
        
        if(SHOW_LEFT == -1 || SHOW_RIGHT == -1){
            LIFE_POINTS -= 5;
        }else{
            LIFE_POINTS -= 10;
        }
        std::cout << "Sorry that was not the right answer you lose " << LIFE_POINTS << ".\n";
    }

}