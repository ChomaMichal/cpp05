#ifndef BURECRAUT_HPP
#define BURECRAUT_HPP
#include <string>
#include <iostream>
#include <exception>

class Burecraut{
	public:
		Burecraut();
		Burecraut(std::string name, int grade);
		~Burecraut();
		Burecraut(const Burecraut& other);
		Burecraut& operator=(const Burecraut& other);
		std::string			getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(int i);
		void				decrementGrade(int i);
	private:
		const std::string	name;
		int					grade;

};
#endif
