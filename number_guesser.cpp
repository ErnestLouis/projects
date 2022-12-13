// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>

void play_game();
bool want_to_play_again();
bool is_game_over(int secret_number, int number_of_tries_left, int guess);
int get_guess(int number_of_tries_left);
void display_result(int secret_number, int number_of_tries_left);


const int IGNORE_CHAR = 256;


int main()
{
	std::srand(std::time(0));//seed

	do
	{
		play_game();
	} while (want_to_play_again());




}

void play_game()
{
	const int UPPER_BOUND = 100;
	int secret_number = std::rand() % UPPER_BOUND + 1;
	int number_of_tries_left = ceil(log2(UPPER_BOUND));
	int guess = 0;

	std::cout << " The range of the number is between 0 and 100" << std:: endl;
	do
	{

		guess = get_guess(number_of_tries_left);
		if (guess != secret_number)
		{
			number_of_tries_left--;
			if (guess > secret_number)
			{
				std::cout << "Your guess was too high!" << std::endl;

			}
			else
			{
				std::cout << "Your guess was too low!" << std::endl;

			}
		}

	} while (!is_game_over(secret_number,number_of_tries_left,guess));

	display_result(secret_number, number_of_tries_left);

}

bool want_to_play_again()
{
	
	char input;
	bool failure;

	do
	{
		failure = false;

		std::cout << "Would you like to play again? (y/n)";
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(IGNORE_CHAR, '\n');
			std::cout << "Input error! Please try agin." << std::endl;
			failure = true;
		}
		else
		{
			std::cin.ignore(IGNORE_CHAR, '\n');

			input = tolower(input);
		}
	} while (failure);

	return input == 'y';
}

bool is_game_over(int secret_number, int number_of_tries_left, int guess)
{
	return secret_number == guess || number_of_tries_left <= 0;
}

int get_guess(int number_of_tries_left)
{

	int guess;
	bool failure;

	do
	{
		failure = false;

		std::cout << "please enter you guess ( number of guesses left: " << number_of_tries_left << "): ";
		std::cin >> guess;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(IGNORE_CHAR, '\n');
			std::cout << "Input error! Please try aagin." << std::endl;
			failure = true;
		}
	} while (failure);

	return guess;
}

void display_result(int secret_number, int number_of_tries_left)
{
	if (number_of_tries_left > 0)
	{
		std::cout<< "You got it! It was: " << secret_number << std::endl;
	}
	else
	{
		std::cout << "You didn't get it.... It was: " << secret_number << std::endl;
	}
}