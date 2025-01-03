/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/11/27 08:00:20 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	testBureaucratCopyByAffectation();
void	testBureaucratCopyByConstructor();

void	testShrubberyCreationFormCopyByAffectation();
void	testShrubberyCreationFormCopyByConstructor();

void	testRobotomyRequestFormCopyByAffectation();
void	testRobotomyRequestFormCopyByConstructor();

void	testPresidentialPardonFormCopyByAffectation();
void	testPresidentialPardonFormCopyByConstructor();

int	main( void )
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mBureaucrat Signatory\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	
	std::cout << std::endl;
	std::cout << "\033[0;32mCREATION\033[0m" << std::endl;
	std::cout << std::endl;
		
	Bureaucrat	*BureaucratSignatory = new Bureaucrat("BureaucratSignatory", 150);

	///////////////////

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mBureaucrat Executor\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	
	std::cout << std::endl;
	std::cout << "\033[0;35mCREATION\033[0m" << std::endl;
	std::cout << std::endl;
		
	Bureaucrat	*BureaucratExecutor = new Bureaucrat("BureaucratExecutor", 150);

	///////////////////

	// ShrubberyCreationForm 1
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mShrubberyCreationForm 1\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	
	// CREATION
	std::cout << std::endl;
	std::cout << "\033[0;32mCREATION\033[0m" << std::endl;
	std::cout << std::endl;
		
	ShrubberyCreationForm	*ShrubberyCreationForm1 = new ShrubberyCreationForm("ShrubberyCreationForm1Target");
	
	// Attribute display (<< operator)
	std::cout << std::endl;
	std::cout << "\033[0;32mAttribute display (<< operator)\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << *ShrubberyCreationForm1;

	///////////////////

	// executeForm : Should NOT be executed
	std::cout << std::endl;
	std::cout << "\033[0;32mexecuteForm : Should NOT be executed (ShrubberyCreationForm1 NOT SIGNED yet)\033[0m" << std::endl;
	std::cout << std::endl;

	// Display of ShrubberyCreationForm1 current signed status
	std::cout << "ShrubberyCreationForm1 -> signed status : " << ShrubberyCreationForm1->getIsSigned() << std::endl;

	// Execution of ShrubberyCreationForm1 by BureaucratExecutor with whatever grade
	BureaucratExecutor->executeForm(*ShrubberyCreationForm1);

	///////////////////

	// executeForm : Should NOT be executed
	std::cout << std::endl;
	std::cout << "\033[0;32mexecuteForm : Should NOT be executed (ShrubberyCreationForm1 SIGNED but wrong grade for executor)\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for signatory bureaucrat
	BureaucratSignatory->setGrade(145);
	
	// Signature of ShrubberyCreationForm1 by BureaucratSignatory with OK grade
	BureaucratSignatory->signForm(*ShrubberyCreationForm1);
	std::cout << "ShrubberyCreationForm1 -> signed status : " << ShrubberyCreationForm1->getIsSigned() << std::endl;
	
	std::cout << std::endl;

	// Exec of ShrubberyCreationForm1 with wrong exec grade (138 VS 137)
	BureaucratExecutor->setGrade(138);
	std::cout << "BureaucratExecutor -> grade : " << (int)BureaucratExecutor->getGrade() << std::endl;
	BureaucratExecutor->executeForm(*ShrubberyCreationForm1);

	///////////////////
	
	// executeForm : Should be executed
	std::cout << std::endl;
	std::cout << "\033[0;32mexecuteForm : Should be executed\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for executor bureaucrat
	BureaucratExecutor->setGrade(137);
	std::cout << "BureaucratExecutor -> grade : " << (int)BureaucratExecutor->getGrade() << std::endl;

	// Exec of ShrubberyCreationForm1 with OK exec grade (137)
	BureaucratExecutor->executeForm(*ShrubberyCreationForm1);

	// signForm : Should NOT be signed
	std::cout << std::endl;
	std::cout << "\033[0;32msignForm : Should NOT be signed (wrong grade for signatory)\033[0m" << std::endl;
	std::cout << std::endl;

	// set signed status to 0 again
	ShrubberyCreationForm1->setIsSigned(false);
	std::cout << "ShrubberyCreationForm1 -> signed status : " << ShrubberyCreationForm1->getIsSigned() << std::endl;
	
	// Set bad grade for signatory bureaucrat (146 VS 145)
	BureaucratSignatory->setGrade(146);
	std::cout << "BureaucratSignatory -> grade : " << (int)BureaucratSignatory->getGrade() << std::endl;
	std::cout << "ShrubberyCreationForm1 -> required grade for signature : " << (int)ShrubberyCreationForm1->getGradeSign() << std::endl;

	// Signature : should throw an error
	BureaucratSignatory->signForm(*ShrubberyCreationForm1);
	std::cout << "ShrubberyCreationForm1 -> signed status : " << ShrubberyCreationForm1->getIsSigned() << std::endl;
	
	// signForm : Should be signed
	std::cout << std::endl;
	std::cout << "\033[0;32msignForm : Should be signed\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for signatory bureaucrat (145)
	BureaucratSignatory->setGrade(145);
	std::cout << "BureaucratSignatory -> grade : " << (int)BureaucratSignatory->getGrade() << std::endl;
	std::cout << "ShrubberyCreationForm1 -> required grade for signature : " << (int)ShrubberyCreationForm1->getGradeSign() << std::endl;
	
	// Signature : should NOT throw an error
	BureaucratSignatory->signForm(*ShrubberyCreationForm1);
	std::cout << "ShrubberyCreationForm1 -> signed status : " << ShrubberyCreationForm1->getIsSigned() << std::endl;

	///////////////////

	// ShrubberyCreationForm 1
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mRobotomyRequestForm 1\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	
	// CREATION
	std::cout << std::endl;
	std::cout << "\033[0;35mCREATION\033[0m" << std::endl;
	std::cout << std::endl;
		
	RobotomyRequestForm	*RobotomyRequestForm1 = new RobotomyRequestForm("RobotomyRequestForm1Target");
	
	// Attribute display (<< operator)
	std::cout << std::endl;
	std::cout << "\033[0;35mAttribute display (<< operator)\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << *RobotomyRequestForm1;

	///////////////////

	// executeForm : Should NOT be executed
	std::cout << std::endl;
	std::cout << "\033[0;35mexecuteForm : Should NOT be executed (RobotomyRequestForm1 NOT SIGNED yet)\033[0m" << std::endl;
	std::cout << std::endl;

	// Display of RobotomyRequestForm1 current signed status
	std::cout << "RobotomyRequestForm1 -> signed status : " << RobotomyRequestForm1->getIsSigned() << std::endl;

	// Execution of RobotomyRequestForm1 by BureaucratExecutor with whatever grade
	BureaucratExecutor->executeForm(*RobotomyRequestForm1);

	///////////////////

	// executeForm : Should NOT be executed
	std::cout << std::endl;
	std::cout << "\033[0;35mexecuteForm : Should NOT be executed (RobotomyRequestForm1 SIGNED but wrong grade for executor)\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for signatory bureaucrat
	BureaucratSignatory->setGrade(72);
	
	// Signature of ShrubberyCreationForm1 by BureaucratSignatory with OK grade
	BureaucratSignatory->signForm(*RobotomyRequestForm1);
	std::cout << "RobotomyRequestForm1 -> signed status : " << RobotomyRequestForm1->getIsSigned() << std::endl;
	
	std::cout << std::endl;

	// Exec of RobotomyRequestForm1 with wrong exec grade (46 VS 45)
	BureaucratExecutor->setGrade(46);
	std::cout << "BureaucratExecutor -> grade : " << (int)BureaucratExecutor->getGrade() << std::endl;
	BureaucratExecutor->executeForm(*RobotomyRequestForm1);

	///////////////////
	
	// executeForm : Should be executed
	std::cout << std::endl;
	std::cout << "\033[0;35mexecuteForm : Should be executed\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for executor bureaucrat
	BureaucratExecutor->setGrade(45);
	std::cout << "BureaucratExecutor -> grade : " << (int)BureaucratExecutor->getGrade() << std::endl;
	std::cout << std::endl;

	// Exec of RobotomyRequestForm1 with OK exec grade (45)
	BureaucratExecutor->executeForm(*RobotomyRequestForm1);
	std::cout << std::endl;
	BureaucratExecutor->executeForm(*RobotomyRequestForm1);
	std::cout << std::endl;
	BureaucratExecutor->executeForm(*RobotomyRequestForm1);
	std::cout << std::endl;
	BureaucratExecutor->executeForm(*RobotomyRequestForm1);
	std::cout << std::endl;
	BureaucratExecutor->executeForm(*RobotomyRequestForm1);

	// signForm : Should NOT be signed
	std::cout << std::endl;
	std::cout << "\033[0;35msignForm : Should NOT be signed (wrong grade for signatory)\033[0m" << std::endl;
	std::cout << std::endl;

	// set signed status to 0 again
	RobotomyRequestForm1->setIsSigned(false);
	std::cout << "RobotomyRequestForm1 -> signed status : " << RobotomyRequestForm1->getIsSigned() << std::endl;
	
	// Set bad grade for signatory bureaucrat (73 VS 72)
	BureaucratSignatory->setGrade(73);
	std::cout << "BureaucratSignatory -> grade : " << (int)BureaucratSignatory->getGrade() << std::endl;
	std::cout << "RobotomyRequestForm1 -> required grade for signature : " << (int)RobotomyRequestForm1->getGradeSign() << std::endl;

	// Signature : should throw an error
	BureaucratSignatory->signForm(*RobotomyRequestForm1);
	std::cout << "RobotomyRequestForm1 -> signed status : " << RobotomyRequestForm1->getIsSigned() << std::endl;
	
	// signForm : Should be signed
	std::cout << std::endl;
	std::cout << "\033[0;35msignForm : Should be signed\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for signatory bureaucrat (72)
	BureaucratSignatory->setGrade(72);
	std::cout << "BureaucratSignatory -> grade : " << (int)BureaucratSignatory->getGrade() << std::endl;
	std::cout << "RobotomyRequestForm1 -> required grade for signature : " << (int)RobotomyRequestForm1->getGradeSign() << std::endl;
	
	// Signature : should NOT throw an error
	BureaucratSignatory->signForm(*RobotomyRequestForm1);
	std::cout << "RobotomyRequestForm1 -> signed status : " << RobotomyRequestForm1->getIsSigned() << std::endl;

	///////////////////

	// PresidentialPardonForm 1
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mPresidentialPardonForm 1\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	
	// CREATION
	std::cout << std::endl;
	std::cout << "\033[0;32mCREATION\033[0m" << std::endl;
	std::cout << std::endl;
		
	PresidentialPardonForm	*PresidentialPardonForm1 = new PresidentialPardonForm("PresidentialPardonForm1Target");
	
	// Attribute display (<< operator)
	std::cout << std::endl;
	std::cout << "\033[0;32mAttribute display (<< operator)\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << *PresidentialPardonForm1;

	///////////////////

	// executeForm : Should NOT be executed
	std::cout << std::endl;
	std::cout << "\033[0;32mexecuteForm : Should NOT be executed (PresidentialPardonForm1 NOT SIGNED yet)\033[0m" << std::endl;
	std::cout << std::endl;

	// Display of PresidentialPardonForm1 current signed status
	std::cout << "PresidentialPardonForm1 -> signed status : " << PresidentialPardonForm1->getIsSigned() << std::endl;

	// Execution of PresidentialPardonForm1 by BureaucratExecutor with whatever grade
	BureaucratExecutor->executeForm(*PresidentialPardonForm1);

	///////////////////

	// executeForm : Should NOT be executed
	std::cout << std::endl;
	std::cout << "\033[0;32mexecuteForm : Should NOT be executed (PresidentialPardonForm1 SIGNED but wrong grade for executor)\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for signatory bureaucrat
	BureaucratSignatory->setGrade(25);
	
	// Signature of PresidentialPardonForm1 by BureaucratSignatory with OK grade
	BureaucratSignatory->signForm(*PresidentialPardonForm1);
	std::cout << "PresidentialPardonForm1 -> signed status : " << PresidentialPardonForm1->getIsSigned() << std::endl;
	
	std::cout << std::endl;

	// Exec of PresidentialPardonForm1 with wrong exec grade (6 VS 5)
	BureaucratExecutor->setGrade(6);
	std::cout << "BureaucratExecutor -> grade : " << (int)BureaucratExecutor->getGrade() << std::endl;
	BureaucratExecutor->executeForm(*PresidentialPardonForm1);

	///////////////////
	
	// executeForm : Should be executed
	std::cout << std::endl;
	std::cout << "\033[0;32mexecuteForm : Should be executed\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for executor bureaucrat
	BureaucratExecutor->setGrade(5);
	std::cout << "BureaucratExecutor -> grade : " << (int)BureaucratExecutor->getGrade() << std::endl;

	// Exec of PresidentialPardonForm1 with OK exec grade (5)
	BureaucratExecutor->executeForm(*PresidentialPardonForm1);

	// signForm : Should NOT be signed
	std::cout << std::endl;
	std::cout << "\033[0;32msignForm : Should NOT be signed (wrong grade for signatory)\033[0m" << std::endl;
	std::cout << std::endl;

	// set signed status to 0 again
	PresidentialPardonForm1->setIsSigned(false);
	std::cout << "PresidentialPardonForm1 -> signed status : " << PresidentialPardonForm1->getIsSigned() << std::endl;
	
	// Set bad grade for signatory bureaucrat (26 VS 25)
	BureaucratSignatory->setGrade(26);
	std::cout << "BureaucratSignatory -> grade : " << (int)BureaucratSignatory->getGrade() << std::endl;
	std::cout << "PresidentialPardonForm1 -> required grade for signature : " << (int)PresidentialPardonForm1->getGradeSign() << std::endl;

	// Signature : should throw an error
	BureaucratSignatory->signForm(*PresidentialPardonForm1);
	std::cout << "PresidentialPardonForm1 -> signed status : " << PresidentialPardonForm1->getIsSigned() << std::endl;
	
	// signForm : Should be signed
	std::cout << std::endl;
	std::cout << "\033[0;32msignForm : Should be signed\033[0m" << std::endl;
	std::cout << std::endl;

	// Set OK grade for signatory bureaucrat (72)
	BureaucratSignatory->setGrade(25);
	std::cout << "BureaucratSignatory -> grade : " << (int)BureaucratSignatory->getGrade() << std::endl;
	std::cout << "PresidentialPardonForm1 -> required grade for signature : " << (int)PresidentialPardonForm1->getGradeSign() << std::endl;
	
	// Signature : should NOT throw an error
	BureaucratSignatory->signForm(*PresidentialPardonForm1);
	std::cout << "PresidentialPardonForm1 -> signed status : " << PresidentialPardonForm1->getIsSigned() << std::endl;

	///////////////////

	std::cout << std::endl;

	delete(BureaucratSignatory);
	delete(BureaucratExecutor);
	delete(ShrubberyCreationForm1);
	delete(RobotomyRequestForm1);
	delete(PresidentialPardonForm1);

	///////////////////

	testBureaucratCopyByAffectation();
	testBureaucratCopyByConstructor();

	testShrubberyCreationFormCopyByAffectation();
	testShrubberyCreationFormCopyByConstructor();

	testRobotomyRequestFormCopyByAffectation();
	testRobotomyRequestFormCopyByConstructor();

	testPresidentialPardonFormCopyByAffectation();
	testPresidentialPardonFormCopyByConstructor();

	std::cout << std::endl;
	
	return (0);
}

void	testBureaucratCopyByAffectation() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mCheck copy by affectation from Bureaucrat\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
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
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mCheck copy by constructor from Bureaucrat\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
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

void	testShrubberyCreationFormCopyByAffectation() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mCheck copy by affectation from ShrubberyCreationForm\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	std::cout << std::endl;
		
	// Creation of a ShrubberyCreationForm instance (will be copied)
	
	ShrubberyCreationForm	ShrubberyCreationForm1("target1");
	ShrubberyCreationForm1.setIsSigned(true);
	std::cout << std::endl;

	// Display of ShrubberyCreationForm1 attributes

	std::cout << ShrubberyCreationForm1 << std::endl;

	// Creation of a ShrubberyCreationForm instance (copy)
	
	ShrubberyCreationForm	ShrubberyCreationForm2("target2");
	std::cout << std::endl;

	// Display of ShrubberyCreationForm2 attributes BEFORE

	std::cout << ShrubberyCreationForm2 << std::endl;

	// Affectation from 1 to 2
	
	ShrubberyCreationForm2 = ShrubberyCreationForm1;

	std::cout << std::endl;

	// Display of ShrubberyCreationForm2 attributes AFTER

	std::cout << ShrubberyCreationForm2 << std::endl;

	return ;
}

void	testCopyByConstructor(ShrubberyCreationForm ShrubberyCreationForm1);

void	testShrubberyCreationFormCopyByConstructor() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mCheck copy by constructor from ShrubberyCreationForm\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	std::cout << std::endl;
		
	// Creation of a ShrubberyCreationForm instance (will be copied)
	
	ShrubberyCreationForm	ShrubberyCreationForm1("target1");
	ShrubberyCreationForm1.setIsSigned(true);
	std::cout << std::endl;

	// Display of ShrubberyCreationForm1 attributes

	std::cout << ShrubberyCreationForm1 << std::endl;

	testCopyByConstructor(ShrubberyCreationForm1);

	return ;
}

void	testCopyByConstructor(ShrubberyCreationForm ShrubberyCreationForm1)
{
	std::cout << std::endl;

	// Display of ShrubberyCreationForm1 attributes

	std::cout << ShrubberyCreationForm1 << std::endl;
	
	return ;
}

void	testRobotomyRequestFormCopyByAffectation() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mCheck copy by affectation from RobotomyRequestForm\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	std::cout << std::endl;
		
	// Creation of a RobotomyRequestForm instance (will be copied)
	
	RobotomyRequestForm	RobotomyRequestForm1("target1");
	RobotomyRequestForm1.setIsSigned(true);
	std::cout << std::endl;

	// Display of RobotomyRequestForm1 attributes

	std::cout << RobotomyRequestForm1 << std::endl;

	// Creation of a RobotomyRequestForm instance (copy)
	
	RobotomyRequestForm	RobotomyRequestForm2("target2");
	std::cout << std::endl;

	// Display of RobotomyRequestForm2 attributes BEFORE

	std::cout << RobotomyRequestForm2 << std::endl;

	// Affectation from 1 to 2
	
	RobotomyRequestForm2 = RobotomyRequestForm1;

	std::cout << std::endl;

	// Display of RobotomyRequestForm2 attributes AFTER

	std::cout << RobotomyRequestForm2 << std::endl;

	return ;
}

void	testCopyByConstructor(RobotomyRequestForm RobotomyRequestForm1);

void	testRobotomyRequestFormCopyByConstructor() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mCheck copy by constructor from RobotomyRequestForm\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	std::cout << std::endl;
		
	// Creation of a RobotomyRequestForm instance (will be copied)
	
	RobotomyRequestForm	RobotomyRequestForm1("target1");
	RobotomyRequestForm1.setIsSigned(true);
	std::cout << std::endl;

	// Display of RobotomyRequestForm1 attributes

	std::cout << RobotomyRequestForm1 << std::endl;

	testCopyByConstructor(RobotomyRequestForm1);

	return ;
}

void	testCopyByConstructor(RobotomyRequestForm RobotomyRequestForm1)
{
	std::cout << std::endl;

	// Display of RobotomyRequestForm1 attributes

	std::cout << RobotomyRequestForm1 << std::endl;
	
	return ;
}

void	testPresidentialPardonFormCopyByAffectation() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mCheck copy by affectation from PresidentialPardonForm\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;35mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	std::cout << std::endl;
		
	// Creation of a PresidentialPardonForm instance (will be copied)
	
	PresidentialPardonForm	PresidentialPardonForm1("target1");
	PresidentialPardonForm1.setIsSigned(true);
	std::cout << std::endl;

	// Display of PresidentialPardonForm1 attributes

	std::cout << PresidentialPardonForm1 << std::endl;

	// Creation of a PresidentialPardonForm instance (copy)
	
	PresidentialPardonForm	PresidentialPardonForm2("target2");
	std::cout << std::endl;

	// Display of PresidentialPardonForm2 attributes BEFORE

	std::cout << PresidentialPardonForm2 << std::endl;

	// Affectation from 1 to 2
	
	PresidentialPardonForm2 = PresidentialPardonForm1;

	std::cout << std::endl;

	// Display of PresidentialPardonForm2 attributes AFTER

	std::cout << PresidentialPardonForm2 << std::endl;

	return ;
}

void	testCopyByConstructor(PresidentialPardonForm PresidentialPardonForm1);

void	testPresidentialPardonFormCopyByConstructor() {

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32m**********************************************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mCheck copy by constructor from PresidentialPardonForm\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;32mVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\033[0m" << std::endl;
	std::cout << std::endl;
		
	// Creation of a PresidentialPardonForm instance (will be copied)
	
	PresidentialPardonForm	PresidentialPardonForm1("target1");
	PresidentialPardonForm1.setIsSigned(true);
	std::cout << std::endl;

	// Display of PresidentialPardonForm1 attributes

	std::cout << PresidentialPardonForm1 << std::endl;

	testCopyByConstructor(PresidentialPardonForm1);

	return ;
}

void	testCopyByConstructor(PresidentialPardonForm PresidentialPardonForm1)
{
	std::cout << std::endl;

	// Display of PresidentialPardonForm1 attributes

	std::cout << PresidentialPardonForm1 << std::endl;
	
	return ;
}