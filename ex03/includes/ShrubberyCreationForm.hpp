/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/11/28 03:51:07 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include <string>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {

public:

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string const & target );
	ShrubberyCreationForm( ShrubberyCreationForm const & src );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm	&operator=( ShrubberyCreationForm const & rhs);

	const std::string	getTarget( void ) const;

	void	executeFormAction( void ) const;

private:

	const std::string	_target;
	
};

std::ostream	&operator<<( std::ostream & o, ShrubberyCreationForm const & rhs );

#endif