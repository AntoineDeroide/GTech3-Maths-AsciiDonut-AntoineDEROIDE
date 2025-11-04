#include <iostream>
#include <windows.h>

// 1.1
int main(int argc, char** argv)
{
	std::cout << "Hello World !\n";

// 1.2
	std::cout << "Hello...\n";
	std::cout << "\033[2J"; // console clear
	std::cout << "...hello?\n";

	std::cout << "\033[H"; // Move cursor to home position

	std::cout << "\033[?25l"; // Make cursor invisible
	std::cout << "\033[?25h"; // Make cursor visible


}

