#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void){
	std::cout << "=== Test 1: Create Bureaucrats ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 100);
	Bureaucrat lowest("Lowest", 150);

	std::cout << "\n=== Test 2: Create Forms ===" << std::endl;
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Marvin");

	std::cout << "\n=== Test 3: Display Forms ===" << std::endl;
	std::cout << shrubbery;
	std::cout << robotomy;
	std::cout << pardon;

	std::cout << "\n=== Test 4: Try to execute unsigned form ===" << std::endl;
	try {
		boss.executeForm(robotomy);
	} catch (std::exception &e) {
		std::cerr << e.what();
	}

	std::cout << "\n=== Test 5: Sign forms ===" << std::endl;
	boss.signForm(shrubbery);
	boss.signForm(robotomy);
	boss.signForm(pardon);
	std::cout << std::endl << shrubbery;

	std::cout << "\n=== Test 6: Execute PresidentialPardonForm with high enough grade ===" << std::endl;
	boss.executeForm(pardon);

	std::cout << "\n=== Test 7: Try to execute form with insufficient grade ===" << std::endl;
	lowest.executeForm(robotomy);

	std::cout << "\n=== Test 8: Execute RobotomyRequestForm (50% success rate) ===" << std::endl;
	std::cout << "Attempting robotomy 5 times..." << std::endl;
	for (int i = 0; i < 5; i++) {
		boss.executeForm(robotomy);
	}

	std::cout << "\n=== Test 9: Execute ShrubberyCreationForm ===" << std::endl;
	boss.executeForm(shrubbery);
	std::cout << "File 'garden_shrubbery' should be created in current directory." << std::endl;

	std::cout << "\n=== Test 10: Try to sign form with insufficient grade ===" << std::endl;
	Bureaucrat insufficient("Insufficient", 150);
	ShrubberyCreationForm another_shrubbery("park");
	insufficient.signForm(another_shrubbery);
	std::cout << another_shrubbery;

	std::cout << "\n=== Test 11: Execute with exactly required grade ===" << std::endl;
	Bureaucrat exact_executor("Exact", 5);
	PresidentialPardonForm test_pardon("TestTarget");
	boss.signForm(test_pardon);
	std::cout << "Executor with grade 5 executing form requiring grade 5:" << std::endl;
	exact_executor.executeForm(test_pardon);

	std::cout << "\n=== Test 12: Chain signing and executing ===" << std::endl;
	RobotomyRequestForm chain_robotomy("C3PO");
	Bureaucrat mid_signer("MidSigner", 72);
	Bureaucrat mid_executor("MidExecutor", 45);
	
	mid_signer.signForm(chain_robotomy);
	std::cout << chain_robotomy;
	mid_executor.executeForm(chain_robotomy);

	std::cout << "\n=== Test 13: Try executing with grade too low ===" << std::endl;
	ShrubberyCreationForm hard_shrubbery("forest");
	Bureaucrat almost("Almost", 138);  // Requires 137 to execute
	boss.signForm(hard_shrubbery);
	std::cout << "Almost (grade 138) tries to execute form requiring grade 137:" << std::endl;
	almost.executeForm(hard_shrubbery);

	return 0;
}
