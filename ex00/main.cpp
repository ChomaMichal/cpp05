#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat hermes;
		std::cout << hermes << std::endl;

		Bureaucrat fry("Fry", 1);
		std::cout << fry << std::endl;
		
		try {
			fry.decrementGrade(2);
			std::cout << fry << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		Bureaucrat leela("Leela", 149);
		std::cout << leela << std::endl;
		try {
			leela.incrementGrade(2);
			std::cout << leela << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try {
			Bureaucrat bender("Bender", 151);
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		try {
			Bureaucrat invalid("Invalid", 0);
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}
	return 0;
}
