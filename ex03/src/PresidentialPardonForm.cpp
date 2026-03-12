/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:17:28 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 14:16:34 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), _target("defaultPerson")
{
    std::cout   << "+ PresidentialPardonForm Constructor called - Default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout   << "+ PresidentialPardonForm Constructor called - target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
    std::cout   << "+ PresidentialPardonForm Constructor called - Copy" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if(this != &copy)
        _target = copy.getTarget();

    std::cout   << "= PresidentialPardonForm Copy assignment operator called"  << std::endl;

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout   << "- PresidentialPardonForm Destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget()const
{
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
    if(!this->getSignedStatus())
        throw FormNotSignedException();
    else if(executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();

    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
