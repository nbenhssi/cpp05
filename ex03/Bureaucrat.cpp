/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:48:41 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/07 13:48:41 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(10)
{}

Bureaucrat::Bureaucrat(Bureaucrat &b) : name(b.name), grade(b.grade)
{
    if(b.grade < 1)
    {
        throw GradeTooHighException();
    }
    if (b.grade> 150 )
    {
        throw GradeTooLowException();
    }
}

Bureaucrat Bureaucrat::operator=(Bureaucrat &b)
{
    if (this != &b)
        this->grade = b.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const std::string Bureaucrat::getName() const
{
    return name;
}
int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;

}
void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    throw(2);
    return "Grade is too High!";
}


const char *Bureaucrat::GradeTooLowException::what() const throw()
{
        return "Grade is too low!";
}

std::ostream &operator<<(std::ostream& os, Bureaucrat &b)
{
    std::cout<< b.getName() << ", bureaucrat grade" << b.getGrade() <<"." << std::endl;
    return os;
}

void Bureaucrat::signForm(AForm &f) const
{
    try
    {       
        f.beSigned(*this);
        std::cout << this->getName() << " signed" <<f.getName();
    }
    catch(std::exception& e)
    {
        std::cout<< "couldn't sign" << f.getName() <<"because"<<  e.what()<< std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
