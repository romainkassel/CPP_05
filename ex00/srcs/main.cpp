/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/29 10:45:33 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	testBureaucratCopyByAffectation();
void	testBureaucratCopyByConstructor();

int	main( void )
{

	Bureaucrat	*bureaucrat1 = NULL;
	Bureaucrat	*bureaucrat2 = NULL;
	Bureaucrat	*bureaucrat3 = NULL;
	Bureaucrat	*bureaucrat4 = NULL;
	
	try
	{
		std::cout << std::endl;
		std::cout << "***** BUREAUCRAT 1 *****" << std::endl;
		std::cout << std::endl;
		bureaucrat1 = new Bureaucrat("bureaucrat1", 1);
		std::cout << std::endl;
		
		std::cout << std::endl;
		std::cout << "***** BUREAUCRAT 2 *****" << std::endl;
		std::cout << std::endl;
		bureaucrat2 = new Bureaucrat("bureaucrat2", 150);
		std::cout << std::endl;
		
		std::cout << std::endl;
		std::cout << "***** BUREAUCRAT 3 *****" << std::endl;
		std::cout << std::endl;
		bureaucrat3 = new Bureaucrat("bureaucrat3", 0);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "A bureaucrat was incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << std::endl;
		std::cout << "***** BUREAUCRAT 4 *****" << std::endl;
		std::cout << std::endl;
		bureaucrat4 = new Bureaucrat("bureaucrat4", 151);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "A bureaucrat was incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***** BUREAUCRAT 1 *****" << std::endl;
	std::cout << std::endl;

	try
	{
		if (bureaucrat1 == NULL)
			throw "Bureaucrat1 has not been instantiated correctly! Can't use incrementGrade";
		try
		{
			bureaucrat1->incrementGrade(); // must throw an exception (from 1 to 0)
		}
		catch (std::exception & e)
		{
			std::cerr << "Can't increment grade" << std::endl;
			std::cout << std::endl;
			bureaucrat1->decrementGrade(); // must NOT throw an exception (from 1 to 2)
		}
	}
	catch (const char * e)
	{
		std::cerr << e << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***** BUREAUCRAT 2 *****" << std::endl;
	std::cout << std::endl;

	try
	{
		if (bureaucrat2 == NULL)
			throw "Bureaucrat2 has not been instantiated correctly! Can't use decrementGrade";
		try
		{
			bureaucrat2->decrementGrade(); // must throw an exception (from 150 to 151)
		}
		catch (std::exception & e)
		{
			std::cerr << "Can't decrement grade" << std::endl;
			std::cout << std::endl;
			bureaucrat2->incrementGrade(); // must NOT throw an exception (from 150 to 149)
		}
		
	}
	catch (const char * e)
	{
		std::cerr << e << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "***** BUREAUCRAT 3 & 4 *****" << std::endl;
	std::cout << std::endl;

	try
	{
		if (bureaucrat3 == NULL)
			throw "Bureaucrat3 has not been instantiated correctly! Can't use decrementGrade";
		try
		{
			bureaucrat3->decrementGrade(); // must NOT throw an exception (from 0 to 1)
		}
		catch (std::exception & e)
		{
			std::cerr << "Can't decrement grade" << std::endl;
		}
	}
	catch (const char * e)
	{
		std::cerr << e << std::endl;
	}


	try
	{
		if (bureaucrat4 == NULL)
			throw "Bureaucrat4 has not been instantiated correctly! Can't use incrementGrade";
		try
		{
			bureaucrat4->incrementGrade(); // must NOT throw an exception (from 151 to 150)
		}
		catch (std::exception & e)
		{
			std::cerr << "Can't decrement grade" << std::endl;
		}
	}
	catch (const char * e)
	{
		std::cerr << e << std::endl;
	}

	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "***** Test of insertion operator *****" << std::endl;
	std::cout << std::endl;

	std::cout << *bureaucrat1 << std::endl;
	std::cout << *bureaucrat2 << std::endl;

	std::cout << std::endl;
	std::cout << "***** Call of destructors *****" << std::endl;
	std::cout << std::endl;

	delete (bureaucrat1);
	delete (bureaucrat2);

	testBureaucratCopyByAffectation();
	testBureaucratCopyByConstructor();

	std::cout << std::endl;
	
	return (0);
}

void	testBureaucratCopyByAffectation() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Check copy by affectation from Bureaucrat" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << std::endl;
		
	// Creation of a Bureaucrat instance (will be copied)
	
	Bureaucrat	bureaucrat1("bureaucrat1", 42);
	std::cout << std::endl;

	// Display of bureaucrat1 attributes

	std::cout << "bureaucrat1 name : " << bureaucrat1.getName() << std::endl;
	std::cout << "bureaucrat1 grade : " << (int)bureaucrat1.getGrade() << std::endl;
	std::cout << std::endl;

	// Creation of a Bureaucrat instance (copy)
	
	Bureaucrat	bureaucrat2("bureaucrat2", 100);
	std::cout << std::endl;

	// Display of bureaucrat2 attributes BEFORE

	std::cout << "bureaucrat2 name : " << bureaucrat2.getName() << std::endl;
	std::cout << "bureaucrat2 grade : " << (int)bureaucrat2.getGrade() << std::endl;
	std::cout << std::endl;

	// Affectation from 1 to 2
	
	bureaucrat2 = bureaucrat1;

	std::cout << std::endl;

	// Display of bureaucrat2 attributes AFTER

	std::cout << "bureaucrat2 name : " << bureaucrat2.getName() << std::endl;
	std::cout << "bureaucrat2 grade : " << (int)bureaucrat2.getGrade() << std::endl;
	std::cout << std::endl;

	return ;
}

void	testCopyByConstructor(Bureaucrat bureaucrat1);

void	testBureaucratCopyByConstructor() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Check copy by constructor from Bureaucrat" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << std::endl;
		
	// Creation of a Bureaucrat instance (will be copied)
	
	Bureaucrat	bureaucrat1("bureaucrat1", 42);
	std::cout << std::endl;

	// Display of bureaucrat1 attributes

	std::cout << "bureaucrat1 name : " << bureaucrat1.getName() << std::endl;
	std::cout << "bureaucrat1 grade : " << (int)bureaucrat1.getGrade() << std::endl;
	std::cout << std::endl;

	testCopyByConstructor(bureaucrat1);

	return ;
}

void	testCopyByConstructor(Bureaucrat bureaucrat1)
{
	std::cout << std::endl;
	
	// Display of bureaucrat1 attributes

	std::cout << "bureaucrat1 name : " << bureaucrat1.getName() << std::endl;
	std::cout << "bureaucrat1 grade : " << (int)bureaucrat1.getGrade() << std::endl;
	std::cout << std::endl;
	
	return ;
}