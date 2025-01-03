/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/11/27 00:02:04 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include <string>
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

public:

	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string const & target );
	PresidentialPardonForm( PresidentialPardonForm const & src );
	~PresidentialPardonForm( void );

	PresidentialPardonForm	&operator=( PresidentialPardonForm const & rhs);

	const std::string	getTarget( void ) const;

	void	executeFormAction( void ) const;

private:

	const std::string	_target;
	
};

std::ostream	&operator<<( std::ostream & o, PresidentialPardonForm const & rhs );

#endif