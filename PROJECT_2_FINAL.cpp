#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
#include <string>
#include <limits>

using namespace std;
const int ROW = 5;
const int COL = 5;
enum selection{disLeft = 1 , disRight , GUESS , cheat , change , leave };
selection CHOICE;


std::string GET_NAME(std::string& USER_NAME)
{
    int ALPHA = 1;

do
{
std::cout << "Please enter UserName: \n";
getline (std::cin , USER_NAME);


for ( int i = 0 ; i < USER_NAME.length() ; i++ )
{
    ALPHA = 1;
    if (!isalpha(USER_NAME.at(i)) && !isspace(USER_NAME.at(i)) ) 
    //this is for checking if there are only spaces or alphabetical characters ommiting digits and symbols
    {
    ALPHA = 0;
    std::cout << "Please enter only alphabetical characters\n";
    break;
    }

}
}while(ALPHA == 0);

/*This portion will check if the first letters after a space are uppercase 
and the following letters are lowercase*/
int last = ' ';
for (int i= 0; i < USER_NAME.length(); i++){

if(last == ' ' && (USER_NAME.at(i) != ' ') && isalpha(USER_NAME.at(i)))
{
    USER_NAME.at(i) = ::toupper(USER_NAME.at(i));
last = USER_NAME.at(i);
}
else {
   USER_NAME.at(i) = ::tolower(USER_NAME.at(i)); 
   last = USER_NAME.at(i);
}

}

std::cout << "Welcome: " << USER_NAME << "\n";

return USER_NAME;
}

void genShowMatrix(int visible[][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            visible[i][j] = -1;
        }
    }
}

void genHideMatrix(int hidden[][COL], int lower, int upper) {
    srand(time(NULL));
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            hidden[i][j] = rand() % (upper - lower + 1) + lower;
        }
    }
}

void showMatrix( int array[][COL])
{
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			cout << array[i][j] << "\t";
		}
        std::cout << "\n";
	}

	cout << endl;
}

void cheatMatrix(int HIDDEN_MATRIX[][COL]){
    for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COL; ++j)
		{
			cout << HIDDEN_MATRIX[i][j] << "\t";
		}
        std::cout << "\n";
	}

	cout << endl;
}

int DISPLAY_RIGHT(int DISPLAY_RIGHT , int UPPER_BOUND , int DISPLAY_LEFT){
  if(DISPLAY_LEFT == -1){
   DISPLAY_RIGHT = UPPER_BOUND; 
   std::cout << "You will now earn only 1 point and can lose 10 points\n";
  }
    else{
        std::cout << "You can't do that cheater!\n\n";
    }
    return DISPLAY_RIGHT;
}

void DISPLAY_LEFT(int& DISPLAY_LEFT , int LOWER_BOUND , int DISPLAY_RIGHT){
    if(DISPLAY_RIGHT == -1){
   DISPLAY_LEFT = LOWER_BOUND; 
   std::cout << "You will now earn only 1 point and can lose 10 points\n";
  }
    else{
        std::cout << "You can't do that cheater!\n\n";
    }
}

void eliminate(int array[][COL], int hidden_array[][COL], int rowIn, int colIn)
{
	bool check = false;

	if(!(check = false))
	{
		for(int i = 0; i < ROW; ++i)
		{
			for(int j = 0; j < COL; ++j)
			{

				array[i][colIn] = 0;
				array[rowIn][j] = 0;
				hidden_array[rowIn][j] = 0;
				hidden_array[i][colIn] = 0;
			}
		}
	}
	cout << endl;
}

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

void guess(int VISIBLE_MATRIX[][COL] , int HIDDEN_MATRIX[][COL] , int SHOW_LEFT , int SHOW_RIGHT , int& LIFE_POINTS){
    int guess;
    int ELIM_ROW;
    int ELIM_COL;
    int POINT_MOD;
    bool CHECK = false;
    std::cout << "Please enter a number: ";
    std::cin >> guess; 
     std::cout << "+_____________________________________________________________+\n";

for(int i = 0 ; i < ROW ; ++i){
        for(int j = 0 ; j < COL ; ++j){
            if(HIDDEN_MATRIX[i][j] == guess){
                std::cout << "Good job! " << guess << " was correct!\n"; 
                ELIM_ROW = i;
                ELIM_COL = j;
                eliminate(VISIBLE_MATRIX , HIDDEN_MATRIX , ELIM_ROW , ELIM_COL);
                if(SHOW_LEFT == -1 && SHOW_RIGHT == -1){
                    POINT_MOD = 5;
                    LIFE_POINTS += POINT_MOD;
                }
                else{
                    POINT_MOD = 1;
                    LIFE_POINTS += POINT_MOD;
                }
                std::cout << "You earn " << POINT_MOD << " points\n";
                CHECK = true;
            }
        }
    }
    if(CHECK == false){
        
        if(SHOW_LEFT == -1 && SHOW_RIGHT == -1){
            POINT_MOD = 5;
            LIFE_POINTS -= POINT_MOD;

        }else{
            POINT_MOD = 10;
            LIFE_POINTS -= POINT_MOD;
        }
        std::cout << "Sorry that was not the right answer you lose " << POINT_MOD << " Life points.\n";
    }

}

void Initialize(int& LOWER_BOUND , int& UPPER_BOUND , int& HIDDEN_1 , int& HIDDEN_2 , int HIDDEN_MATRIX[][COL] , int VISIBLE_MATRIX[][COL]){
    srand(time(NULL));
    HIDDEN_1 = -1;
    HIDDEN_2 = -1;
    LOWER_BOUND = 100 + std::rand() % (199 - 100) + 1;
    UPPER_BOUND = 200 + std::rand() % (299 - 200) + 1;
    genHideMatrix(HIDDEN_MATRIX , LOWER_BOUND , UPPER_BOUND);
    genShowMatrix(VISIBLE_MATRIX);
}

int main(){
    int LIFE_POINTS = 100;
    int HIDDEN_MATRIX[ROW][COL];
    int VISIBLE_MATRIX[ROW][COL];
    int UPPER_BOUND;
    int LOWER_BOUND;
    int UPPER_HIDDEN;
    int LOWER_HIDDEN;
    int CHOICE;
    bool EXIT_FUNC;
    std::string USER_NAME;
    char EXIT_CHOICE;

    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|           COMPUTER SCIENCE AND ENGINEERING            |\n";
    std::cout << "|            CSCE 1030 - COMPUTER SCIENCE 1             |\n";
    std::cout << "|        DYLAN MCNULTY DPM0130 dpm0130@my.unt.edu       |\n";
    std::cout << "|        JOEL HUNT     JH1249  jh1249@my.unt.edu        |\n";
    std::cout << "|        RADHIKA OAD   RO0164  ro0164@my.unt.edu        |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  Please read: Your goal is to guess a number in the   |\n";
    std::cout << "|  box, you are given choices to show lower and upper   |\n";
    std::cout << "|  bounds of the boxes and what they can be , the max   |\n";
    std::cout << "|  bounds of the array are from 100 to 299. guessing    |\n";
    std::cout << "|  will turn all numbers of the same column and row     |\n";
    std::cout << "|  of the number to 0 your goal is to reach all 0 and   |\n";
    std::cout << "|           avoid reaching zero life points             |\n";
    std::cout << "+-------------------------------------------------------+\n";
    Initialize(LOWER_BOUND, UPPER_BOUND , LOWER_HIDDEN , UPPER_HIDDEN , HIDDEN_MATRIX , VISIBLE_MATRIX);
    GET_NAME(USER_NAME);
    do{
        showMatrix(VISIBLE_MATRIX);
        
        std::cout << "+_____________________________________________________________+\n";
        std::cout << " Lower bound: " << LOWER_HIDDEN << "\t Upper bound: " << UPPER_HIDDEN << "\n";
        std::cout << "you have " << LIFE_POINTS << " life points\n What would you like to do?\n";
        std::cout << " 1. Display Left \n 2. Display Right \n 3. Guess \n 4. Cheat (dev tool) \n 5. Change \n 6. Exit \n";
        std::cin >> CHOICE;
        std::cout << "+_____________________________________________________________+\n\n\n";
        switch(CHOICE){
            case disLeft:
                DISPLAY_LEFT( LOWER_HIDDEN , LOWER_BOUND , UPPER_HIDDEN);
                break;
            
            case disRight:
                DISPLAY_RIGHT(UPPER_HIDDEN , UPPER_BOUND , LOWER_HIDDEN);
                break;
            
            case GUESS:
                guess(VISIBLE_MATRIX , HIDDEN_MATRIX ,  LOWER_HIDDEN ,  UPPER_HIDDEN , LIFE_POINTS);
                break;
            
            case change:
                Initialize(LOWER_BOUND, UPPER_BOUND , LOWER_HIDDEN , UPPER_HIDDEN , HIDDEN_MATRIX , VISIBLE_MATRIX);
                LIFE_POINTS --;
                break;

            case cheat:
                cheatMatrix(HIDDEN_MATRIX);
                break;

            case leave:
                EXIT_FUNC = true;
                break;

            default:
                std::cout << "invalid choice\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
        if(EXIT_FUNC == false){    
            EXIT_FUNC = allZero(HIDDEN_MATRIX);
            if(EXIT_FUNC == true){
                std::cout << "Would you like to play again? (Y/N)\n";
                std::cin >> EXIT_CHOICE;
                EXIT_CHOICE = toupper(EXIT_CHOICE);
                if(EXIT_CHOICE == 'Y'){
                    Initialize(LOWER_BOUND, UPPER_BOUND , LOWER_HIDDEN , UPPER_HIDDEN , HIDDEN_MATRIX , VISIBLE_MATRIX);
                    EXIT_FUNC = false;
                }
            }
        }
        if(LIFE_POINTS <= 0 ){
            EXIT_FUNC = true;
        }
    }while(EXIT_FUNC == false);
    if(LIFE_POINTS <= 0){
        std::cout << "Tough Luck " << USER_NAME << " you ran out of life points\n";  
    }
    std::cout << "Well see you later then!";
    return 0;
}