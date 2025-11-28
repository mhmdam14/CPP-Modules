#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other)
    : AForm(other), target(other.target) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & other) {
    if (this != &other)
        target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecutability(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
