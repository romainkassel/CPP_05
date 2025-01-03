/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/27 00:33:11 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "Default constructor (void) called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const & target ) :
AForm("PresidentialPardonForm", 25, 5),
_target(target)
{
	std::cout << "Default constructor (std::string target) from PresidentialPardonForm called" << std::endl;
	return ;
	
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) :
AForm(src), _target(src.getTarget())
{
	std::cout << "Copy constructor from PresidentialPardonForm called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "Destructor from PresidentialPardonForm " << this->getName() << " called" << std::endl;
	return ;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs)
{
	std::cout << "Affectation operator from PresidentialPardonForm " << this->getName() << " called" << std::endl;
	this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

const std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void	PresidentialPardonForm::executeFormAction( void ) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

	return ;
}

std::ostream	&operator<<( std::ostream & o, PresidentialPardonForm const & rhs )
{
	o << "Name : " << rhs.getName() << std::endl;
	o << "Is signed : " << rhs.getIsSigned() << std::endl;
	o << "Grade for sign : " << (int)rhs.getGradeSign() << std::endl;
	o << "Grade for execute : " << (int)rhs.getGradeExecute() << std::endl;
	o << "Target : " << rhs.getTarget() << std::endl; 
	return (o);
}
