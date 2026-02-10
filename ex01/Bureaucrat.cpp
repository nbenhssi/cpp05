/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:22:32 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/02/10 16:15:42 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name(""), grade(0)
{}
Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
    name = b.name;
    grade = b.grade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &Bureaucrat)
{
    this->name = Bureaucrat.name;
    this->grade = Bureaucrat.grade;
    return *this;
}
Bureaucrat::~Bureaucrat()
{}

void Bureaucrat::setName(std::string name)
{
    this->name = name;
}
void Bureaucrat::setGrade(int grade)
{
    this->grade = grade;
}
std::string Bureaucrat::getName()
{
    return name;
}
int Bureaucrat::getGrade()
{
    return grade;
}
void Bureaucrat::incGrade(Bureaucrat &bureaucrat)
{
    
    try
    {
        std::exception e;
        bureaucrat.grade++;
        if (bureaucrat.grade > 150)
            throw e;
    }
    catch(std::exception& e)
    {
        std::cerr << "Bureaucrat::GradeTooHighException" << e.what() << std::endl;
    }
}
void Bureaucrat::decGrade(Bureaucrat &bureaucrat)
{
    try
    {
        std::exception e;
        bureaucrat.grade--;
        if (bureaucrat.grade < 1)
            throw e;
    }
    catch(std::exception& e)
    {
        std::cerr << "Bureaucrat::GradeTooLowException" << e.what() << std::endl;
    }
    
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &B)
{
    os << B.name << ", bureaucrat grade" << B.grade;
    return os;
}
