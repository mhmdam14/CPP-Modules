#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool sign;
	const int gradeS;
	const int gradeE;
public:
	Form();
	Form(const std::string& name, const int& gradeS, const int& gradeE);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string &getName() const;
	int getGradeS() const;
	int getGradeE() const;
	bool getSign() const;

	void beSigned(const Bureaucrat& bureaucrat);

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

};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif