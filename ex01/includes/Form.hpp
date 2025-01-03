/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/11/29 10:49:31 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
#define __FORM_H__

#include <string>

class	Bureaucrat;

class	Form {

public:

	Form( void );
	Form( std::string name, int gradeSign, int gradeExecute );
	Form( Form const & src );
	~Form( void );

	Form	&operator=( Form const & rhs);

	const std::string	getName( void ) const;
	bool				getIsSigned( void ) const;
	int				getGradeSign(void ) const;
	int				getGradeExecute( void) const;

	void				setIsSigned( bool isSigned );

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

	void	beSigned( Bureaucrat const & bureaucrat );

	void	checkGrade( int grade ) const;

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExecute;
	
};

std::ostream	&operator<<( std::ostream & o, Form const & rhs );

#endif