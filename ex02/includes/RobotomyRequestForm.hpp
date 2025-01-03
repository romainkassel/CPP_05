/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/11/27 00:02:04 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include <string>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

public:

	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string const & target );
	RobotomyRequestForm( RobotomyRequestForm const & src );
	~RobotomyRequestForm( void );

	RobotomyRequestForm	&operator=( RobotomyRequestForm const & rhs);

	const std::string	getTarget( void ) const;

	void	executeFormAction( void ) const;

	class	RobotomyFailException : public std::exception {

		public : 

			virtual const char * what() const throw()
			{
				return ("RobotomyFailException : Robotomy failed");
			}

	};

private:

	const std::string	_target;
	static bool			_shouldRobotomyFail;
	
};

std::ostream	&operator<<( std::ostream & o, RobotomyRequestForm const & rhs );

#endif