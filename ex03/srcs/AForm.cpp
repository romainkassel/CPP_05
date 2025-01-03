/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/29 10:54:56 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm( void ) :
_isSigned(false),
_gradeSign('\0'),
_gradeExecute('\0')
{
	std::cout << "Default constructor (void) called" << std::endl;
	return ;
}

AForm::AForm( std::string name, int gradeSign, int gradeExecute ) :
_name(name),
_gradeSign(gradeSign),
_gradeExecute(gradeExecute)
{
	std::cout << "Default constructor (std::string name, int gradeSign, int gradeExecute) from AForm " << name << " called" << std::endl;
	
	try
	{
		this->checkGrade( gradeSign );
		this->checkGrade( gradeExecute );
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Grade must be between 1 and 150" << std::endl;
		throw e;
	}

	this->_isSigned = false;
	
	return ;
	
}

AForm::AForm( AForm const & src ) :
_name(src.getName()),
_isSigned(src.getIsSigned()),
_gradeSign(src.getGradeSign()),
_gradeExecute(src.getGradeExecute())
{
	std::cout << "Copy constructor from AForm " << this->_name << " called" << std::endl;
	return ;
}

AForm::~AForm( void )
{
	std::cout << "Destructor from AForm " << this->_name << " called" << std::endl;
	return ;
}

AForm  &AForm::operator=( AForm const & rhs)
{
	std::cout << "Affectation operator from AForm " << this->_name << " called" << std::endl;
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

const std::string	AForm::getName( void ) const
{
	return (this->_name);
}

bool	AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int	AForm::getGradeSign(void ) const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExecute( void) const
{
	return (this->_gradeExecute);
}

void	AForm::setIsSigned( bool isSigned )
{
	this->_isSigned = isSigned;
	return ;
}

void	AForm::checkGrade( int grade ) const
{
	if ( (int)grade > 150)
	{
		AForm::GradeTooLowException	test1;
		throw test1;
	}
	else if ( (int)grade < 1)
	{
		AForm::GradeTooHighException	test2;
		throw test2;
	}
	else
		std::cout << "Grade approuved : " << (int)grade << std::endl;

	return ;
}

void	AForm::beSigned( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > this->_gradeSign)
	{
		AForm::GradeTooLowException	GradeTooLowException;
		throw GradeTooLowException;
	}
	this->_isSigned = true;

	return ;
}

void	AForm::execute( Bureaucrat const & executor ) const
{
	if (this->_isSigned == false)
	{
		AForm::FormNotSignedException	FormNotSignedException;
		throw FormNotSignedException;
	}
	else if (executor.getGrade() > this->_gradeExecute)
	{
		AForm::GradeTooLowException		GradeTooLowException;
		throw GradeTooLowException;
	}
	this->executeFormAction();
	
	return ;
}

std::ostream	&operator<<( std::ostream & o, AForm const & rhs )
{
	o << "Name : " << rhs.getName() << std::endl;
	o << "Is signed : " << rhs.getIsSigned() << std::endl;
	o << "Grade for sign : " << (int)rhs.getGradeSign() << std::endl;
	o << "Grade for execute : " << (int)rhs.getGradeExecute() << std::endl;
	return (o);
}

