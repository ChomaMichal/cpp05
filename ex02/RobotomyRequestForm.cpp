#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45, "None"){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45, target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other){
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	*this = obj;
	return (*this);
}

void	RobotomyRequestForm::execute(const Burecraut &executor)const{
	if (this->is_signed() == false){
		throw FormNotSigned();
	}
	if (this->get_grade_to_execute() > executor.getGrade()){
		throw GradeTooLowException();
	}
	std::srand(std::time(0));
	if (std::rand() % 2 == 0){
		std::cout << this->get_target() <<" has been robotomized succsesfully" << std::endl;
	}
	else {
		std::cout << this->get_target() <<" has not been robotomized succsesfully" << std::endl;
	}
}
