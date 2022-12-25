#include <iostream>
#include <string>
#include "encrypt.h"
#include <fstream>
#include "decrypt.h"

int main()
{
	using std::string;
	std::string file_name;
	std::string enter;
	std::string mode;
	std::cout << "1) Caesar encryption\n2) Caesar decryption\n\nChoice script mode: ";
	std::getline(std::cin, mode);
	{
		std::string line;
		std::cout << "\n\nWrite a filename: ";
		std::getline(std::cin, file_name);
		std::ifstream encryption_file(file_name);

		if (encryption_file.is_open()) {
			// file has opened successfully
			while (std::getline(encryption_file, line)) {
				enter += line;
			}
		}
		else {
			std::cout << "Some troubles with file. Make sure that filename written in a right way!" << std::endl;
			system("pause");
			return 0;
		}
	}
	
	std::string step_unprocessed;
	std::cout << "Enter the step for the Caesar encription way: ";
	std::getline(std::cin, step_unprocessed);
	int step = std::stoi(step_unprocessed);
	if (mode == "1")
	{
		string encrypted = encryption::caesar_encryption(enter, step);
		std::ofstream write_file("encrypted.txt");
		if (write_file.is_open()) {
			write_file << encrypted;
			std::cout << "encrypted.txt has been created!" << std::endl;
			write_file.close();
		}
	}
	else if (mode == "2") {
		string decrypted = decryption::caesar_decryption(enter, step);
		std::ofstream write_file("decrypted.txt");
		if (write_file.is_open()) {
			write_file << decrypted;
			std::cout << "decrypted.txt has been created!" << std::endl;
			write_file.close();
		}
	}
	// std::cout << "Decrypted: " << decryption::caesar_decryption(encrypted, step) << std::endl;
	system("pause");
}
