#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
using namespace std;
void genHideMatrix(int hidden[][10], int lower, int upper) {
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            hidden[i][j] = rand() % (upper - lower + 1) + lower;
        }
    }
}
