#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out)
		throw std::runtime_error("Failed to create shrubbery file");
	out << "      /\\      " << std::endl;
	out << "     /\\*\\     " << std::endl;
	out << "    /\\O\\*\\    " << std::endl;
	out << "   /*/\\/\\/\\   " << std::endl;
	out << "  /\\O/\\*\\/\\  " << std::endl;
	out << " /\\*/*/\\/\\/\\ " << std::endl;
	out << "      ||      " << std::endl;
	out << "      ||      " << std::endl;
}