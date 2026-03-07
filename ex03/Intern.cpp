/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:48:49 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/07 13:48:49 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& i)
{
    *this = i;
}

Intern& Intern::operator=(const Intern& i)
{
    if (this != &i)
    {
    }
    return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    
}