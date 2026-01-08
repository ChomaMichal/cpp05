#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class AForm {
	public:
		AForm();
		AForm(const std::string &name, int grade_to_sign, int grade_to_execute, const std::string &target);
		AForm(const AForm& obj);
		virtual ~AForm() = 0;

		virtual AForm& operator=(const AForm& obj);

		bool				is_signed(void)const;
		int					get_grade_to_sign(void)const;
		int					get_grade_to_execute(void)const;
		const std::string	get_name(void)const;
		const std::string	get_target(void)const;
		void				beSigned(Bureaucrat &singer);

		class	GradeTooLowException: public std::exception{
			public:
			const char* what() const noexcept;
		};
		class	GradeTooHighException: public std::exception{
			public:
			const char* what() const noexcept;
		};
		class	FormNotSigned: public std::exception{
			public:
			const char* what() const noexcept;
		};

	private:
		const std::string	name;
		const std::string	target;
		bool				sig;
		int					grade_to_sign;
		int					grade_to_execute;
};

std::ostream&	operator<<(std::ostream& os, const AForm &obj);
