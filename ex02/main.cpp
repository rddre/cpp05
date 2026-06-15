#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void print(const std::string &title)
{
	std::cout << "\n== " << title << " ==" << std::endl;
}

int main()
{
	Bureaucrat chief("Chief", 1);
	Bureaucrat worker("Worker", 140);

	print("Shrubbery - execute without signing");
	ShrubberyCreationForm home("home");
	worker.executeForm(home);

	print("Shrubbery - sign and execute");
	worker.signForm(home);
	worker.executeForm(home);
	chief.executeForm(home);

	print("Robotomy - sign and execute several times");
	RobotomyRequestForm robot("Bender");
	chief.signForm(robot);
	for (int i = 0; i < 4; ++i)
		chief.executeForm(robot);

	print("Presidential pardon - low grade then high grade");
	PresidentialPardonForm pardon("Arthur Dent");
	worker.signForm(pardon);
	chief.signForm(pardon);
	worker.executeForm(pardon);
	chief.executeForm(pardon);

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

	return (0);
}
