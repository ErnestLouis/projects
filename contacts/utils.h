#pragma once


#ifndef __UTILS_H__
#define __UTILS_H__
#include <iostream>
#include <cctype>
#include <string>

enum character_casetype
{
	CC_UPPER_CASE = 0,
	CC_LOWER_CASE,
	CC_EITHER
};


char get_character(const std::string prompt, const std::string error);
char get_character(const std::string prompt, const std::string error, const char validInput[], int validInputLength, character_casetype char_case);

std::string get_string(const std::string prompt, const std::string error, std::string& text);
int get_integer(const std::string prompt, const std::string error, const int valid_input[], int valid_inputlength);

void clear_screen();
void wait_for_keypress();

#endif
