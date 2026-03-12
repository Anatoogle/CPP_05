/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:42:34 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 14:16:30 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), _target("home")
{
    std::cout   << "+ ShrubberyCreationForm Constructor called - Default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout   << "+ ShrubberyCreationForm Constructor called - Target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
    std::cout   << "+ ShrubberyCreationForm Constructor called - Copy" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if(this != &copy)
        this->_target = copy.getTarget();

    std::cout   << "= ShrubberyCreationForm Copy assignment operator called"  << std::endl;

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout   << "- ShrubberyCreationForm Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget()const
{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
    if(!this->getSignedStatus())
        throw FormNotSignedException();
    else if(executor.getGrade() > this->getGradeToExecute())
        throw Bureaucrat::GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if(!file)
        throw std::runtime_error("File Error");

    file << "         v\n"
            "        >X<\n"
            "         A\n"
            "        d$b\n"
            "      .d$$$b.\n"
            "    .d$i$$$$$b.\n"
            "       d$$@b\n"
            "      d$$$$ib\n"
            "    .d$$$$$$$b\n"
            "  .d$$@$$$$$$$ib.\n"
            "      d$$i$$b\n"
            "     d$$$$$@$b\n"
            "  .d$@$$$$$$$$@b.\n"
            ".d$$$$i$$$$$$$$$$b.\n"
            "        ###\n"
            "        ###\n"
            "        ###\n";

    file.close();

    std::cout << "ShrubberyCreationForm executed by: " << executor.getName() << std::endl;
}
