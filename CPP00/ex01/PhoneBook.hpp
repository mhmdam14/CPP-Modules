#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContacts();
};

#endif