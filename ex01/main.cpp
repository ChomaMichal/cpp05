#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void){
	std::cout << "=== Test 1: Create Bureaucrats ===" << std::endl;
	Bureaucrat Hermes;
	std::cout << Hermes.getName() << "__" << Hermes.getGrade() << std::endl;

	Bureaucrat Fry("Fry", 1);
	std::cout << Fry.getName() << "__" << Fry.getGrade() << std::endl;

	Bureaucrat Leela("Leela", 149);
	std::cout << Leela.getName() << "__" << Leela.getGrade() << std::endl;

	std::cout << "\n=== Test 2: Create Forms ===" << std::endl;
	Form form1("TPS Report", 50, 25);
	std::cout << form1;

	Form form2("Budget Request", 75, 50);
	std::cout << form2;

	std::cout << "\n=== Test 3: Try to sign forms with insufficient grade ===" << std::endl;
	Bureaucrat low_rank("Bob", 100);
	std::cout << "Bob tries to sign TPS Report (requires grade 50):" << std::endl;
	low_rank.signForm(form1);

	std::cout << "\n=== Test 4: Successfully sign a form ===" << std::endl;
	Bureaucrat high_rank("Alice", 30);
	std::cout << "Alice tries to sign TPS Report (requires grade 50):" << std::endl;
	high_rank.signForm(form1);
	std::cout << form1;

	std::cout << "\n=== Test 5: Try to sign already signed form ===" << std::endl;
	Bureaucrat another("Charlie", 20);
	std::cout << "Charlie tries to sign TPS Report (already signed):" << std::endl;
	another.signForm(form1);
	std::cout << form1;

	std::cout << "\n=== Test 6: Grade 1 (highest) signs form ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	Form hard_form("Secret Document", 1, 1);
	std::cout << hard_form;
	boss.signForm(hard_form);
	std::cout << hard_form;

	std::cout << "\n=== Test 7: Bureaucrat with exact required grade ===" << std::endl;
	Bureaucrat exact("Exact", 50);
	Form exact_form("Exact Form", 50, 25);
	exact.signForm(exact_form);
	std::cout << exact_form;

	std::cout << "\n=== Test 8: Test grade increment/decrement with form ===" << std::endl;
	Bureaucrat david("David", 100);
	Form test_form("Test Form", 75, 50);
	std::cout << "David (grade 100) tries to sign form requiring grade 75:" << std::endl;
	david.signForm(test_form);
	std::cout << "\nDavid increments grade by 30 (now grade 70):" << std::endl;
	try {
		david.incrementGrade(30);
		std::cout << "David's new grade: " << david.getGrade() << std::endl;
		david.signForm(test_form);
	} catch (std::exception &e) {
		std::cerr << e.what();
	}

	std::cout << "\n=== Test 9: Invalid form grades ===" << std::endl;
	try {
		Form invalid1("Invalid High", 0, 50);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what();
	}

	try {
		Form invalid2("Invalid Low", 151, 50);
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what();
	}

	std::cout << "\n=== Test 10: Form copy constructor and assignment ===" << std::endl;
	Form original("Original Form", 50, 25);
	Form copy(original);
	std::cout << "Original:" << std::endl << original;
	std::cout << "Copy:" << std::endl << copy;

	return 0;
}
