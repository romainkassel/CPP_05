/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/29 10:55:07 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include <exception>

Bureaucrat::Bureaucrat( void )
{
	std::cout << "Default constructor (void) called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name)
{
	std::cout << "Default constructor (std::string _name, int _grade) from Bureaucrat " << name << " called" << std::endl;
	
	try
	{
		this->checkGrade( grade );
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Grade must be between 1 and 150" << std::endl;
		std::cout << "Current grade : " << (int)grade << std::endl;
		throw e;
	}
	
	this->_grade = grade;
	
	return ;
	
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Copy constructor from Bureaucrat " << this->_name << " called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Destructor from Bureaucrat " << this->_name << " called" << std::endl;
	return ;
}

Bureaucrat  &Bureaucrat::operator=( Bureaucrat const & rhs)
{
	std::cout << "Affectation operator from Bureaucrat " << this->_name << " called" << std::endl;
	this->_grade = rhs.getGrade();
	return (*this);
}

const std::string	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade( int grade )
{
	this->_grade = grade;
	return ;
}

void	Bureaucrat::checkGrade( int grade ) const
{
	if ( (int)grade > 150)
	{
		Bureaucrat::GradeTooLowException	test1;
		throw test1;
	}
	else if ( (int)grade < 1)
	{
		Bureaucrat::GradeTooHighException	test2;
		throw test2;
	}
	else
		std::cout << "Grade approuved : " << (int)grade << std::endl;

	return ;
}

void	Bureaucrat::incrementGrade( void )
{
	try
	{
		this->checkGrade( this->_grade - 1 );
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Can't increment grade, must be between 1 and 150" << std::endl;
		std::cout << "If incrementing, grade will be " << this->_grade - 1 << std::endl;
		throw e;
	}
	
	this->_grade--;
	std::cout << "Grade has been correctly incremented!" << std::endl;
	std::cout << "From : " << this->_grade + 1 << std::endl;
	std::cout << "To : " << (int)this->_grade << std::endl;

	return ;
}

void	Bureaucrat::decrementGrade( void )
{
	try
	{
		this->checkGrade( this->_grade + 1 );
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Can't decrement grade, must be between 1 and 150" << std::endl;
		std::cout << "If decrementing, grade will be " << this->_grade + 1 << std::endl;
		throw e;
	}
	
	this->_grade++;
	std::cout << "Grade has been correctly decremented!" << std::endl;
	std::cout << "From : " << this->_grade - 1 << std::endl;
	std::cout << "To : " << (int)this->_grade << std::endl;
	
	return ;
}

void	Bureaucrat::signForm( AForm & form )
{
	try
	{
		form.beSigned( *this );
		std::cerr << "Bureaucrat " << this->_name << " signed Form " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Bureaucrat " << this->_name << " couldn’t sign Form " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm( AForm const & form )
{
	try
	{
		form.execute( *this );
		std::cerr << "Bureaucrat " << this->_name << " executed Form " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Bureaucrat " << this->_name << " couldn’t execute Form " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}

std::ostream	&operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << (int)rhs.getGrade();
	return (o);
}

