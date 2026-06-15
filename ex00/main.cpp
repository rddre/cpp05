#include "Bureaucrat.hpp"

/*     juste pour la mise en forme     */
static void print(const std::string &title)
{
	std::cout << "\n== " << title << " ==" << std::endl;
}

/*        boucle pour cree les bureaucrat avec catch des erreur      */
static void make_bureaucrat(const std::string &name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error creating " << name << " with grade " << grade << ": " << e.what() << std::endl;
	}
}

int main()
{
	print("Valid construction");
	make_bureaucrat("archi", 1);
	make_bureaucrat("andrei", 75);
	make_bureaucrat("stefani", 150);

	print("Invalid construction");
	make_bureaucrat("TooHigh", 0);
	make_bureaucrat("TooLow", 151);

	print("Grade changes");
	try
	{
		Bureaucrat b("Diane", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	print("Boundary checks");
	try
	{
		Bureaucrat top("Top", 1);
		top.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Incrementing grade 1: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bottom("Bottom", 150);
		bottom.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Decrementing grade 150: " << e.what() << std::endl;
	}

	return (0);
}
