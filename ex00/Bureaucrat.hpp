/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:16:26 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/02/10 15:22:13 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        std::string name;
        int garde;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat b);
        void setName(std::string name);
        void setGrade(int grade);
        std::string getName();
        int getGrade();
};

#endif