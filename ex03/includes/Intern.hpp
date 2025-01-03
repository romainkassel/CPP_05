/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/11/28 05:40:13 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
#define __INTERN_H__

#include <string>
#include <exception>
#include "AForm.hpp"

class	Intern {

public:

	Intern( void );
	Intern( Intern const & src );
	~Intern( void );

	Intern	&operator=( Intern const & rhs);

	AForm	*makeForm( std::string formName, std::string formTarget );

	class	NoExistingFormNameException : public std::exception {

		public:

			virtual const char *what() const throw()
			{
				return ("NoExistingFormNameException : form name not recognized");
			}
	};

	class	EmptyParamException : public std::exception {

		public:

			virtual const char *what() const throw()
			{
				return ("EmptyParamException : No parameter should be empty");
			}
	};

private:

	AForm	*_makeShrubberyCreationForm( std::string formTarget );
	AForm	*_makeRobotomyRequestForm( std::string formTarget );
	AForm	*_makePresidentialPardonForm( std::string formTarget );

};

#endif