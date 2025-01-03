/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/29 10:50:38 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form( void ) :
_isSigned(false),
_gradeSign('\0'),
_gradeExecute('\0')
{
	std::cout << "Default constructor (void) called" << std::endl;
	return ;
}

Form::Form( std::string name, int gradeSign, int gradeExecute ) :
_name(name),
_gradeSign(gradeSign),
_gradeExecute(gradeExecute)
{
	std::cout << "Default constructor (std::string name, int gradeSign, int gradeExecute) from Form " << name << " called" << std::endl;
	
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

Form::Form( Form const & src ) :
_name(src.getName()),
_isSigned(src.getIsSigned()),
_gradeSign(src.getGradeSign()),
_gradeExecute(src.getGradeExecute())
{
	std::cout << "Copy constructor from Form " << this->_name << " called" << std::endl;
	return ;
}

Form::~Form( void )
{
	std::cout << "Destructor from Form " << this->_name << " called" << std::endl;
	return ;
}

Form  &Form::operator=( Form const & rhs)
{
	std::cout << "Affectation operator from Form " << this->_name << " called" << std::endl;
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

const std::string	Form::getName( void ) const
{
	return (this->_name);
}

bool	Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int	Form::getGradeSign(void ) const
{
	return (this->_gradeSign);
}

int	Form::getGradeExecute( void) const
{
	return (this->_gradeExecute);
}

void	Form::setIsSigned( bool isSigned )
{
	this->_isSigned = isSigned;
	return ;
}

void	Form::checkGrade( int grade ) const
{
	if ( (int)grade > 150)
	{
		Form::GradeTooLowException	test1;
		throw test1;
	}
	else if ( (int)grade < 1)
	{
		Form::GradeTooHighException	test2;
		throw test2;
	}
	else
		std::cout << "Grade approuved : " << (int)grade << std::endl;

	return ;
}

void	Form::beSigned( Bureaucrat const & bureaucrat )
{
	if (bureaucrat.getGrade() > this->_gradeSign)
	{
		Form::GradeTooLowException	GradeTooLowException;
		throw GradeTooLowException;
	}
	this->_isSigned = true;

	return ;
}

std::ostream	&operator<<( std::ostream & o, Form const & rhs )
{
	o << "Name : " << rhs.getName() << std::endl;
	o << "Is signed : " << rhs.getIsSigned() << std::endl;
	o << "Grade for sign : " << (int)rhs.getGradeSign() << std::endl;
	o << "Grade for execute : " << (int)rhs.getGradeExecute() << std::endl;
	return (o);
}

