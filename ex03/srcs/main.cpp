/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/28 05:52:13 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	testBureaucratCopyByAffectation();
void	testBureaucratCopyByConstructor();

void	testShrubberyCreationFormCopyByAffectation();
void	testShrubberyCreationFormCopyByConstructor();

void	testRobotomyRequestFormCopyByAffectation();
void	testRobotomyRequestFormCopyByConstructor();

void	testPresidentialPardonFormCopyByAffectation();
void	testPresidentialPardonFormCopyByConstructor();

int	main( int argc, char **argv )
{
	///////////////////

	if (argc != 3)
	{
		std::cerr << "This program strictly accepts 2 arguments" << std::endl;
		return (1);
	}

	///////////////////

	std::string	formName(argv[1]);
	std::string	formTarget(argv[2]);

	///////////////////
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mIntern\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	
	std::cout << std::endl;
	std::cout << "\033[0;35mCREATION\033[0m" << std::endl;
	std::cout << std::endl;
		
	// Creation of intern instance
	Intern someRandomIntern;

	///////////////////
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mmakeForm -> ARGUMENTS : \033[0m" << formName << ", " << formTarget << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	
	// Initialization of a form ptr
	AForm*	rrf = NULL;
	
	// makeForm
	
	std::cout << std::endl;
	std::cout << "\033[0;32mmakeForm from Intern\033[0m" << std::endl;
	std::cout << std::endl;
	
	rrf = someRandomIntern.makeForm(formName, formTarget);

	std::cout << std::endl;

	// Attribute display (<< operator)
	std::cout << "\033[0;32mDisplay of Form attributes\033[0m" << std::endl;
	std::cout << std::endl;
	if (rrf)
	{
		std::cout << *rrf;
		std::cout << "Target : " << rrf->getTarget() << std::endl;
	}
	else
		std::cout << "Nothing to display" << std::endl;

	// Delete of AForm ptr
	std::cout << std::endl;
	std::cout << "\033[0;32mDestruction of Form ptr\033[0m" << std::endl;
	std::cout << std::endl;
	if (rrf)
		delete (rrf);
	else
		std::cout << "Nothing to destroy" << std::endl;

	// Destruction of Intern instance
	std::cout << std::endl;
	std::cout << "\033[0;32mDestruction of Intern instance\033[0m" << std::endl;
	std::cout << std::endl;

	///////////////////

	return (0);

}