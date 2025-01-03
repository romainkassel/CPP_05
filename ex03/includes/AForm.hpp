/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/11/29 10:53:43 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AForm_H__
#define __AForm_H__

#include <string>

class	Bureaucrat;

class	AForm {

public:

	AForm( void );
	AForm( std::string name, int gradeSign, int gradeExecute );
	AForm( AForm const & src );
	virtual ~AForm( void );

	AForm	&operator=( AForm const & rhs);

	const std::string	getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getGradeSign(void ) const;
	int					getGradeExecute( void) const;

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

	class FormNotSignedException : public std::exception {

		public :

			virtual const char *what() const throw()
			{
				return ("FormNotSignedException : form is not signed");
			}
	};

	void	beSigned( Bureaucrat const & bureaucrat );
	void	execute( Bureaucrat const & executor ) const;

	void	checkGrade( int grade ) const;

	virtual const std::string	getTarget( void ) const = 0;

	virtual void	executeFormAction( void ) const = 0;

private:

	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExecute;
	
};

std::ostream	&operator<<( std::ostream & o, AForm const & rhs );

#endif