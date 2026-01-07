#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const noexcept{
	return "Grade is too high!\n";
}

const char* AForm::GradeTooLowException::what() const noexcept{
	return "Grade is too low!\n";
}

const char* AForm::FormNotSigned::what() const noexcept{
	return "Form  not signed!\n";
}

AForm::AForm():sig(false), grade_to_sign(1), grade_to_execute(1){
}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute, const std::string &target):
	name(name),
	sig(false),
	grade_to_sign(grade_to_sign),
	grade_to_execute(grade_to_execute),
	target(target)
{}


AForm::AForm(const AForm& other):
	name(other.name),
	sig(other.sig),
	grade_to_sign(other.grade_to_sign),
	grade_to_execute(other.grade_to_execute)
{}

AForm::~AForm(){
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
	return (this->name);
}

void	AForm::beSigned(Burecraut &signer){
	if (signer.getGrade() <= this->grade_to_sign){
		this->sig = true;
		std::cout << "AForm: " << this->name << " was signed by "
			<< signer.getName() << std::endl;
		return ;
	}
	throw	AForm::GradeTooLowException();
}
