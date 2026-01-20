#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	std::string formNames[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	
	FormCreator creators[3] = {
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm,
		&Intern::createShrubberyCreationForm
	};
	
	for (int i = 0; i < 3; i++) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	
	std::cerr << "Error: invalid form name \"" << name << "\"" << std::endl;
	return (NULL);
}
