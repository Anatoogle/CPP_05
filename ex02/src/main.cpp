/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:29:28 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 14:10:42 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <stdlib.h>

int main(int argc, char **argv)
{
    (void)argc;
    
    int check = atoi(argv[1]);
    switch(check){
        // Test for ShrubberyCreationForm
        case 1:
        {
            Bureaucrat bob("bob", 150);
            ShrubberyCreationForm form("home");

            form.beSigned(bob);
            form.execute(bob);
            break;
        }
        case 2:
        {
            Bureaucrat bob("bob", 140);
            ShrubberyCreationForm form("home");

            form.beSigned(bob);
            form.execute(bob);
            break;
        }
        case 3:
        {
            Bureaucrat bob("bob", 130);
            ShrubberyCreationForm form("home");

            form.beSigned(bob);
            form.execute(bob);
            break;
        }
        
        // Test for RobotomyRequestForm
        case 4:
        {
            Bureaucrat john("john", 150);
            RobotomyRequestForm form("Robo");

            form.beSigned(john);
            form.execute(john);
            break;
        }
        case 5:
        {
            Bureaucrat john("john", 60);
            RobotomyRequestForm form("Robo");

            form.beSigned(john);
            form.execute(john);
            break;
        }
        case 6:
        {
            Bureaucrat john("john", 20);
            RobotomyRequestForm form("Robo");

            form.beSigned(john);
            form.execute(john);
            break;
        }
        
        // Test for PresidentialPardonForm
        case 7:
        {
            Bureaucrat oli("Oli", 150);
            PresidentialPardonForm form("A38");

            form.beSigned(oli);
            form.execute(oli);
            break;
        }
        case 8:
        {
            Bureaucrat oli("Oli", 20);
            PresidentialPardonForm form("A38");

            form.beSigned(oli);
            form.execute(oli);
            break;
        }
        case 9:
        {
            Bureaucrat oli("Oli", 2);
            PresidentialPardonForm form("A38");

            form.beSigned(oli);
            form.execute(oli);
            break;
        }
        
        case 10:
        {
            Bureaucrat oli("Oli", 2);
            PresidentialPardonForm form("A38");

            form.beSigned(oli);
            oli.executeForm(form);
            break;
        }

    }

    return 0;
}
