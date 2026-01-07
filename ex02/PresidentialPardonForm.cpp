#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5, "none"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5, target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other){
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	*this = obj;
	return (*this);
}

void	PresidentialPardonForm::execute(const Burecraut &executor)const{
	if (this->is_signed() == false){
		throw FormNotSigned();
	}
	if (this->get_grade_to_execute() > executor.getGrade()){
		throw GradeTooLowException();
	}
	std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
