#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form {
	public:
		Form();
		Form(const std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form& obj);
		~Form();

		Form& operator=(const Form& obj);

		bool				is_signed(void)const;
		int					get_grade_to_sign(void)const;
		int					get_grade_to_execute(void)const;
		const std::string	get_name(void)const;
		void				beSigned(const Bureaucrat &singer);

		class	GradeTooLowException: public std::exception{
			public:
			const char* what() const throw();
		};
		class	GradeTooHighException: public std::exception{
			public:
			const char* what() const throw();
		};

	private:
		const std::string	name;
		bool				sig;
		int					grade_to_sign;
		int					grade_to_execute;
};

std::ostream&	operator<<(std::ostream& os, const Form &obj);
