#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	static const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	static const FormCreator creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << "Intern couldn't create form: unknown form name '" << formName << "'" << std::endl;
	return (NULL);
}