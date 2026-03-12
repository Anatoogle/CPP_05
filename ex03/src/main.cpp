/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:29:28 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 23:22:49 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2)
        return 0;
    
    int check = atoi(argv[1]);
    switch(check){
        // Test for Intern
        case 1:
        {
            Intern junior;
            AForm* form;

            form = junior.makeForm("shrubbery creation", "HOME");

            if(!form)
                break;
            
            Bureaucrat pete("Pete", 20);

            pete.signForm(*form);
            pete.executeForm(*form);

            delete form;
            
            break;
        }
        case 2:
        {
            Intern junior;
            AForm* form;

            form = junior.makeForm("robotomy request", "Robo");

            if(!form)
                break;
            
            Bureaucrat pete("Pete", 20);

            pete.signForm(*form);
            pete.executeForm(*form);

            delete form;
            
            break;
        }
        case 3:
        {
            Intern junior;
            AForm* form;

            form = junior.makeForm("presidential pardon", "Angelo");

            if(!form)
                break;
            
            Bureaucrat pete("Pete", 20);

            pete.signForm(*form);
            pete.executeForm(*form);

            delete form;
            
            break;
        }
        case 4:
        {
            Intern junior;
            AForm* form;

            form = junior.makeForm("shrubbery creation", "HOME");

            if(!form)
                break;
                
            std::cout << "SHOULD NOT BE HERE" << std::endl;
            
            Bureaucrat pete("Pete", 150);
            
            pete.signForm(*form);
            pete.executeForm(*form);

            delete form;
            
            break;
        }
        case 5:
        {
            Intern junior;
            AForm* form;

            form = junior.makeForm("Wrong Shrubbery", "HOME");

            if(!form)
                break;
                
            std::cout << "SHOULD NOT REACH HERE!!" << std::endl;
            
            break;
        }
    }

    return 0;
}
