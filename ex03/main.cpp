/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:48:55 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/07 13:48:55 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main()
{
    std::srand(42);

    Intern intern;
    AForm* f = NULL;

    // --- Formulaires valides ---
    std::cout << "--- Formulaires valides ---" << std::endl;

    f = intern.makeForm("shrubbery creation", "garden");
    if (f)
    { 
        Bureaucrat b("Bob", 1); 
        b.signForm(*f); 
        b.executeForm(*f); 
        delete f;
     }

    f = intern.makeForm("robotomy request", "Bender");
    if (f)
    { 
        Bureaucrat b("Bob", 1);
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }

    f = intern.makeForm("presidential pardon", "Arthur Dent");
    if (f)
    {
        Bureaucrat b("Bob", 1);
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }

    // --- Nom inconnu ---
    std::cout << "\n--- Nom inconnu ---" << std::endl;
    f = intern.makeForm("coffee request", "Bender");
    if (!f)
        std::cout << "Aucun formulaire cree" << std::endl;

    return 0;
}