/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:31:23 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/03 22:31:51 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute; 
    public:
        Form();
        Form(std::string name, int _grade_s, int _grade_e);
        Form(const Form &copy);
        ~Form();
        Form &operator=(const Form &copy);
        
        void beSigned(const Bureaucrat &b);
        const std::string &getName()const;
        int getGradeToSign()const;
        int getGradeToExecute()const;
        bool getSignedStatus()const;
        
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const Form &form);