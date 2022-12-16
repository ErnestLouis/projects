// main.cpp : This file contains the 'Battle Ship'. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "utils.h"

//constants-anonymous enum with a bunch of values
enum
{
    AIRCRAFT_CARRIER_SIZE = 5,
    BATTLESHIP_SIZE = 4,
    CRUISER_SIZE = 3,
    DESTROYER_SIZE = 3,
    SUBMARINE_SIZE = 2,

    BOARD_SIZE = 10,
    NUM_SHIPS = 5,
    PLAYER_NAME_SIZE = 8, //player1, player2
    MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE
};

enum ship_type
{
    ST_NONE = 0, //SHIP TYPE NONE
    ST_AIRCRAFT_CARRIER,
    ST_BATTLESHIP,
    ST_CRUISER,
    ST_DESTROYER,
    ST_SUBMARINE
};


enum ship_orientation
{
    SO_HORIZONTAL = 0,
    SO_VERTICAL
};

struct Ship_position_type
{
    int row;
    int col;
};

struct Ship
{
    ship_type s_type;
    int s_size;
    ship_orientation s_orientation;
    Ship_position_type s_position;
};

//Boards
//------

enum guess_type
{
    GT_NONE = 0,
    GT_MISSED,
    GT_HIT
};

struct ship_part_type//because 1 squre on the board
{
    ship_type s_type;
    bool is_hit;
};

//Player
//------
struct Player
{
    //char player_name[PLAYER_NAME_SIZE];
    std::string player_name;
    Ship ships[NUM_SHIPS];
    guess_type guess_board[BOARD_SIZE][BOARD_SIZE];
    ship_part_type ship_board[BOARD_SIZE][BOARD_SIZE];

};

void initialize_player(Player& player, std::string  player_name);

void play_game(Player& player1, Player& player2);

bool want_to_play_again();

int main() {

    Player player1;
    Player player2;

    initialize_player(player1, "Player1");
    initialize_player(player1, "Player2");

    do
    {
        play_game(player1, player2);
    } while (want_to_play_again());

}

void initialize_player(Player& player, std::string  player_name) 
{
    if (std::size(player_name) > 0)
    {
        player.player_name = player_name;
    }

    initialize_ship(player.ships[0], AIRCRAFT_CARRIER_SIZE, ST_AIRCRAFT_CARRIER);

    initialize_ship(player.ships[1], BATTLESHIP_SIZE, ST_BATTLESHIP);

    initialize_ship(player.ships[2], CRUISER_SIZE, ST_CRUISER);

    initialize_ship(player.ships[3], DESTROYER_SIZE, ST_DESTROYER);

    initialize_ship(player.ships[4], SUBMARINE_SIZE, ST_SUBMARINE);
}

void play_game(Player& player1, Player& player2);

bool want_to_play_again()
{
    char input;

    const char valid_input[2] = { 'y', 'n' };

    input = get_character("Would you like to play again? (y/n)");
}