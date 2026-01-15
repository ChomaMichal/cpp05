#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!\n";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!\n";
}

Form::Form():name("not named"), sig(false), grade_to_sign(1), grade_to_execute(1){
}

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute):
	name(name),
	sig(false),
	grade_to_sign(grade_to_sign),
	grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}


Form::Form(const Form& other):
	name(other.name),
	sig(other.sig),
	grade_to_sign(other.grade_to_sign),
	grade_to_execute(other.grade_to_execute)
{}

Form::~Form(){
}

Form& Form::operator=(const Form& obj){
	this->sig = obj.sig;
	this->grade_to_execute = obj.grade_to_execute;
	this->grade_to_sign = obj.grade_to_sign;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form&obj){
	os << "Form name: " << obj.get_name() << "\n";
	os << "Signed: " << obj.is_signed() << "\n";
	os << "Grade to sign: " << obj.get_grade_to_sign() << "\n";
	os << "Grade to execute: " << obj.get_grade_to_execute() << std::endl;
	return(os);
}


bool	Form::is_signed(void) const{
	return (this->sig);
}

int	Form::get_grade_to_execute(void)const{
	return (this->grade_to_execute);
}

int	Form::get_grade_to_sign(void)const{
	return (this->grade_to_sign);
}

const std::string	Form::get_name(void) const{
	return (this->name);
}


void	Form::beSigned(Bureaucrat &signer){
	if (signer.getGrade() <= this->grade_to_sign){
		this->sig = true;
		return ;
	}
	throw	Form::GradeTooLowException();
}
