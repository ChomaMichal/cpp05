#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm& obj);
  ~RobotomyRequestForm();

  RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
  void	execute(Burecraut const &executor)const;

};
