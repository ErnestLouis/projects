// string_practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using std::swap;
using std::vector;
using std::string;

void space(int num);
int last(string& str);
int min(vector<int> vec);
void find_duplicate(string& str);
void find_dup(string& str);
bool is_anagram(const std::string& str1, const std::string& str2);


int cslength(const char* cstr)
{
	int i = 0;
	int length = 0;
	while (cstr[i] != '\0')
	{
		length++;
		i++;
	}
	return length;
}

int count_word(const char* A)
{
	int word = 1;
	for (int i = 0; A[i] != '\0'; i++)
	{
		if (A[i] == ' ' && A[i - 1] != ' ')
		{
			word++;
		}
	}
	return word;
}

bool valid_pass(const char* password)
{
	for (int i = 0; password[i] != '\0'; i++)
	{
		if (!(password[i] >=65 && password[i]<=90) &&
			!(password[i] >= 97 && password[i] <= 122) &&
			!(password[i] >= 48 && password[i] <= 57)
			)
		{
			return false;
		}
	}
	return true;
}



char * str_add (char A[] , int size) {
	char* s;
	s = new char[size];

	for (int i = 0; i < size; i++)
	{
		s[i] = A[i];
		s[0] = 'o';
	}

	return s;
}


void make_upper (const char * cstr)
{
	const char * const A = "orange";



}


void reverse(char * A)
{
	int j = 0;
	for ( ; A[j] != '\0'; j++)
	{
	}
	j = j - 1;
	int i = 0;
	while (i < j) {

		swap(A[i], A[j]);
		i++;
		j--;
	}

}

bool is_palindrome(const char* A)
{
	int j = 0;
	for (; A[j] != '\0'; j++)
	{
	}
	j = j - 1;
	int i = 0;
	while (i < j) {

		if (A[i] == A[j])
		{
			i++;
			j--;
		}
		else
		{
			break;
			return false;
		}
	}
	return true;

}

const char * compare(const char* str1, const char* str2)
{
	int i, j;
	for ( i = 0, j = 0; str1[i] != '\0'; i++,j++)
	{
		if (str1[i] != str2[j])
		{
			break;
		}
	}

	if (str1[i] == str2[j]) { return "equal"; }
	if (str1[i] < str2[j]) { return "first string is smaller"; }
	else { return "first string is greater"; }
}




int main()
{

   string str5 = { "finding" };

   string str6 = { "verbose" };

   string str7 = { "observe" };


   const char* cstr1 = { "appleSauce12*3" };

   char py[] = { "Python" };

   const char* cstr6 = { "aaa" };
   const char* cstr7 = { "aaA" };

   const char* cstr8 = { "madam" };

   //char cstr3[] = { "Apple Sauce" };

   //char let = (cstr1[1]) + 32;

   //char cstr2[] = {"apple sauce is healthy"};

   //const char * cstr3= str_add(cstr2, 6);



   std::cout<< std::boolalpha;

   //std::cout <<valid_pass(cstr1);


  // std::cout << py << std::endl;

  // reverse(py);

   //std::cout << py << std::endl;

   //std::cout <<compare(cstr6,cstr7) << std::endl;

   //std::cout << is_palindrome(cstr8) << std::endl;

   //find_dup(str5);

   bool result = is_anagram(str6, str7);

   std::cout << result << std::endl;

}


void space(int num)
{
	int i{};
	while (i <= num)
	{
		std::cout << "------------------------------------------" << std::endl;
		std::cout << std::endl;
		i++;
	}

}
int last(string& str) {
	int last_str = 0;
	int i = 0;
	for (; str[i] != '\0'; i++)
	{

	}
	last_str = i - 1;

	return last_str;
}

int min(vector<int> vec) {
	int small = vec[0];

	for (int i{}; i < vec.size(); i++)
	{
		if (vec[i] < small)
		{
			small = vec[i];
		}
	}
	return small;
}

void find_duplicate(string& str) {
	bool count = false;
	int cap_h = 26;
	vector<int> has_vec(cap_h + 1, 0);
	for (int i = 0; i < (str.size()); i++)
	{
		char alpha = str[i];
		int num = alpha - 97;
		has_vec[num]++;
	}
	space(2);
	for (int i = 0; i < (has_vec.size()); i++)
	{
		std::cout << has_vec[i] << " ";
	}
	std::cout << std::endl;
	space(2);
	for (int i = 0 ; i < (has_vec.size()); i++)
	{
		
		if (has_vec[i] > 1)
		{
			if (!count)
			{
				count = true;
				std::cout << "The Duplicate letter are: ";
			}
			
			char alpha = i + 97;
			std::cout << alpha  << " ";
		}

	}
	std::cout << std::endl;
	space(2);
}

void find_dup(string& str) 
{
	bool count = false;
	int total_alpha = 26;
	vector<int> has_vec(total_alpha + 1, 0);
	for (int i = 0; i < (str.size()); i++)
	{
		char alpha = str[i];
		int num = alpha - 97;
		has_vec[num]++;
	}
	for (int i = 0; i < (has_vec.size()); i++)
	{
		if (has_vec[i] > 1)
		{
			if (!count)
			{
				count = true;
				std::cout << "The Duplicate letter(s) are: ";
			}
			char alpha = i + 97;
			std::cout << alpha << " ";
		}

	}
	std::cout << std::endl;
}

//static_cast<char>(str[i] - 97)


bool is_anagram(const std::string& str1, const std::string& str2)
{

	bool count = false;
	int total_alpha = 26;
	vector<int> has_vec(total_alpha + 1, 0);
	for (int i = 0; i < (str1.size()); i++)
	{
		char alpha = str1[i];
		int num = alpha - 97;
		has_vec[num]++;
	}

	for (int i = 0; i < (str2.size()); i++)
	{
		char alpha = str2[i];
		int num = alpha - 97;
		has_vec[num]--;

		if (has_vec[num] < 0)
		{
			return false;
		}
	}

	for (int i = 0; i < (has_vec.size()); i++)
	{
		if (has_vec[i] < 0 )
		{
			return false;
		}

	}
	return true;
}