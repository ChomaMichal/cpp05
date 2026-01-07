#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137, "none"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137, target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other){
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	*this = obj;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Burecraut &executor)const{
	if (this->is_signed() == false){
		throw FormNotSigned();
	}
	if (this->get_grade_to_execute() > executor.getGrade()){
		throw GradeTooLowException();
	}
	std::ofstream file(this->get_target() + "_shrubbery");
	if (!file){
		std::cerr << "failed to create file";
		return ;
	}
	file <<
"my-app/\
├─ node_modules/\
├─ public/\
│  ├─ favicon.ico\
│  ├─ index.html\
│  ├─ robots.txt\
├─ src/\
│  ├─ index.css\
│  ├─ index.js\
├─ .gitignore\
├─ package.json\
├─ README.md" << std::endl;
	file.close();
}
