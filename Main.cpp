#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
using namespace std;
int main()
{
    std::string USER_NAME;
    int visible[10][10];
    int hidden[10][10];
    genShowMatrix(visible);
    genHideMatrix(hidden, 1, 10);
    
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