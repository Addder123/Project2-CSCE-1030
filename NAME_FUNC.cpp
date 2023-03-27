#include <iostream>
#include <cstdlib>
#include <string.h>

std::string GET_NAME(std::string USER_NAME)
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


int main()
{
    std::string USER_NAME;
    GET_NAME(USER_NAME);
}