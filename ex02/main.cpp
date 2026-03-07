/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:49:53 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/07 13:49:53 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main()
{
    std::srand(42);

    // --- ShrubberyCreationForm ---
    std::cout << "--- ShrubberyCreationForm ---" << std::endl;
    {
        Bureaucrat alice("Alice", 130);
        ShrubberyCreationForm f("garden");
        alice.signForm(f);
        alice.executeForm(f); // cree garden_shrubbery
    }

    // --- RobotomyRequestForm ---
    std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
    {
        Bureaucrat bob("Bob", 45);
        RobotomyRequestForm f("Bender");
        bob.signForm(f);
        bob.executeForm(f);
        bob.executeForm(f); // deux fois pour voir le 50/50
    }

    // --- PresidentialPardonForm ---
    std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
    {
        Bureaucrat zaphod("Zaphod", 5);
        PresidentialPardonForm f("Arthur Dent");
        zaphod.signForm(f);
        zaphod.executeForm(f);
    }

    // --- Erreurs ---
    std::cout << "\n--- Erreurs ---" << std::endl;
    {
        Bureaucrat weakling("Weakling", 150);
        RobotomyRequestForm f("R2D2");
        weakling.signForm(f);   // grade trop bas pour signer
        weakling.executeForm(f); // non signe -> echec
    }

    return 0;
}