#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

Bureaucrat::Bureaucrat(): name("Hermes Conrad"), grade(35) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	this->grade = other.grade;
	return (*this);
}

void Bureaucrat::decrementGrade(int i) {
	int tmp;
	
	tmp = this->grade + i;
	if (tmp < 1)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->grade = tmp;
}

void Bureaucrat::incrementGrade(int i) {
	int tmp;
	
	tmp = this->grade - i;
	if (tmp < 1)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->grade = tmp;
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

std::string Bureaucrat::getName(void) const {
	return (this->name);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

