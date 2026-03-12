/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:32:12 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 08:48:20 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm():_name("defaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout   << "+ Form Constructor called - default" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();

    std::cout   << "+ Form Constructor called - Name / Grade" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
}

AForm::~AForm()
{
    std::cout   << "- Form Destructor called" 
                << "\n\tName:\t\t" << _name 
                << "\n\tGradeToSign:\t" << _gradeToSign 
                << "\n\tGradeToExecute:\t" << _gradeToExecute 
                << "\n\tisSigned:\t" << _isSigned << std::endl;
}

AForm::AForm(const AForm &copy):_name(copy._name), _isSigned(false), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
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

const std::string &AForm::getName()const
{
    return _name;
}

int AForm::getGradeToSign()const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute()const
{
    return _gradeToExecute;
}

bool AForm::getSignedStatus()const
{
    return _isSigned;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw Bureaucrat::GradeTooLowException();

    std::cout   << "Form signed by: " << b.getName() << std::endl;  
}

AForm &AForm::operator=(const AForm &copy)
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

std::ostream &operator<<(std::ostream &os, const AForm &form)
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

void AForm::execute(Bureaucrat const &executor)const
{
    (void)executor;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}