//Test

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Battleship.h"

using namespace std;

int main()
{
    srand(time(NULL));
    //const char * INPUT_ERROR_STRING = "input error! Please, try again.";

    Player player1;
    Player player2;

    InitializePlayer(player1, "Player1");
    InitializePlayer(player2, "Player2");

    do
    {
        PlayGame(player1, player2);
    }while(WantToPlayAgain());

    //cout << "Hello world!" << endl;
    return 0;
}
