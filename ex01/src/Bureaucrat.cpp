/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 02:38:00 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/03 23:22:08 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat():_name("default_Bureaucrat"), _grade(150)
{
    std::cout << "+ Bureaucrat Constructor called - Default"
                << "\n\tName: " << _name 
                << "\n\tGrade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name):_name(name), _grade(150)
{
    std::cout << "+ Bureaucrat Constructor called - Name"
                << "\n\tName: " << _name 
                << "\n\tGrade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(int grade):_name("default_Bureaucrat")
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();

    _grade = grade;
    
    std::cout   << "+ Bureaucrat Constructor called - Grade"
                << "\n\tName: " << _name 
                << "\n\tGrade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();

    _grade = grade;

    std::cout   << "+ Bureaucrat constructor called - Name/Grade" 
                << "\n\tName: " << _name 
                << "\n\tGrade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):_name(copy._name), _grade(copy._grade)
{
    std::cout   << "+ Bureaucrat constructor called - Copy" 
                << "\n\tName: " << _name 
                << "\n\tGrade: " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if(this != &copy)
        _grade = copy._grade;

    std::cout   << "= Bureaucrat Copy assignment operator called" 
                << "\n\tName: " << _name 
                << "\n\tGrade: " << _grade << std::endl;
    
    return *this;
}

Bureaucrat::~Bureaucrat()
{    
    std::cout   << "- Bureaucrat Destructor called" 
                << "\n\tName: " << _name 
                << "\n\tGrade: " << _grade << std::endl;
}


const std::string &Bureaucrat::getName()const
{
    return _name;
}

int Bureaucrat::getGrade()const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if(_grade + 1 > 150)
        throw GradeTooHighException();
        
    _grade++;
}

void Bureaucrat::decrementGrade()
{
    if(_grade - 1 < 1)
        throw GradeTooLowException();
    
    _grade--;
}

void Bureaucrat::signForm(Form &form)const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl; 
    }
    catch(const std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
    os << src.getName() << ", bureaucrat grade " << src.getGrade(); 

    return os;
}
