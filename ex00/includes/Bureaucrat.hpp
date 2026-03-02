/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:33:11 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/02 03:37:45 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>

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
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
        
        std::string getName()const;
        int getGrade();
        void incrementGrade(int value);
        void decrementGrade(int value);
        
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& src);
