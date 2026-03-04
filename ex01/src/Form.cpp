/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:32:12 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/03 23:16:56 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form():_name("defaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout   << "+ Form Constructor called - default" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
}

Form::Form(std::string name, int grade_s, int grade_e):_name(name), _isSigned(false), _gradeToSign(grade_s), _gradeToExecute(grade_e)
{
    if(grade_s > 150 || grade_e > 150)
        throw GradeTooLowException();
    else if(grade_s < 1 || grade_e < 1)
        throw GradeTooHighException();

    std::cout   << "+ Form Constructor called - Name / Grade" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
}

Form::~Form()
{
    std::cout   << "- Form Destructor called" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
}

Form::Form(const Form &copy):_name(copy._name), _isSigned(false), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    if(_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    else if(_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();   

    std::cout   << "+ Form Constructor called - copy" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
}

const std::string &Form::getName()const
{
    return _name;
}

int Form::getGradeToSign()const
{
    return _gradeToSign;
}

int Form::getGradeToExecute()const
{
    return _gradeToExecute;
}

bool Form::getSignedStatus()const
{
    return _isSigned;
}

void Form::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

Form &Form::operator=(const Form &copy)
{
    if(this != &copy)
        _isSigned = copy._isSigned;

    std::cout   << "= Form Copy assignment operator" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
                
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    std::string isSigned = "No";
    if(form.getSignedStatus())
        isSigned = "Yes";
        
    os  << "Form: " << form.getName()
        << ", Is Signed: " << form.getSignedStatus()
        << ", Grade to Sign: " << form.getGradeToSign()
        << ", Grade to Execute: " << form.getGradeToExecute();

    return os;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade too low!";
}
