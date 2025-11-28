#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{}

static AForm* makeShrub(std::string const& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* makeRobo(std::string const& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* makePardon(std::string const& target)
{
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(std::string const& name, std::string const& target) const
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

	AForm* (*creators[3])(std::string const&) = { makeShrub, makeRobo, makePardon };

    for (int i = 0; i < 3; i++) {
        if (name == names[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern couldn’t find the form \"" << name << "\"." << std::endl;
    return NULL;
}
