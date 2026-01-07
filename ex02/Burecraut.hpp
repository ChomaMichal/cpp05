#ifndef BURECRAUT_HPP
#define BURECRAUT_HPP
#include <string>
#include <iostream>
#include <exception>

class Form;


class Burecraut{
	public:
		Burecraut();
		Burecraut(std::string name, int grade);
		~Burecraut();
		Burecraut(const Burecraut& other);
		Burecraut&	operator=(const Burecraut& other);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(int i);
		void		decrementGrade(int i);
		void		signForm(Form &form);

		class	GradeTooLowException: public std::exception{
			public:
			const char* what() const noexcept;
		};
		class	GradeTooHighException: public std::exception{
			public:
			const char* what() const noexcept;
		};


	private:
		const std::string	name;
		int					grade;

};
#endif
