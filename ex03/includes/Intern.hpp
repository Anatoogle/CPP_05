/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:21:11 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 22:19:19 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#include <iostream>

class Intern
{
    public:
        Intern();
        Intern(const Intern &copy);
        ~Intern();
        Intern &operator=(const Intern &copy);
        
        AForm *makeForm(const std::string &formName, const std::string &target);
};
