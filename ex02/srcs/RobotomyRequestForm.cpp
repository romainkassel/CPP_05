/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/27 00:33:11 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>

bool	RobotomyRequestForm::_shouldRobotomyFail = true;

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Default constructor (void) called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const & target ) :
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
	std::cout << "Default constructor (std::string target) from RobotomyRequestForm called" << std::endl;

	return ;
	
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) :
AForm(src), _target(src.getTarget())
{
	std::cout << "Copy constructor from RobotomyRequestForm called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "Destructor from RobotomyRequestForm " << this->getName() << " called" << std::endl;
	return ;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs)
{
	std::cout << "Affectation operator from RobotomyRequestForm " << this->getName() << " called" << std::endl;
	this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

const std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::executeFormAction( void ) const
{
	std::cout << "Makes some drilling noises" << std::endl;

	try
	{
		if (this->_shouldRobotomyFail == false)
		{
			RobotomyRequestForm::RobotomyFailException	RobotomyFailException;
			throw RobotomyFailException;
		}
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
		this->_shouldRobotomyFail = false;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		this->_shouldRobotomyFail = true;
	}

	return ;
}

std::ostream	&operator<<( std::ostream & o, RobotomyRequestForm const & rhs )
{
	o << "Name : " << rhs.getName() << std::endl;
	o << "Is signed : " << rhs.getIsSigned() << std::endl;
	o << "Grade for sign : " << (int)rhs.getGradeSign() << std::endl;
	o << "Grade for execute : " << (int)rhs.getGradeExecute() << std::endl;
	o << "Target : " << rhs.getTarget() << std::endl; 
	return (o);
}
