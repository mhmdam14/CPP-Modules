#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact()
{
	if (contactCount == 8)
		contactCount = 0;
	
	Contact& contact = contacts[contactCount];
	std::string input;

	std::cout << "Enter first Name: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	contact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	contact.setLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	contact.setNickname(input);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	contact.setPhoneNumber(input);

	std::cout << "Enter Darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty())
		return;
	contact.setSecret(input);

	contactCount++;
}

int ft_atoi(const std::string& str)
{
    int result = 0;
    size_t i = 0;
    int sign = 1;

    if (str.empty())
	{
        throw std::invalid_argument("Empty string");
	}

	while (str[i] && str[i] == ' ')
		i++;

    if (str[i] == '-' || str[i] == '+')
    {
		if (str[i] == '-')
        	sign = -1;
        i++;
    }
    while (i < str.size())
    {
        if (str[i] < '0' || str[i] > '9')
            throw std::invalid_argument("Invalid character");
        result = result * 10 + (str[i] - '0');
		i++;
    }

    return sign * result;
}


void printColumn(const std::string& str)
{
	std::string out = str;
	if (out.length() > 10)
		out = out.substr(0, 9) + ".";
	std::cout << std::setw(10) << out;
}

void PhoneBook::searchContacts()
{
	int i, index;
	std::string input;

	std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

	if (contactCount == 0)
		return;

	for (i = 0; i < 8; i++)
	{
		if (contacts[i].isEmpty())
			continue;
		std::cout << std::setw(10) << i << "|";
		printColumn(contacts[i].getFirstName());
		std::cout << "|";
		printColumn(contacts[i].getLastName());
		std::cout << "|";
		printColumn(contacts[i].getNickname());
		std::cout << std::endl;
	}

	std::cout << "Enter index of a contact to display: ";
	std::getline(std::cin, input);

	try
	{
		index = ft_atoi(input);
		if (index < 0 || index > 7 || contacts[index].isEmpty())
			throw std::out_of_range("Invalid index");
		
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
	}
	catch (...)
	{
		std::cout << "Invalid index!" << std::endl;
	}
}
