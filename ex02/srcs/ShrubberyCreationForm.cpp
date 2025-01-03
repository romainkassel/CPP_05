/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/29 10:53:18 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default constructor (void) called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const & target ) :
AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{
	std::cout << "Default constructor (std::string target) from ShrubberyCreationForm called" << std::endl;
	return ;
	
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) :
AForm(src), _target(src.getTarget())
{
	std::cout << "Copy constructor from ShrubberyCreationForm called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "Destructor from ShrubberyCreationForm " << this->getName() << " called" << std::endl;
	return ;
}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs)
{
	std::cout << "Affectation operator from ShrubberyCreationForm " << this->getName() << " called" << std::endl;
	this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

const std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::executeFormAction( void ) const
{
	std::string	str;
	std::string	ascii_trees[9];
	
	str.append(this->_target);
	str.append("_shrubbery");
	std::ofstream	ofs(str.c_str());

	ascii_trees[0] = "       ,,,.   ,888888/88,  .oo8888o.";
	ascii_trees[1] = "    ,&%%&%&&%,88888/888888,8888\\88/8o";
	ascii_trees[2] = "   ,%&\\%&&%&&%,888\\888/88888\\88888/88'";
	ascii_trees[3] = "   %&&%&%&/%&&%88\\88/ /88888888\\88888'";
	ascii_trees[4] = "   %&&%/ %&%%&&88\\ V /88' `88\\8 `/88'";
	ascii_trees[5] = "   `&%\\ ` /%&'    |.|        \\ '|8'";
	ascii_trees[6] = "       |o|        | |         | |";
	ascii_trees[7] = "       |.|        | |         | |";
	ascii_trees[8] = "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";

	ofs << ascii_trees[0] << std::endl;
	ofs << ascii_trees[1] << std::endl;
	ofs << ascii_trees[2] << std::endl;
	ofs << ascii_trees[3] << std::endl;
	ofs << ascii_trees[4] << std::endl;
	ofs << ascii_trees[5] << std::endl;
	ofs << ascii_trees[6] << std::endl;
	ofs << ascii_trees[7] << std::endl;
	ofs << ascii_trees[8] << std::endl;

	ofs.close();
	return ;
}

std::ostream	&operator<<( std::ostream & o, ShrubberyCreationForm const & rhs )
{
	o << "Name : " << rhs.getName() << std::endl;
	o << "Is signed : " << rhs.getIsSigned() << std::endl;
	o << "Grade for sign : " << (int)rhs.getGradeSign() << std::endl;
	o << "Grade for execute : " << (int)rhs.getGradeExecute() << std::endl;
	o << "Target : " << rhs.getTarget() << std::endl;
	return (o);
}
