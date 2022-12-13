// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

void play_game();
bool want_to_play_again();
bool is_game_over(int secret_number, int number_of_tries, int guess);
int get_guess(int number_of_tries);
void display_result(secret_number, number_of_tries);

int main()
{
	do
	{
		play_game();
	} while (want_to_play_again());




}

void play_game()
{
	const int UPPER_BOUND = 100;
	int secret_number = 65;
	int number_of_tries = ceil(log2(UPPER_BOUND));
	int guess = 0;

	do
	{

		guess = get_guess(number_of_tries);
		if (guess != secret_number)
		{
			number_of_tries--;
			if (guess > secret_number)
			{
				std::cout << "Your guess was too high!" << std::endl;

			}
			else
			{
				std::cout << "Your guess was too low!" << std::endl;

			}
		}

	} while (!is_game_over(secret_number, number_of_tries, guess));

}

bool want_to_play_again()
{

	//TODO: implement

	return false;
}

bool is_game_over(int secret_number, int number_of_tries, int guess)
{
	return secret_number == guess || number_of_tries <= 0;
}

int get_guess(int number_of_tries)
{
	const int IGNORE_CHAR = 256;
	int guess;
	bool failure;

	do
	{
		failure = false;

		std::cout << "please enter you guess ( number of guesses left: " << number_of_tries << "): ";
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

void display_result(secret_number, number_of_tries)
{

}