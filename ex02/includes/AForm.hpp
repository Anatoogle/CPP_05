/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:31:23 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 14:15:45 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute; 
    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &copy);
        virtual ~AForm();
        AForm &operator=(const AForm &copy);
        
        void beSigned(const Bureaucrat &b);
        const std::string &getName()const;
        int getGradeToSign()const;
        int getGradeToExecute()const;
        bool getSignedStatus()const;
        
        virtual void execute(Bureaucrat const &executor)const = 0 ;
        
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
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);