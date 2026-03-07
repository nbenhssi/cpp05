/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:50:25 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/07 13:50:25 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("default"), is_Signed(false), gradeSign(30), gradeExecute(30)
{}

Form::Form(const std::string& name, int gradeSign, int gradeExecute)
    : name(name), is_Signed(false), gradeSign(gradeSign), gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& b) : name(b.name), is_Signed(b.is_Signed), gradeSign(b.gradeSign), gradeExecute(b.gradeExecute)
{}

Form& Form::operator=(const Form& form)
{
    if (this != &form)
        is_Signed = form.is_Signed;
    return *this;
} 

Form::~Form()
{}

std::string Form::getName() const 
{
    return name; 
}
bool        Form::getIsSigned() const
{
    return is_Signed;
}
int         Form::getGradeSign() const
{ 
    return gradeSign; 
}
int         Form::getGradeExecute() const 
{ 
    return gradeExecute; 
}

bool Form::beSigned(const Bureaucrat* b)
{
    if (b->getGrade() > gradeSign)
        throw GradeTooLowException();
    is_Signed = true;
    return true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: "                      << f.getName()
       << " | Signed: "                 << (f.getIsSigned() ? "yes" : "no")
       << " | Sign grade required: "    << f.getGradeSign()
       << " | Execute grade required: " << f.getGradeExecute();
    return os;
}