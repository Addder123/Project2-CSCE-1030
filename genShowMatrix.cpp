#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
using namespace std;
void genShowMatrix(int visible[][10]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            visible[i][j] = -1;
        }
    }
}
