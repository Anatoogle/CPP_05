/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:13:27 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 14:16:20 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45), _target("defaultRobotomy")
{
    std::cout   << "+ RobotomyRequestForm Constructor called - Default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout   << "+ RobotomyRequestForm Constructor called - tagret" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
    std::cout   << "+ RobotomyRequestForm Constructor called - copy" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if(this != &copy)
        _target = copy.getTarget();

    std::cout   << "= RobotomyRequestForm Copy assignment operator called"  << std::endl;

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout   << "- RobotomyRequestForm Destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget()const
{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
    if(!this->getSignedStatus())
        throw FormNotSignedException();
    else if(executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();

    std::cout   << "Drrrrrrrrrrrrr.....zzzzz....." << std::endl;
    srand(time(0));
    if(std::rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed..." << std::endl;
}
