//Palindrome
#include <iostream>
#include <string.h>
#include <string>
bool isPalindrome(std::string str);
int main() {
	std::cout << "enter the word: ";
	std::string name;
	getline(std::cin, name);
	bool answer = isPalindrome(name);
	if (answer == true)
		std::cout << "Your word is a Palindrome";
	else
		std::cout << "Your word is not a palindrome";
	std::cout << std::endl;
}
bool isPalindrome(std::string str) {
	int length = str.length();
	int i;
	for (i = 0; i < length / 2; i++)
		if (str[i] != str[(length) - 1 - i])
			return false;
	return true;
}

/*
//Palindrome
#include <iostream>
#include <string.h>
#include <string>
bool isPalindrome(std::string str);
int main() {
	std::cout << "enter the word: ";
	std::string name;
	getline(std::cin, name);
	bool answer = isPalindrome(name);
	if (answer == true)
		std::cout << "Your word is a Palindrome";
	else
		std::cout << "Your word is not a palindrome";
	std::cout << std::endl;
}
bool isPalindrome(std::string str) {
	int length = str.length();
	int i;
	for (i = 0; i < length / 2; i++)
		if (str[i] != str[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(length) - 1 - i])
			return false;
	return true;
}
*/