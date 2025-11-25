#include "Burecraut.hpp"

class Burecraut::GradeTooHighException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Grade is too high!\n";
    }
};

class Burecraut::GradeTooLowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Grade is too low!\n";
    }
};

Burecraut::Burecraut(): name("Hermes Conrad"), grade(35){}

Burecraut::Burecraut(const Burecraut& other): name(other.name), grade(other.grade){}

Burecraut::Burecraut(std::string name, int grade) : name(name){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "Burecrat " << this->name << " with grade " << this->grade;
	std::cout << " was undied" << std::endl;
}

Burecraut&	Burecraut::operator=(const Burecraut &other)
{
	this->grade = other.grade;
	return (*this);
}

void	Burecraut::decrementGrade(int i)
{
	int		tmp;
	
	tmp = this->grade - i;
	if (tmp < 1)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->grade = tmp;
}

void	Burecraut::incrementGrade(int i)
{
	int		tmp;
	
	tmp = this->grade + i;
	if (tmp < 1)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->grade = tmp;
}


Burecraut::~Burecraut(){
	std::cout << "Burecrat " << this->name << " with grade " << this->grade;
	std::cout << " was unundied" << std::endl;
}

int		Burecraut::getGrade(void) const{
	return (this->grade);
}

std::string	Burecraut::getName(void) const{
	return (this->name);
}

