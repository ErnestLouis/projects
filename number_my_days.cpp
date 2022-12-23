// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const unsigned DAYS_IN_YEAR{ 365 };
const unsigned MONTHS_IN_YEAR{ 30 };

unsigned years_func(unsigned input);
unsigned months_func(unsigned input);
unsigned days_func(unsigned input);


int main()
{
	std::cout << " Year, Month Day Convertor" << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::cout << " Enter the number of days you would like converted: " << std::endl;

	unsigned user_input{};
	unsigned years{};
	unsigned months{};
	unsigned days{};


	std::cin >> user_input;

	if (user_input > 0) {
		std::cout << "Calculating..." << std::endl;
		std::cout <<"Years: " << years_func(user_input) << " " 
			<<"Months: "<< months_func(user_input) << " " 
			<<"Days: "<< days_func(user_input) << " " << std::endl;
	}



}

unsigned years_func(unsigned input) {
	unsigned result = input / DAYS_IN_YEAR;
	return result;
};

unsigned months_func(unsigned input) {
	unsigned minus_years{years_func(input) * DAYS_IN_YEAR};
	unsigned days_left{ input - minus_years };
	unsigned result = days_left / MONTHS_IN_YEAR;
	return result;
};

unsigned days_func(unsigned input) {
	unsigned total_years{((years_func(input)) * DAYS_IN_YEAR)};
	//std::cout <<"Years: " << total_years << std::endl;
	unsigned total_months{((months_func(input)) * MONTHS_IN_YEAR) };
	//std::cout <<"Months: " << total_months << std::endl;
	unsigned result = input - (total_years + total_months);
	//std::cout << "result: " << result << std::endl;
	return result;
};