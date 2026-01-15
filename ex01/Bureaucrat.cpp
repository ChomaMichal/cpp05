#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
 	return "Grade is too high!\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

Bureaucrat::Bureaucrat(): name("Hermes Conrad"), grade(35){}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade){}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "Burecrat " << this->name << " with grade " << this->grade;
	std::cout << " was undied" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	this->grade = other.grade;
	return (*this);
}

void	Bureaucrat::decrementGrade(int i)
{
	int		tmp;
	
	tmp = this->grade - i;
	if (tmp < 1)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->grade = tmp;
}

void	Bureaucrat::incrementGrade(int i)
{
	int		tmp;
	
	tmp = this->grade + i;
	if (tmp < 1)
		throw GradeTooHighException();
	if (tmp > 150)
		throw GradeTooLowException();
	this->grade = tmp;
}


Bureaucrat::~Bureaucrat(){
	std::cout << "Burecrat " << this->name << " with grade " << this->grade;
	std::cout << " was unundied" << std::endl;
}

int		Bureaucrat::getGrade(void) const{
	return (this->grade);
}

std::string	Bureaucrat::getName(void) const{
	return (this->name);
}

void	Bureaucrat::signForm(Form &form){
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.get_name() << std::endl;
	} catch (Form::GradeTooLowException &e) {
		std::cout << this->name << " couldn't sign " << form.get_name() 
			<< " because " << e.what();
	}
}

