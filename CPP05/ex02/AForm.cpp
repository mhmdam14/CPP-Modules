#include "AForm.hpp"

AForm::AForm() : name("default"), gradeS(150), gradeE(150) 
{
	sign = false;
}

AForm::AForm(const std::string& name, const int& gradeS, const int& gradeE)
	: name(name), gradeS(gradeS), gradeE(gradeE)
{
	if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
	else if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
	sign = false;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

AForm::AForm(const AForm& other)
	: name(other.name),
	sign(other.sign),
	gradeS(other.gradeS),
	gradeE(other.gradeE)
{}

AForm::~AForm() {}


const std::string &AForm::getName() const
{
	return name;
}

int AForm::getGradeS() const
{
	return gradeS;
}

int AForm::getGradeE() const
{
	return gradeE;
}

bool AForm::getSign() const
{
	return sign;
}

void AForm::checkExecutability(Bureaucrat const& executor) const
{
	if (!sign)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeE)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeS)
		sign = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm \"" << f.getName() << "\", signed: "
		<< (f.getSign() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeS()
		<< ", grade to execute: " << f.getGradeE() << ".";
	return out;
}
