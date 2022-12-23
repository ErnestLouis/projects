// hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>

void play_game();
bool want_to_play_game();
size_t get_secret_phrase(std::string& secret_phrase);
const std::string INPUT_ERROR_STRING = "Input error! Please try again.";
char get_character(const std::string prompt, const std::string error);
std::string* make_hidden_phrase(std::string secret_phrase);
char get_guess();

void draw_board(size_t number_of_guesses_left, std::string* noptr_hidden_phrase, size_t secret_phrase_length);
void update_board(char guess, std::string* noptr_hidden_phrase,const std::string secret_phrase, size_t secret_phrase_length, size_t & number_of_guesses_left);

bool is_game_over(size_t number_of_guesses_left, const std::string* noptr_hidden_phrase, size_t secret_phrase_length);
void display_result(const std::string secret_phrase, size_t number_of_guesses_left, size_t secret_phrase_length);
void clear_screen();

int main()
{

    do
    {
        play_game();

    } while (want_to_play_game());
}

void play_game() {

    const size_t MAX_NUMBER_OF_GUESSES{ 6 };
    size_t number_of_guesses_left = MAX_NUMBER_OF_GUESSES;

    std::string secret_phrase{ };
    std::string* optr_hidden_phrase{ nullptr };
    std::string prompt{ "Please enter a letter. " };
    std::string error{ "invalid character entered, please try again " };



    size_t secret_phrase_length = get_secret_phrase(secret_phrase);

    optr_hidden_phrase = make_hidden_phrase(secret_phrase);

    draw_board(number_of_guesses_left, optr_hidden_phrase, secret_phrase_length);

    char guess;

    do {

        guess = get_guess();

        update_board(guess, optr_hidden_phrase, secret_phrase, secret_phrase_length, number_of_guesses_left);

        draw_board(number_of_guesses_left, optr_hidden_phrase, secret_phrase_length);
        
    } while (!is_game_over(number_of_guesses_left, optr_hidden_phrase, secret_phrase_length));

    display_result(secret_phrase, number_of_guesses_left,secret_phrase_length);

    delete[] optr_hidden_phrase;
};

char get_guess() {
    std::string promtu{ "Please input your guess: " };
    return get_character(promtu, INPUT_ERROR_STRING);
}

void update_board(char guess, std::string* noptr_hidden_phrase,const std::string secret_phrase, size_t secret_phrase_length, size_t & number_of_guesses_left) {
   
    bool found = false;

    for (size_t i{ 0 }; i < secret_phrase_length; i++) {
        if (std::tolower(secret_phrase[i]) == guess) {
            noptr_hidden_phrase[i] = secret_phrase[i];
            found = true;
        }
    }
    if (!found) {
        number_of_guesses_left--;
    }
}

bool want_to_play_game() {

    const char valid_inputs[] = { 'y', 'n' };


    std::string play_again{ "Would you like to play again? (y/n) " };
    char response = get_character(play_again, INPUT_ERROR_STRING);

    return response == 'y';
};

size_t get_secret_phrase(std::string& secret_phrase) {

    bool failure;


    do {
        failure = false;
        std::cout << "Please enter the secret phrase: ";

        std::getline(std::cin, secret_phrase);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << INPUT_ERROR_STRING << std::endl;
            failure = true;
        }
        else if (secret_phrase.size() == 0) {
            std::cout << "You must enter a word with more than 0 Character!";
            failure = true;
        }


    } while (failure);
    size_t length = std::size(secret_phrase);


    return length;
};


std::string* make_hidden_phrase( std::string secret_phrase) {

    std::string* hidden_phrase = new std::string[std::size(secret_phrase)];
    const std::string space{ ' ' };
    for (int i = 0; i < (std::size(secret_phrase)); i++) {
        if (secret_phrase[i] != ' ') {
            hidden_phrase[i] = '_';
        }
        else {
            hidden_phrase[i] = ' ';
        }
    }
    return hidden_phrase;
}



char get_character(const std::string prompt, const std::string error) {
    char input{};
    bool failure;

    do {
        failure = false;

        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << INPUT_ERROR_STRING << std::endl;
            failure = true;
        }
        else if (std::isalpha(input)) {
            input = std::tolower(input);
        }
        else {
            std::cout << error << std::endl;
            failure = true;
        }

    } while (failure);

    return input;
}

bool is_game_over(size_t number_of_guesses_left, const std::string* noptr_hidden_phrase, size_t secret_phrase_length) {

    bool has_dash{ false };
    const std::string dash{  };
     //char dash1 = '_';
    // std::string dash = std::to_string(dash1);

    for (int i = 0; i < secret_phrase_length; i++) {
        
        if ((noptr_hidden_phrase[i]) =="_") {
            has_dash = true;
            break;
        }
    }

    return number_of_guesses_left == 0 || !has_dash;

}

void display_result(const std::string secret_phrase, size_t number_of_guesses_left, size_t secret_phrase_length) {
    if (number_of_guesses_left > 0) {
        std::cout << "You got it! The phrase was: ";
            for (size_t i = 0; i < secret_phrase_length; i++) {

                std::cout << secret_phrase[i];

            }
        std::cout << std::endl;
    }
    else {
        std::cout << "You didn't get it... The phrase was: ";
        for (size_t i = 0; i < secret_phrase_length; i++) {

            std::cout << secret_phrase[i];

        }
        std::cout << std::endl;
    }
}

void draw_board(size_t number_of_guesses_left, std::string* noptr_hidden_phrase, size_t secret_phrase_length) {

    clear_screen();

    switch (number_of_guesses_left) {


        break;

    case 6:
    {
        std::cout << "+===+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   " << std::endl;
        std::cout << "|  " << std::endl;
        std::cout << "|  " << std::endl;
        std::cout << "|_______" << std::endl << std::endl;
    }
    break;

    case 5:
    {
        std::cout << "+===+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   o" << std::endl;
        std::cout << "|    " << std::endl;
        std::cout << "|  " << std::endl;
        std::cout << "|_______" << std::endl << std::endl;
    }
    break;

    case 4:
    {
        std::cout << "+===+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   o" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|  " << std::endl;
        std::cout << "|_______" << std::endl << std::endl;
    }
    break;

    case 3:
    {
        std::cout << "+===+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   o" << std::endl;
        std::cout << "|  /|" << std::endl;
        std::cout << "|  " << std::endl;
        std::cout << "|_______" << std::endl << std::endl;
    }
    break;

    case 2:
    {
        std::cout << "+===+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   o" << std::endl;
        std::cout << "|  /|\\" << std::endl;
        std::cout << "|  " << std::endl;
        std::cout << "|_______" << std::endl << std::endl;
    }
    break;

    case 1:
    {
        std::cout << "+===+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   o" << std::endl;
        std::cout << "|  /|\\" << std::endl;
        std::cout << "|  / " << std::endl;
        std::cout << "|_______" << std::endl << std::endl;
    }
    break;

    case 0:
    {
        std::cout << "+===+" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   o" << std::endl;
        std::cout << "|  /|\\" << std::endl;
        std::cout << "|  / \\" << std::endl;
        std::cout << "|_______" << std::endl << std::endl;
    }

    break;

    default:
        break;

    }
    std::cout << std::endl;

    for (int i = 0; i < secret_phrase_length; i++) {

        std::cout << noptr_hidden_phrase[i];

    }
    std::cout << std::endl;
}

void clear_screen()
{
    system("cls"); //clears windows screen
}

void wait_for_key_press()
{
    system("pause");//press any key to continue
}