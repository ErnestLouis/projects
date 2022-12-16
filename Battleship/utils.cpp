#include "Utils.h"
#include <iostream>
#include <cctype>

using namespace std;

const std::string INPUT_ERROR_STRING = "Input error! Please try again.";


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
	std::cout << "You entered: " << input << std::endl;
	return input;
}

char get_character(const std::string prompt, const std::string error, character_casetype char_case) {
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
		else if (isalpha(input))
		{
			if (char_case == CC_UPPER_CASE)
			{
				input = toupper(input);
			}
			else if (char_case == CC_LOWER_CASE)
			{
				input = tolower(input);
			}
		}
		else {
			std::cout << error << std::endl;
			failure = true;
		}

	} while (failure);
	std::cout << "You entered: " << input << std::endl;
	return input;
}




int get_integer(const std::string prompt, const std::string error, const int valid_input[], int valid_inputlength)
{
	int input;
	bool input_failure;

	
	do
	{

		input_failure = false;

		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << INPUT_ERROR_STRING << std::endl;
			input_failure = true;
		}
		else
		{
			for (int i = 0; i < valid_inputlength; i++)
			{
				if (input == valid_input[i])
				{
					return input;
				}
			}


			cout << error << endl;
			input_failure = true;
		}


	} while (input_failure);

	return -1;

}

void clear_screen()
{
	system("cls"); //clears windows screen
}

void wait_for_keypress()
{
	system("pause");//for windows only!

}
