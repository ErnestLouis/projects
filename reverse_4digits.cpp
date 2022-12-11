#include <iostream>
//#include <vector>


int main()
{
	//std::vector<int> num_to_reverse;
	int num_to_reverse[4];

	std::cout << "Enter 4 digits to reverse" << std::endl;

	for (size_t i{0}; i < 4; i++) {
		std::cin >> num_to_reverse[i];
	}
	std::cout << std::endl;
	std::cout << "The numbers you enterd are: ";

	for (size_t i{0}; i < 4; i++) {
		std::cout << num_to_reverse[i]<< " ";
	}
	std::cout << std::endl;
	std::cout << "The numbers you enterd in reverse are: ";

	for (size_t j{ 4 }; j > 0; j--) {
		std::cout << num_to_reverse[j-1] << " ";
	}

	std::cout << std::endl;
	std::cout << "The numbers you enterd in reverse are: ";

	for (int j{ 3 }; j >= 0; j--) {
		std::cout << num_to_reverse[j] << " ";
	}
}
