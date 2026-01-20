#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(int i);
		void decrementGrade(int i);
		void signForm(Form &form);

		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		const std::string name;
		int grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
