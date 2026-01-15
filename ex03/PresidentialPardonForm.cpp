#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5, "none"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5, target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	AForm::operator=(obj);
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor)const{
	if (this->is_signed() == false){
		throw FormNotSigned();
	}
	if (executor.getGrade() > this->get_grade_to_execute()){
		throw GradeTooLowException();
	}
	std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
