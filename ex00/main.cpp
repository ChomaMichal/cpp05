#include "Burecraut.hpp"

int main(void){
	Burecraut Hermes;
	std::cout << Hermes.getName() << "__" << Hermes.getGrade() << std::endl;


	Burecraut Fry("Fry", 1);
	std::cout << Fry.getName() << "__" << Fry.getGrade() << std::endl;
	try{
		Fry.decrementGrade(2);
		std::cout << Fry.getName() << "__" << Fry.getGrade() << std::endl;
	} catch (std::exception& e){
		std::cerr << e.what();
	}
	std::cout << Fry.getName() << "__" << Fry.getGrade() << std::endl;
	Fry.incrementGrade(69);
	std::cout << Fry.getName() << "__" << Fry.getGrade() << std::endl;

	Burecraut Leela("Leela", 149);
	std::cout << Leela.getName() << "__" << Leela.getGrade() << std::endl;
	try{
		Fry.incrementGrade(2);
		std::cout << Leela.getName() << "__" << Leela.getGrade() << std::endl;
	} catch (std::exception& e){
		std::cerr << e.what();
	}
	std::cout << Leela.getName() << "__" << Leela.getGrade() << std::endl;
	Leela.decrementGrade(69);
	std::cout << Leela.getName() << "__" << Leela.getGrade() << std::endl;

	try {
		Burecraut Bender("Bender", 151);
		std::cout << Bender.getName() << "__" << Bender.getGrade() << std::endl;
	} catch (std::exception& e){
		std::cerr << e.what();
	}
	try {
		Burecraut Bender("Bender", 0);
		std::cout << Bender.getName() << "__" << Bender.getGrade() << std::endl;
	} catch (std::exception& e){
		std::cerr << e.what();
	}
	
}
