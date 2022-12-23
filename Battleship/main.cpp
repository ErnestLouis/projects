// main.cpp : This file contains the 'Battle Ship'. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "utils.h"
#include <ctime>

//error string
std::string prompt{ "Would you like to play again? (y/n)" };
std::string error{ "invalid character entered, please try again! " };
const std::string INPUT_ERROR_STRING = "Input error! Please try again.";

//constants-anonymous enum with a bunch of values
enum Class
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


enum Ship_orientation
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
    Ship_orientation orientation;
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

enum Player_type
{
    PT_HUMAN = 0,
    PT_AI

};

//Player
//------
struct Player
{
    Player_type player_type;
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

char get_guess_representation_at(const Player& player, int row, int col);

char get_ship_representation_at(const Player& player, int row, int col);

Ship_position_type get_board_position();

std::string get_shipname_for_shiptype(Ship_type ship_type);

Ship_position_type map_board_position(char row_input, int col_input);

Ship_orientation get_ship_orientation();

bool is_valid_placement_func(const Player& player, const Ship& current_ship, const Ship_position_type& ship_position, Ship_orientation orientation);

void place_ship_onboard(Player& player, Ship& current_ship, const Ship_position_type& ship_position, Ship_orientation orientation);

Ship_type update_boards(Ship_position_type guess, Player& current_player, Player& other_player);

bool is_game_over(const Player& player1, const Player& player2);

bool are_all_ship_sunk(const Player& player);

bool is_sunk(const Player& player, const Ship& ship);

void switch_player(Player** current_player, Player** other_player);

void display_winner(const Player& player1, const Player& player2);

Player_type get_player2_type();

Ship_position_type get_ai_guess(const Player& ai_player);

void setup_ai_boards(Player& player);

Ship_position_type get_random_position();

int main() {
    std::srand(std::time(0));

    Player player1;
    Player player2;

    initialize_player(player1, "Player1");
    initialize_player(player2, "Player2");

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
    clear_screen();

    player1.player_type = PT_HUMAN;
    player2.player_type = get_player2_type();

    setup_board(player1);
    setup_board(player2);

    Player* current_player = &player1;
    Player* other_player = &player2;

    Ship_position_type guess;

    do
    {
        if (current_player->player_type == PT_HUMAN)
        {
            draw_boards(*current_player);
        }

        bool is_valid_guess;

        do
        {
            if (current_player->player_type == PT_HUMAN)
            {
                std::cout << current_player->player_name << " what is your guess?" << std::endl;

                guess = get_board_position();
            }
            else
            {
                guess = get_ai_guess(*current_player);
            }
            is_valid_guess = current_player->guess_board[guess.row][guess.col] == GT_NONE;

            if (!is_valid_guess && current_player->player_type == PT_HUMAN)
            {
                std::cout << "That was not a valid guess! Please try again." << std::endl;
            }

        } while (!is_valid_guess);

        Ship_type type = update_boards(guess, *current_player, *other_player);

        if (current_player->player_type == PT_AI)
        {
            draw_boards(*other_player);
            std::cout << current_player->player_name << " chose row " << static_cast<char>(guess.row + 'A') <<
                " and column " << guess.col + 1 << std::endl;
        }
        else
        {
            draw_boards(*current_player);
        }


        if (type != ST_NONE && is_sunk(*other_player, other_player->ships[type - 1]))
        {
            if (current_player->player_type == PT_AI)
            {
                std::cout << current_player->player_name << " sunk your " << get_shipname_for_shiptype(type) << "!" << std::endl;
            }
            else
            {
                std::cout << "You sunk " << other_player->player_name << "'s " << get_shipname_for_shiptype(type) << "!" << std::endl;

            }
        }

        wait_for_keypress();
        switch_player(&current_player, &other_player);

    } while (!is_game_over(player1, player2));

    display_winner(player1, player2);
}

bool want_to_play_again()
{
    char input;

    const char valid_input[2] = { 'y', 'n' };

    input = get_character(prompt, INPUT_ERROR_STRING, valid_input, 2, CC_LOWER_CASE);

    return input == 'y';
}

void setup_board(Player& player)
{
    clear_boards(player);

    if (player.player_type == PT_AI)
    {
        setup_ai_boards(player);
        return;
    }

    for (int i = 0; i < NUM_SHIPS; i++) {

        draw_boards(player);

        Ship& current_ship = player.ships[i];

        Ship_position_type ship_position;
        Ship_orientation orientation;

        bool is_valid_placement = false;

        do
        {

            std::cout << player.player_name << " please set the position and orientation for your " <<
                get_shipname_for_shiptype(current_ship.ship_type) << std::endl;

            ship_position = get_board_position();
            orientation = get_ship_orientation();

            is_valid_placement = is_valid_placement_func(player, current_ship, ship_position, orientation);

            if (!is_valid_placement)
            {
                std::cout << "That was not a valid placement. Please try again." << std::endl;
                wait_for_keypress();
            }

        } while (!is_valid_placement);

        place_ship_onboard(player, current_ship, ship_position, orientation);
    }

    draw_boards(player);
    wait_for_keypress();
}

void initialize_ship(Ship& ship, int ship_size, Ship_type ship_type)
{
    ship.ship_type = ship_type;
    ship.ship_size = ship_size;
    ship.position.row = 0;
    ship.position.col = 0;
    ship.orientation = SO_HORIZONTAL;
}

Ship_position_type map_board_position(char row_input, int col_input)
{
    int real_row = row_input - 'A';
    int real_col = col_input - 1;

    Ship_position_type board_position;

    board_position.row = real_row;
    board_position.col = real_col;

    return board_position;
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
        std::cout << " " << get_ship_representation_at(player, row, c) << " |";
    }
}

void draw_guessboard_row(const Player& player, int row)
{
    char row_name = row + 'A';
    std::cout << row_name << "|";

    for (int c = 0; c < BOARD_SIZE; c++)
    {
        std::cout << " " << get_guess_representation_at(player, row, c) << " |";
    }
}

void draw_boards(const Player& player)
{
    clear_screen();  //sceen clears after each completed entry

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

        draw_guessboard_row(player, r);

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

        std::cout << " " << column_name << "  ";
    }
}
char get_ship_representation_at(const Player& player, int row, int col)
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

char get_guess_representation_at(const Player& player, int row, int col)
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

std::string get_shipname_for_shiptype(Ship_type ship_type) {
    if (ship_type == ST_AIRCRAFT_CARRIER)
    {
        return "Aircraft Carrier";
    }
    else if (ship_type == ST_BATTLESHIP)
    {
        return "Battleship";
    }
    else if (ship_type == ST_CRUISER)
    {
        return "Cruiser";
    }
    else if (ship_type == ST_DESTROYER)
    {
        return "Destroyer";
    }
    else if (ship_type == ST_SUBMARINE)
    {
        return "Submarine";
    }
    else
    {
        return "None";
    }

}

Ship_position_type get_board_position()
{

    char row_input;
    int col_input;

    const char valid_row_input[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J' };
    const int valid_col_input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };

    row_input = get_character("Please input a row (A - J): ", INPUT_ERROR_STRING, valid_row_input, BOARD_SIZE, CC_UPPER_CASE);
    col_input = get_integer("Please input a column (1 - 10)", INPUT_ERROR_STRING, valid_col_input, BOARD_SIZE);

    return map_board_position(row_input, col_input);
}

Ship_orientation get_ship_orientation()
{

    const char valid_input[2] = { 'H', 'V' };

    char input = get_character("Please choose an orientation (H) for Horizontal or (V) for vertical)", INPUT_ERROR_STRING, valid_input, 2, CC_UPPER_CASE);

    if (input == valid_input[0])
    {
        return SO_HORIZONTAL;
    }
    else
    {
        return SO_VERTICAL;
    }
}

bool is_valid_placement_func(const Player& player, const Ship& current_ship, const Ship_position_type& ship_position, Ship_orientation orientation)
{

    if (orientation == SO_HORIZONTAL)
    {
        for (int c = ship_position.col; c < (ship_position.col + current_ship.ship_size); c++)
        {
            if ((player.ship_board[ship_position.row][c].ship_type != ST_NONE) || (c >= BOARD_SIZE))
            {
                return false;
            }
        }
    }
    else
    {
        for (int r = ship_position.row; r < (ship_position.row + current_ship.ship_size); r++)
        {
            if ((player.ship_board[r][ship_position.col].ship_type != ST_NONE) || (r >= BOARD_SIZE))
            {
                return false;
            }
        }
    }
    return true;
}

void place_ship_onboard(Player& player, Ship& current_ship, const Ship_position_type& ship_position, Ship_orientation orientation)
{
    current_ship.position = ship_position;
    current_ship.orientation = orientation;

    if (orientation == SO_HORIZONTAL)
    {
        for (int c = ship_position.col; c < (ship_position.col + current_ship.ship_size); c++)
        {
            player.ship_board[ship_position.row][c].ship_type = current_ship.ship_type;
            player.ship_board[ship_position.row][c].is_hit = false;
        }
    }
    else
    {
        for (int r = ship_position.row; r < (ship_position.row + current_ship.ship_size); r++)
        {
            player.ship_board[r][ship_position.col].ship_type = current_ship.ship_type;
            player.ship_board[r][ship_position.col].is_hit = false;
        }
    }
}

Ship_type update_boards(Ship_position_type guess, Player& current_player, Player& other_player)
{
    if (other_player.ship_board[guess.row][guess.col].ship_type != ST_NONE)
    {
        //hit
        current_player.guess_board[guess.row][guess.col] = GT_HIT;
        other_player.ship_board[guess.row][guess.col].is_hit = true;

    }
    else
    {
        //not a hit
        current_player.guess_board[guess.row][guess.col] = GT_MISSED;
    }

    return other_player.ship_board[guess.row][guess.col].ship_type;

}

bool is_sunk(const Player& player, const Ship& ship)
{
    if (ship.orientation == SO_HORIZONTAL)
    {
        for (int col = ship.position.col; col < (ship.position.col + ship.ship_size); col++)
        {
            if (!player.ship_board[ship.position.row][col].is_hit)
            {
                return false;
            }
        }
    }

    else
    {
        for (int row = ship.position.row; row < (ship.position.row + ship.ship_size); row++)
        {
            if (!player.ship_board[row][ship.position.col].is_hit)
            {
                return false;
            }
        }
    }
    return true;
}

bool are_all_ship_sunk(const Player& player)
{
    for (int i = 0; i < NUM_SHIPS; i++)
    {
        if (!is_sunk(player, player.ships[i]))
        {
            return false;
        }
    }

    return true;
}


bool is_game_over(const Player& player1, const Player& player2)
{
    return are_all_ship_sunk(player1) || are_all_ship_sunk(player2);
}

void switch_player(Player** current_player, Player** other_player)
{
    Player* temp_player = *current_player;
    *current_player = *other_player;
    *other_player = temp_player;

}

void display_winner(const Player& player1, const Player& player2)
{
    if (are_all_ship_sunk(player1))
    {
        std::cout << "Congratulations " << player2.player_name << "! You won!" << std::endl;
    }
    else if (are_all_ship_sunk(player2))
    {
        std::cout << "Congratulations " << player1.player_name << "! You won!" << std::endl;
    }
}

Player_type get_player2_type()
{
    const int valid_input[2] = { 1,2 };

    int input = get_integer("Who would you like to play against?\n1. Human\n2. AI\n\nWhat is your choice? ", INPUT_ERROR_STRING, valid_input, 2);

    if (input == 1)
    {
        return PT_HUMAN;
    }
    else
    {
        return PT_AI;
    }
}
Ship_position_type get_random_position()
{
    Ship_position_type guess;

    guess.row = rand() % BOARD_SIZE;
    guess.col = rand() % BOARD_SIZE;

    return guess;
}

Ship_position_type get_ai_guess(const Player& ai_player)
{
    return get_random_position();
}

void setup_ai_boards(Player& player)
{
    Ship_position_type pos;
    Ship_orientation orientation;

    for (int i = 0; i < NUM_SHIPS; i++)
    {
        Ship& current_ship = player.ships[i];

        do
        {
            pos = get_random_position();
            orientation = Ship_orientation(rand() % 2);


        } while (!is_valid_placement_func(player, current_ship, pos, orientation));

        place_ship_onboard(player, current_ship, pos, orientation);
    }


}