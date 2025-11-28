#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int gradeS;
	const int gradeE;

protected:
	void checkExecutability(Bureaucrat const & executor) const;

public:
	AForm();
	AForm(const std::string& name, const int& gradeS, const int& gradeE);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string &getName() const;
	int getGradeS() const;
	int getGradeE() const;
	bool getSign() const;

	void beSigned(const Bureaucrat& b);
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
        const char * what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif