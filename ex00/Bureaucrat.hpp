/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:16:26 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/02/10 15:59:53 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &b);
        Bureaucrat& operator=(const Bureaucrat& Bureaucrat);
        ~Bureaucrat();
        void setName(std::string name);
        void setGrade(int grade);
        std::string getName();
        int getGrade();
        void incGrade(Bureaucrat& bureaucrat);
        void decGrade(Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);

#endif