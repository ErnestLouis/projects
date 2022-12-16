// main.cpp : This file contains the 'Battle Ship'. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "utils.h"

//error string
std::string prompt{ "Would you like to play again? (y/n)" };
std::string error{ "invalid character entered, please try again! " };

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

enum Ship_type
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
    Ship_type ship_type;
    int ship_size;
    ship_orientation orientation;
    Ship_position_type position;
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
    Ship_type ship_type;
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

void initialize_ship(Ship& ship, int ship_size, Ship_type ship_type);


void play_game(Player& player1, Player& player2);

bool want_to_play_again();

void setup_board(Player& player);

void clear_boards(Player& player);

void draw_boards(const Player& player);

void draw_seperator_line();

void draw_columns_row();

void draw_shipboard_row(const Player& player, int row);

char get_guess_representation(const Player& player, int row, int col);

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

void play_game(Player& player1, Player& player2)
{
    setup_board(player1);
    setup_board(player2);
}

bool want_to_play_again()
{
    char input;

    const char valid_input[2] = { 'y', 'n' };

    input = get_character(prompt, error,CC_LOWER_CASE);

    return input == 'y';
}

void setup_board(Player& player)
{
    clear_boards(player);

    draw_boards(player);
}

void initialize_ship(Ship& ship, int ship_size, Ship_type ship_type)
{
    ship.ship_type = ship_type;
    ship.ship_size = ship_size;
    ship.position.row = 0;
    ship.position.col = 0;
    ship.orientation = SO_HORIZONTAL;
}

void clear_boards(Player& player) 
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int c = 0; c < BOARD_SIZE; c++)
        {
            player.guess_board[r][c] = GT_NONE;
            player.ship_board[r][c].ship_type = ST_NONE; // no ship present
            player.ship_board[r][c].is_hit = false;
        }
    }
}

void draw_shipboard_row(const Player& player, int row)
{
    char row_name = row + 'A';
    std::cout << row_name << "|";

    for (int c = 0; c < BOARD_SIZE; c++)
    {
        std::cout << " " << " " << " |";
    }
}

void draw_guessboard_row(const Player& player, int row)
{
    char row_name = row + 'A';
    std::cout << row_name << "|";

    for (int c = 0; c < BOARD_SIZE; c++)
    {
        std::cout << " " << get_guess_representation(player,row,c) << " |";
    }
}

void draw_boards(const Player& player)
{
    draw_columns_row();

    draw_columns_row();

    std::cout << std::endl;

    for (int r = 0; r < BOARD_SIZE; r++)
    {
        draw_seperator_line();

        std::cout << " ";

        draw_seperator_line();

        std::cout << std::endl;

        draw_shipboard_row(player, r);

        std::cout << " ";

        draw_shipboard_row(player, r);

        std::cout << std::endl;
    }

    draw_seperator_line();

    std::cout << " ";

    draw_seperator_line();

    std::cout << std::endl;

}

void draw_seperator_line()
{
    std::cout << " ";

    for (int c = 0; c < BOARD_SIZE; c++)
    {
        std::cout << "+---";
    }

    std::cout << "+";
}

void draw_columns_row()
{
    std::cout << "  ";

    for (int c = 0; c < BOARD_SIZE; c++)
    {
        int column_name = c + 1;

        std::cout << " "<< column_name << "  ";
    }
}
char get_ship_representation(const Player& player, int row, int col)
{
    if (player.ship_board[row][col].is_hit)
    {
        return '*'; // represent hit
    }

    if (player.ship_board[row][col].ship_type == ST_AIRCRAFT_CARRIER)
    {
        return 'A';
    }
    else if (player.ship_board[row][col].ship_type == ST_BATTLESHIP)
    {
        return 'B';
    }
    else if (player.ship_board[row][col].ship_type == ST_CRUISER)
    {
        return 'C';
    }
    else if (player.ship_board[row][col].ship_type == ST_DESTROYER)
    {
        return 'D';
    }
    else if (player.ship_board[row][col].ship_type == ST_SUBMARINE)
    {
        return 'S';
    }
    else
    {
        return ' ';
    }
}

char get_guess_representation(const Player& player, int row, int col)
{
    if (player.guess_board[row][col] == GT_HIT)
    {
        return '*';
    }
    else if (player.guess_board[row][col] == GT_MISSED)
    {
        return 'o';
    }
    else
    {
        return ' ';
    }
}