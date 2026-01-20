#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high!\n";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low!\n";
}

const char* AForm::FormNotSigned::what() const throw(){
	return "Form  not signed!\n";
}

AForm::AForm():name(""), target(""), sig(false), grade_to_sign(1), grade_to_execute(1){
}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute, const std::string &target):
	name(name),
	target(target),
	sig(false),
	grade_to_sign(grade_to_sign),
	grade_to_execute(grade_to_execute)
{}


AForm::AForm(const AForm& other):
	name(other.name),
	target(other.target),
	sig(other.sig),
	grade_to_sign(other.grade_to_sign),
	grade_to_execute(other.grade_to_execute)
{}

AForm::~AForm() {
}

AForm& AForm::operator=(const AForm& obj){
	this->sig = obj.sig;
	this->grade_to_execute = obj.grade_to_execute;
	this->grade_to_sign = obj.grade_to_sign;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const AForm&obj){
	os << "AForm name: " << obj.get_name() << "\n";
	os << "Signed: " << obj.is_signed() << "\n";
	os << "Grade to sign: " << obj.get_grade_to_sign() << "\n";
	os << "Grade to execute: " << obj.get_grade_to_execute() << std::endl;
	return(os);
}


bool	AForm::is_signed(void) const{
	return (this->sig);
}

int	AForm::get_grade_to_execute(void)const{
	return (this->grade_to_execute);
}

int	AForm::get_grade_to_sign(void)const{
	return (this->grade_to_sign);
}

const std::string	AForm::get_name(void) const{
	return (this->name);
}

const std::string	AForm::get_target(void) const{
	return (this->target);
}

void AForm::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() <= this->grade_to_sign) {
		this->sig = true;
		return ;
	}
	throw AForm::GradeTooLowException();
}
