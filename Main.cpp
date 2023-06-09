#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
using namespace std;
const int ROW = 5;
const int COl = 5;
int main()
{
    std::string USER_NAME;
    int visible[ROW][COL];
    int hidden[ROW][COL];
    int LOWER_BOUND;
    int UPPER_BOUND;
    int LOWER_HIDDEN;
    int UPPER_HIDDEN;
    initialize(LOWER_BOUND , UPPER_BOUND , LOWER_HIDDEN , UPPER_HIDDEN , hidden , visible);
    
    USER_NAME = GET_NAME(USER_NAME);
    std::cout << USER_NAME << "\n";
    // Print the contents of the matrices for testing purposes
    std::cout << "Visible matrix:\n";
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            std::cout << visible[i][j] << " ";
        }
        std::cout << "\n";
    }

   std::cout << "Hidden matrix:\n";
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            std::cout << hidden[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
