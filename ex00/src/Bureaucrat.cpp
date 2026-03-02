/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 02:38:00 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/02 04:29:58 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("default_Bureaucrat"), _grade(150)
{
    std::cout << "Default    constructor called. Name: " << _name << ", Grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name):_name(name), _grade(150)
{
    std::cout << "Name       constructor called. Name: " << _name << ", Grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(int grade):_name("default_Bureaucrat")
{
    if(grade < 1)
        throw GradeTooLowException();
    if(grade > 150)
        throw GradeTooHighException();

    _grade = grade;
    
    std::cout << "Grade      constructor called. Name: " << _name << ", Grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
    if(grade < 1)
        throw GradeTooLowException();
    if(grade > 150)
        throw GradeTooHighException();

    _grade = grade;

    std::cout << "Name/Grade constructor called. Name: " << _name << ", Grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):_name(copy._name), _grade(copy._grade)
{
    std::cout << "Copy       constructor called. Name: " << _name << ", Grade: " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if(this != &copy)
        _grade = copy._grade;

    std::cout << "Copy assignment constructor called. Name: " << _name << ", Grade: " << _grade << std::endl;
    
    return *this;
}

Bureaucrat::~Bureaucrat()
{    
    std::cout << "Destructor called. Name: " << _name << ", Grade: " << _grade << std::endl;
}


std::string Bureaucrat::getName()const
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void Bureaucrat::incrementGrade(int value)
{
    if(value < 0)
        return;
    if(_grade + value > 150)
        throw GradeTooHighException();
        
    _grade += value;
}

void Bureaucrat::decrementGrade(int value)
{
    if(_grade - value < 1)
        throw GradeTooLowException();
    
    _grade -= value;
}

        
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade(); 

    return os;
}
