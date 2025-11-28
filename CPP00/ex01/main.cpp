#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command" << std::endl;
	}
	return 0;
}