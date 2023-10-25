/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:49:33 by vegret            #+#    #+#             */
/*   Updated: 2023/10/25 02:23:40 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &source) { (void) source; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &source) {
	if (this == &source)
		return *this;
	return *this;
}

static AForm* ppFormCreator(std::string& target) {
	return new PresidentialPardonForm(target);
}

static AForm* rrFormCreator(std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* scFormCreator(std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (*creators[3])(std::string& target) = {ppFormCreator, rrFormCreator, scFormCreator};
	
	for (int i = 0; i < 3; i++) {
		if (name == types[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return creators[i](target);
		}
	}

	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() { return "Unknown Form"; }
