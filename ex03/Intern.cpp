#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
	names[0] = "robotomy request";
	names[1] = "presidential pardon";
	names[2] = "shrubbery creation";
};
Intern::~Intern() {};
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
	int form = -1;
	int i = 0;
	for (; i < 3; i++) {
		if (name == names[i])
			form = i;
	}
	if (form == -1) {
		std::cerr << "Error: invalid form name \"" << name << "\"" << std::endl;
		return (NULL);
	}
	switch (form) {
	case (0): {
		RobotomyRequestForm *ptr = new RobotomyRequestForm(target);
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return (ptr);
	}
	case (1): {
		PresidentialPardonForm *ptr = new PresidentialPardonForm(target);
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return (ptr);
	}
	case (2): {
		ShrubberyCreationForm *ptr = new ShrubberyCreationForm(target);
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return (ptr);
	}
	}
	std::cerr << "Error: invalid form name \"" << name << "\"" << std::endl;
	return (NULL);
}
