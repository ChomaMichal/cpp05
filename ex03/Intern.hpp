#pragma once
#include "AForm.hpp"
#include <string>

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		AForm *makeForm(const std::string &name, const std::string &target);

	private:
		typedef AForm* (Intern::*FormCreator)(const std::string &target);
		
		AForm *createRobotomyRequestForm(const std::string &target);
		AForm *createPresidentialPardonForm(const std::string &target);
		AForm *createShrubberyCreationForm(const std::string &target);
};

std::ostream& operator<<(std::ostream& os, const Intern& obj);
