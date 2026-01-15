#pragma once
#include "AForm.hpp"
#include <string>

class Intern {
public:
  Intern();
  ~Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  AForm *makeForm(const std::string &name, const std::string &target);

private:
  std::string names[3];
  void initNames();
};
