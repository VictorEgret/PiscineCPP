/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:46:22 by vegret            #+#    #+#             */
/*   Updated: 2023/10/25 00:15:19 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Form"), _signGrade(Bureaucrat::lowestGrade),
	  _executeGrade(Bureaucrat::lowestGrade), _isSigned(false), _target("None") {}

AForm::AForm(const AForm& form)
	: _name(form._name), _signGrade(form._signGrade),
	  _executeGrade(form._executeGrade), _isSigned(form._isSigned), _target(form._target) {}

AForm::AForm(std::string name, std::string target, int signGrade, int executeGrade)
	: _name(name), _signGrade(signGrade), _executeGrade(executeGrade),
	  _isSigned(false), _target(target) { 
	if (signGrade < Bureaucrat::highestGrade || executeGrade < Bureaucrat::highestGrade)
		throw AForm::GradeTooHighException();
	if (signGrade > Bureaucrat::lowestGrade || executeGrade > Bureaucrat::lowestGrade)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& form) {
	if (this == &form)
		return *this;
	*const_cast<std::string*>(&_name) = form._name;
	*const_cast<std::string*>(&_target) = form._target;
	*const_cast<int*>(&_signGrade) = form._signGrade;
	*const_cast<int*>(&_executeGrade) = form._executeGrade;
	_isSigned = form._isSigned;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
std::string AForm::getTarget() const { return _target; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecuteGrade() const { return _executeGrade; }
bool AForm::isSigned() const { return _isSigned; }

void AForm::checkRequirements(const Bureaucrat& bureaucrat) const {
	if (!_isSigned)
		throw AForm::NotSignedException();
	if (bureaucrat.getGrade() > _executeGrade)
		throw Bureaucrat::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else if (_isSigned)
		std::cout << bureaucrat.getName() << " couldn't sign " << _name
				  << " because it is already signed." << std::endl;
	else {
		std::cout << bureaucrat.getName() << " signed " << _name << "." << std::endl;
		_isSigned = true;
	}
}

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high"; }

const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low"; }

const char* AForm::NotSignedException::what() const throw() { return "Form not signed"; }

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "Form " << form.getName() << " is signable by grade " << form.getSignGrade()
	   << " and executable by grade " << form.getExecuteGrade() << ". It is"
	   << (form.isSigned() ? " " : " not yet ") << "signed." << std::endl;
	return os;
}
