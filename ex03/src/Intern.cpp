/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:58:12 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 22:45:31 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
    std::cout   << "+ Intern Constructor called - Default" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
    std::cout   << "+ Intern Constructor called - Copy" << std::endl;
}

Intern::~Intern()
{
    std::cout   << "- Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout   << "= Intern Copy assignment operator called"  << std::endl;
    if(this != &copy)
        *this = copy;
    return *this;
}

AForm* createShrubbery(const std::string &target)
{
    AForm *form = new ShrubberyCreationForm(target);
    return form;
}

AForm* createRobotomy(const std::string &target)
{
    AForm *form = new RobotomyRequestForm(target);
    return form;
}

AForm* createPresidential(const std::string &target)
{
    AForm *form = new PresidentialPardonForm(target);
    return form;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm *(*allForms[3])(const std::string &target) = {createShrubbery, createRobotomy, createPresidential};
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int length = sizeof(forms) / sizeof(forms[0]);
    int i = 0;
    for (; i < length; i++)
    {
        if(formName == forms[i])
        {
            std::cout << "Intern creates " << forms[i] << std::endl;
            return (allForms[i])(target);
        }
    }

    std::cout << "Form not existing: " << formName << std::endl;
    return NULL;
}
