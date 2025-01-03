/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/11/29 10:48:48 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <exception>

class	Form;

class	Bureaucrat {

public:

	Bureaucrat( void );
	Bureaucrat( std::string	name, int grade );
	Bureaucrat( Bureaucrat const & src );
	~Bureaucrat( void );

	Bureaucrat	&operator=( Bureaucrat const & rhs);

	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				setGrade( int grade);

	class	GradeTooHighException : public std::exception {
		
		public:

			virtual const char *what() const throw()
			{
				return ("GradeTooHighException : grade is too high");
			}

	};

	class	GradeTooLowException : public std::exception {
		
		public:

			virtual const char *what() const throw()
			{
				return ("GradeTooLowException : grade is too low");
			}

	};

	void	checkGrade( int grade ) const;
	void	incrementGrade( void );
	void	decrementGrade( void ); 

	void	signForm( Form & form );

private:

	const std::string	_name;
	int					_grade;
	
};

std::ostream	&operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif