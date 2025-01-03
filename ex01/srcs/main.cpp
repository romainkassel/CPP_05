/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/27 08:59:00 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	testBureaucratCopyByAffectation();
void	testBureaucratCopyByConstructor();

void	testFormCopyByAffectation();
void	testFormCopyByConstructor();

int	main( void )
{

	std::cout << std::endl;
	std::cout << "***** BUREAUCRAT 1 - CREATION *****" << std::endl;
	std::cout << std::endl;
		
	Bureaucrat	*bureaucrat1 = NULL;
	
	try
	{
		bureaucrat1 = new Bureaucrat("bureaucrat1", 42);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "bureaucrat1 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "***** FORM 1 - CREATION *****" << std::endl;
	std::cout << std::endl;
		
	Form	*form1 = NULL;
	
	try
	{
		form1 = new Form("form1", 42, 1);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "form1 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "***** FORM 2 - CREATION *****" << std::endl;
	std::cout << "***** 1, 1 - SHOULD NOT THROW *****" << std::endl;
	std::cout << std::endl;
		
	Form	*form2 = NULL;
	
	try
	{
		form2 = new Form("form2", 1, 1);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "form2 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "***** FORM 3 - CREATION *****" << std::endl;
	std::cout << "***** 150, 150 - SHOULD NOT THROW *****" << std::endl;
	std::cout << std::endl;
		
	Form	*form3 = NULL;
	
	try
	{
		form3 = new Form("form3", 150, 150);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "form3 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "***** FORM 4 - CREATION *****" << std::endl;
	std::cout << "***** 1, 0 - SHOULD THROW *****" << std::endl;
	std::cout << std::endl;
		
	Form	*form4 = NULL;
	
	try
	{
		form4 = new Form("form4", 1, 0);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "form4 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "***** FORM 5 - CREATION *****" << std::endl;
	std::cout << "***** 151, 150 - SHOULD THROW *****" << std::endl;
	std::cout << std::endl;
		
	Form	*form5 = NULL;
	
	try
	{
		form5 = new Form("form5", 151, 150);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "form5 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "***** FORM 6 - CREATION *****" << std::endl;
	std::cout << "***** 150, 151 - SHOULD THROW *****" << std::endl;
	std::cout << std::endl;
		
	Form	*form6 = NULL;
	
	try
	{
		form6 = new Form("form6", 150, 151);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "form6 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "***** FORM 7 - CREATION *****" << std::endl;
	std::cout << "***** 0, 1 - SHOULD THROW *****" << std::endl;
	std::cout << std::endl;
		
	Form	*form7 = NULL;
	
	try
	{
		form7 = new Form("form7", 0, 1);
		std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "form7 has been incorrectly instantiated due to a bad grade" << std::endl;
	}

	/////////

	std::cout << std::endl;
	std::cout << "***** SIGN FORM *****" << std::endl;
	std::cout << "***** Should NOT be signed (wrong bureaucrat grade) *****" << std::endl;
	std::cout << std::endl;

	// set signed status to 0 form1
	form1->setIsSigned(false);
	std::cout << "form1 -> signed status : " << form1->getIsSigned() << std::endl;
	
	// Set bad grade for bureaucrat1 (43 VS 42)
	bureaucrat1->setGrade(43);
	std::cout << "bureaucrat1 -> grade : " << (int)bureaucrat1->getGrade() << std::endl;
	std::cout << "form1 -> required grade for signature : " << (int)form1->getGradeSign() << std::endl;

	// Signature : should throw an error
	bureaucrat1->signForm(*form1);
	std::cout << "form1 -> signed status : " << form1->getIsSigned() << std::endl;
	
	std::cout << std::endl;
	std::cout << "***** SIGN FORM *****" << std::endl;
	std::cout << "***** Should be signed *****" << std::endl;
	std::cout << std::endl;

	// Set OK grade for bureaucrat1 (42)
	bureaucrat1->setGrade(42);
	std::cout << "bureaucrat1 -> grade : " << (int)bureaucrat1->getGrade() << std::endl;
	std::cout << "form1 -> required grade for signature : " << (int)form1->getGradeSign() << std::endl;
	
	// Signature : should NOT throw an error
	bureaucrat1->signForm(*form1);
	std::cout << "form1 -> signed status : " << form1->getIsSigned() << std::endl;

	std::cout << std::endl;
	std::cout << "***** Test of insertion operator *****" << std::endl;
	std::cout << std::endl;

	/////////

	if (form1)
		std::cout << *form1 << std::endl;
	if (form2)
		std::cout << *form2 << std::endl;
	if (form3)
		std::cout << *form3 << std::endl;
	if (form4)
		std::cout << *form4 << std::endl;
	if (form5)
		std::cout << *form5 << std::endl;
	if (form6)
		std::cout << *form6 << std::endl;
	if (form7)
		std::cout << *form7 << std::endl;

	std::cout << std::endl;
	std::cout << "***** Call of destructors *****" << std::endl;
	std::cout << std::endl;

	delete (bureaucrat1);
	delete (form1);
	delete (form2);
	delete (form3);

	testBureaucratCopyByAffectation();
	testBureaucratCopyByConstructor();

	testFormCopyByAffectation();
	testFormCopyByConstructor();

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

void	testFormCopyByAffectation() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Check copy by affectation from Form" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << std::endl;
		
	// Creation of a Form instance (will be copied)
	
	Form	form1("form1", 78, 53);
	form1.setIsSigned(true);
	std::cout << std::endl;

	// Display of form1 attributes

	std::cout << form1 << std::endl;

	// Creation of a Form instance (copy)
	
	Form	form2("form2", 100, 68);
	std::cout << std::endl;

	// Display of form2 attributes BEFORE

	std::cout << form2 << std::endl;

	// Affectation from 1 to 2
	
	form2 = form1;

	std::cout << std::endl;

	// Display of form2 attributes AFTER

	std::cout << form2 << std::endl;

	return ;
}

void	testCopyByConstructor(Form form1);

void	testFormCopyByConstructor() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Check copy by constructor from Form" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << std::endl;
		
	// Creation of a Form instance (will be copied)
	
	Form	form1("form1", 78, 53);
	form1.setIsSigned(true);
	std::cout << std::endl;

	// Display of form1 attributes

	std::cout << form1 << std::endl;

	testCopyByConstructor(form1);

	return ;
}

void	testCopyByConstructor(Form form1)
{
	std::cout << std::endl;

	// Display of form1 attributes

	std::cout << form1 << std::endl;
	
	return ;
}