/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:50:08 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/07 13:50:08 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r) : AForm(r), target(r.target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
    if (this != &r)
    {
        AForm::operator=(r);
        target = r.target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::doExecute() const
{
    std::cout << target << "has been robotomized successfully" << std::endl;
}
