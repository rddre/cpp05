#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void print(const std::string &title)
{
	std::cout << "\n== " << title << " ==" << std::endl;
}

int main()
{
	Bureaucrat SlaveBoss("SlaveBoss", 1);
	Bureaucrat ModernSlave("ModernSlave", 140);

	print("Shrubbery - execute without signing");
	ShrubberyCreationForm home("home");
	ModernSlave.executeForm(home);

	print("Shrubbery - sign and execute");
	ModernSlave.signForm(home);
	ModernSlave.executeForm(home);
	SlaveBoss.executeForm(home);

	print("Robotomy - sign and execute several times");
	RobotomyRequestForm robot("Andrei");
	SlaveBoss.signForm(robot);
	for (int i = 0; i < 4; ++i)
		SlaveBoss.executeForm(robot);

	print("Presidential pardon - low grade then high grade");
	PresidentialPardonForm pardon("Arthur Dent");
	ModernSlave.signForm(pardon);
	SlaveBoss.signForm(pardon);
	ModernSlave.executeForm(pardon);
	SlaveBoss.executeForm(pardon);

	print("Invalid bureaucrat and form grades");
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat creation failed: " << e.what() << std::endl;
	}
	try
	{
		ShrubberyCreationForm s("park");
		std::cout << s << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Form creation failed: " << e.what() << std::endl;
	}
/*                           test des interne                        */
	print("Intern form factory");
	Intern someRandomIntern;
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		SlaveBoss.signForm(*rrf);
		SlaveBoss.executeForm(*rrf);
		delete rrf;
	}

	AForm *invalidForm = someRandomIntern.makeForm("coffee form", "office");
	if (invalidForm)
		delete invalidForm;

	return (0);
}
