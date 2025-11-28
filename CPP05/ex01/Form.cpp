#include "Form.hpp"

Form::Form() : name("default"), gradeS(150), gradeE(150) 
{
	sign = false;
}

Form::Form(const std::string& name, const int& gradeS, const int& gradeE)
	: name(name), gradeS(gradeS), gradeE(gradeE)
{
	if (gradeS < 1 || gradeE < 1)
		throw GradeTooHighException();
	else if (gradeS > 150 || gradeE > 150)
		throw GradeTooLowException();
	sign = false;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

Form::Form(const Form& other)
	: name(other.name),
	sign(other.sign),
	gradeS(other.gradeS),
	gradeE(other.gradeE)
{}

Form::~Form() {}


const std::string& Form::getName() const
{
	return name;
}

int Form::getGradeS() const
{
	return gradeS;
}

int Form::getGradeE() const
{
	return gradeE;
}

bool Form::getSign() const
{
	return sign;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeS)
		sign = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form \"" << f.getName() << "\", signed: "
		<< (f.getSign() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeS()
		<< ", grade to execute: " << f.getGradeE() << ".";
	return out;
}
