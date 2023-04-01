void Initialize(int& LOWER_BOUND , int& UPPER_BOUND , int& HIDDEN_1 , int& HIDDEN_2 , int HIDDEN_MATRIX[][COL] , int VISIBLE_MATRIX[][COL]){
    srand(time(NULL));
    HIDDEN_1 = -1;
    HIDDEN_2 = -1;
    LOWER_BOUND = 100 + std::rand() % (199 - 100) + 1;
    UPPER_BOUND = 200 + std::rand() % (299 - 200) + 1;
    genHideMatrix(HIDDEN_MATRIX , LOWER_BOUND , UPPER_BOUND);
    genShowMatrix(VISIBLE_MATRIX);
}