#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void){
	std::cout << "=== Test 1: Create Bureaucrats and Intern ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat low("Low", 100);
	Bureaucrat lowest("Lowest", 150);
	Intern intern;

	std::cout << "\n=== Test 2: Intern creates valid forms ===" << std::endl;
	AForm* form1 = intern.makeForm("robotomy request", "Bender");
	AForm* form2 = intern.makeForm("presidential pardon", "Marvin");
	AForm* form3 = intern.makeForm("shrubbery creation", "garden");

	std::cout << "\n=== Test 3: Display created forms ===" << std::endl;
	if (form1) std::cout << *form1;
	if (form2) std::cout << *form2;
	if (form3) std::cout << *form3;

	std::cout << "\n=== Test 4: Intern tries to create invalid form ===" << std::endl;
	AForm* invalid = intern.makeForm("invalid form name", "target");
	std::cout << "Invalid form pointer is: " << (invalid ? "not NULL" : "NULL") << std::endl;

	std::cout << "\n=== Test 5: Bureaucrat signs forms created by intern ===" << std::endl;
	boss.signForm(*form1);
	boss.signForm(*form2);
	boss.signForm(*form3);

	std::cout << "\n=== Test 6: Bureaucrat executes forms created by intern ===" << std::endl;
	boss.executeForm(*form1);
	boss.executeForm(*form2);
	boss.executeForm(*form3);

	std::cout << "\n=== Test 7: Mid-grade bureaucrat tries forms ===" << std::endl;
	mid.signForm(*form1);
	mid.executeForm(*form1);

	std::cout << "\n=== Test 8: Low-grade bureaucrat cannot execute high-grade forms ===" << std::endl;
	low.signForm(*form3);
	low.executeForm(*form3);

	std::cout << "\n=== Test 9: Test all form types separately ===" << std::endl;
	AForm* robotomy = intern.makeForm("robotomy request", "C3PO");
	AForm* pardon = intern.makeForm("presidential pardon", "Prisoner");
	AForm* shrubbery = intern.makeForm("shrubbery creation", "park");

	std::cout << "\nRobotomy form created:" << std::endl;
	boss.signForm(*robotomy);
	std::cout << "Executing robotomy 3 times for testing:" << std::endl;
	for (int i = 0; i < 3; i++) {
		boss.executeForm(*robotomy);
	}

	std::cout << "\nPardon form created:" << std::endl;
	boss.signForm(*pardon);
	boss.executeForm(*pardon);

	std::cout << "\nShrubbery form created:" << std::endl;
	boss.signForm(*shrubbery);
	boss.executeForm(*shrubbery);

	std::cout << "\n=== Test 10: Try various invalid form names ===" << std::endl;
	intern.makeForm("", "target");
	intern.makeForm("robotomy", "target");
	intern.makeForm("ROBOTOMY REQUEST", "target");
	intern.makeForm("shrubbery", "target");
	intern.makeForm("president pardon", "target");

	std::cout << "\n=== Test 11: Case sensitivity ===" << std::endl;
	AForm* case_test = intern.makeForm("Robotomy Request", "target");
	std::cout << "Case-sensitive test (should fail): " << (case_test ? "Created" : "Failed") << std::endl;

	std::cout << "\n=== Test 12: Execute unsigned form ===" << std::endl;
	AForm* unsigned_form = intern.makeForm("presidential pardon", "TestTarget");
	std::cout << "Form created but not signed, trying to execute:" << std::endl;
	boss.executeForm(*unsigned_form);

	std::cout << "\n=== Test 13: Copy intern and test functionality ===" << std::endl;
	Intern intern2;
	AForm* copy_test = intern2.makeForm("robotomy request", "Copy");
	std::cout << "Intern copy created form successfully" << std::endl;
	boss.signForm(*copy_test);
	boss.executeForm(*copy_test);

	std::cout << "\n=== Test 14: Clean up dynamically allocated forms ===" << std::endl;
	delete form1;
	delete form2;
	delete form3;
	delete robotomy;
	delete pardon;
	delete shrubbery;
	delete unsigned_form;
	delete copy_test;
	std::cout << "All forms deleted successfully" << std::endl;

	std::cout << "\n=== Test 15: Lowest grade bureaucrat with low-grade form ===" << std::endl;
	AForm* easy_form = intern.makeForm("presidential pardon", "EasyTarget");
	boss.signForm(*easy_form);
	lowest.executeForm(*easy_form);
	delete easy_form;

	return 0;
}
