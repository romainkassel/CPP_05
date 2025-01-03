/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/27 06:05:57 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	std::cout << "Default constructor (void) from Intern called" << std::endl;
	return ;
}

Intern::Intern( Intern const & src )
{
	std::cout << "Copy constructor from Intern called" << std::endl;
	(void)src;
	return ;
}

Intern::~Intern( void )
{
	std::cout << "Destructor from Intern called" << std::endl;
	std::cout << std::endl;
	return ;
}

Intern  &Intern::operator=( Intern const & rhs)
{
	std::cout << "Affectation operator from Intern called" << std::endl;
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm( std::string formName, std::string formTarget )
{
	int	i;
	std::string	formNameCpy;

	try
	{
		if (formName.empty() == true || formTarget.empty() == true)
		{
			Intern::EmptyParamException	EmptyParamException;
			throw EmptyParamException;
		}
		for (i=0; i < (int)formName.length(); i++)
		{
			formName[i] = std::tolower(formName[i]);
			if (std::isspace(formName[i]) == 0)
				formNameCpy.append(1, formName[i]);
		}
		if (formNameCpy.compare("shrubberycreation") != 0
			&& formNameCpy.compare("robotomyrequest") != 0
			&& formNameCpy.compare("presidentialpardon") != 0)
		{
			Intern::NoExistingFormNameException	NoExistingFormNameException;
			throw NoExistingFormNameException;
		}
		AForm* ( Intern::*functionPtrArray[3] )( std::string formTarget ) = {
			&Intern::_makeShrubberyCreationForm,
			&Intern::_makeRobotomyRequestForm,
			&Intern::_makePresidentialPardonForm
		};
		std::string	nameArray[3] = {
			"shrubberycreation",
			"robotomyrequest",
			"presidentialpardon"
		};
		for (int i = 0; i < 3; i++)
		{
			if (formNameCpy == nameArray[i])
			{
				std::cout << "Intern creates form " << formNameCpy << std::endl;
				return ((this->*functionPtrArray[i])(formTarget));
			}
		}
	}
	catch (std::exception & e)
	{
		std::cerr << "Intern couldn’t create form " << formName << " because " << e.what() << std::endl;
	}
	return (NULL);
}

AForm	*Intern::_makeShrubberyCreationForm( std::string formTarget )
{
	AForm	*newShrubberyCreationForm = new ShrubberyCreationForm(formTarget);
	return (newShrubberyCreationForm);
}

AForm	*Intern::_makeRobotomyRequestForm( std::string formTarget )
{
	AForm	*newRobotomyRequestForm = new RobotomyRequestForm(formTarget);
	return (newRobotomyRequestForm);
}

AForm	*Intern::_makePresidentialPardonForm( std::string formTarget )
{
	AForm	*newPresidentialPardonForm = new PresidentialPardonForm(formTarget);
	return (newPresidentialPardonForm);
}
