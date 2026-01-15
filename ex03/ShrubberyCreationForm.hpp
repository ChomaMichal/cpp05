#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm& obj);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
  void	execute(Bureaucrat const &executor)const;

};
