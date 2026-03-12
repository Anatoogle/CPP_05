/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:33:11 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 13:35:01 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>

class AForm;

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(int grade);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception{
            public: 
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        void signForm(AForm &form)const;
        
        const std::string &getName()const;
        int getGrade()const;
        void incrementGrade();
        void decrementGrade();

        void executeForm(AForm const & form)const;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& src);
