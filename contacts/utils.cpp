#include "Utils.h"



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

char get_character(const std::string prompt, const std::string error, const char validInput[], int validInputLength, character_casetype char_case) {

	const int IGNORE_CHARS = 256;

	char input{};
	bool failure;

	do {
		failure = false;

		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
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

			for (int i = 0; i < validInputLength; i++)
			{
				if (input == validInput[i])
				{
					return input;
				}
			}
		}
		else 
		{
			std::cout << error << std::endl;
			failure = true;
		}

	} while (failure);

	std::cout << "You entered: " << input << std::endl;//block out line

	return input;
}




int get_integer(const std::string prompt, const std::string error, const int valid_input[], int valid_inputlength)
{

	const int IGNORE_CHARS = 256;

	int input;
	bool input_failure;

	
	do
	{

		input_failure = false;

		std::cout << prompt;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout << error << std::endl;
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


			std::cout << error << std::endl;
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

/*
int get_string(const std::string prompt, const std::string error, std::string text)
{
	//const int IGNORE_CHARS = 256;

	int input;
	bool input_failure;
	int length = std::size(text);

	do
	{

		input_failure = false;

		std::cout << prompt;
		//std::cin >> ;
		std::getline(std::cin,text);

		if (std::cin.fail()) {
			text.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			std::cout << error << std::endl;
			input_failure = true;
		}
		else
		{


			if ( length == 0)
			{
				std::cout << error << std::endl;
				input_failure = true;
			}
		}


	} while (input_failure);

	return length;


}

*/

std::string get_string(const std::string prompt, const std::string error, std::string& text)
{

	bool input_failure;
	int length; 



	do
	{

		input_failure = false;

		std::cout << prompt;
		std::cin >> text;

		length = text.length();

		if (length == 0)
		{
			std::cout << error << std::endl;
			input_failure = true;
		}


	} while (input_failure);

	return text;

}