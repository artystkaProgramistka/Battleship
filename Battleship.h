
#ifndef __ BATTLESHIP_H__
#define __BATTLESHIP_H__

#include <iostream>

using namespace std;

// Data design:
/*enum SizeType;
enum ShipType;
enum ShipOrientationType;
struct BattleshipPositionType;
struct Ship;
enum GuessType;
struct SipPartType;
struct Player;*/
enum SizeType
{
    AIRCRAFT_CARRIER_SIZE = 5,
    BATTLESHIP_SIZE = 4,
    CRUISER_SIZE = 3,
    DESTROYER_SIZE = 2,
    SUBMARINE_SIZE = 1,

    BOARD_SIZE = 10,
    NUM_SHIPS = 5,
    PLAYER_NAME_SIZE = 8, // Player1, Player2
    MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE
};

enum ShipType
{
    ST_NONE = 0,
    ST_AIRCRAFT_CARRIER,
    ST_BATTLESHIP,
    ST_CRUISER,
    ST_DESTROYER,
    ST_SUBMARINE
};

enum ShipOrientationType
{
    SO_HORIZONTAL = 0,
    SO_VERTICAL
};

struct ShipPositionType
{
    int row;
    int col;
};

struct Ship
{
    ShipType shipType;
    int shipSize;
    ShipOrientationType orientation;  //stworzylam tutaj typ, ale on sam nie definiuje zadnej kokrenej zmiennej =>
    ShipPositionType position;          // miszê ustawiæ wszystkie statki dla kazdego gracza
};

enum GuessType
{
    GT_NONE = 0,
    GT_MISSED,
    GT_HIT
};

struct ShipPartType
{
    ShipType shipType;
    bool isHit;
};

enum PlayerType
{
    PT_HUMAN = 0,
    PT_AI
};

struct Player
{
    PlayerType playerType;
    char playerName[PLAYER_NAME_SIZE];
    Ship ships[NUM_SHIPS];                  // musze ustawic wszystkie statki poprawnie i przekazac graczowi jeden typ statku do
    GuessType guessBoard[BOARD_SIZE][BOARD_SIZE];   // kazdego z poszczegolnych elementow tablicy
    ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE];
};

// Functions:
void InitializeShip(Ship & ship, int shipSize, ShipType shipType);
void InitializePlayer(Player & player, const char * playerName);
bool WantToPlayAgain();
void ClearBoards(Player&player);
void DrawColumnsRow();
void DrawSeparatorLine();
char GetShipeprezentation(const Player& player, int row, int col);
char GetGuessRepresentationAt(const Player& player, int row, int col);
void DrawShipBoardRow(const Player& player, int row);
void DrawGuessBoardRow(const Player& player, int row);
void DrawBoards(const Player&player);
const char* GetShipNameForShipType(ShipType shipType);
void SetUpBoards(Player&player);
void PlayGame(Player& player1, Player&player2);
char GetCharacter(const char* prompt, const char*error);
char GetCharacter(const char* prompt, const char* error, const char validInput[], int validInputLength);
ShipPositionType GetBoardPosition();
ShipOrientationType GetShipOrientation();
bool IsValidPlacement(const Player& player, const Ship& currentShip, const ShipPositionType shipPosition, const ShipOrientationType shipOrientation);
void PlaceShipOnBoard(Player& player, Ship& currentShip, const ShipPositionType shipPosition, const ShipOrientationType shipOrientation);
ShipType UpdateBoards(ShipPositionType guess, Player& currentPlayer, Player& otherPlayer);
bool IsGameOver(const Player& player1, const Player& player2);
bool IsSunk(const Player& player, const Ship& ship);
bool AreAllShipsSunk(const Player& player);
void SwitchPlayers(Player** currentPlayer, Player** otherPlayer);
void DisplayWinner(const Player& player1, const Player& player2);
PlayerType GetPlayer2Type();
ShipPositionType GetRandomPosition();
ShipPositionType GetAIGuess(const Player& aiPlayer);
void SetUpAIBoards(Player& player);

#endif


