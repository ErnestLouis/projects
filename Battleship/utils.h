#pragma once

#ifndef __UTILS_H__
#define __UTILS_H__

enum character_casetype
{
	CC_UPPER_CASE = 0,
	CC_LOWER_CASE,
	CC_EITHER
};


char get_character(const std::string prompt, const std::string error);
char get_character(const std::string prompt, const std::string error, character_casetype char_case);

int get_integer(const std::string prompt, const std::string error, const int valid_input[], int valid_inputlength);

void clear_screen();
void wait_for_keypress();

#endif
