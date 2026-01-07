#pragma once
#include "AForm.hpp"


class PresidentialPardonForm : public AForm{
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm& obj);
  ~PresidentialPardonForm();

  PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
  void	execute(Burecraut const &executor)const;

};
