/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:50:31 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/07 13:51:47 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    // Test 1 : signature réussie
    try
    {
        Bureaucrat b("Alice", 1);
        Form f("TaxForm", 10, 50);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Test 2 : grade trop bas pour signer
    try
    {
        Bureaucrat b("Bob", 100);
        Form f("SecretForm", 10, 50);
        std::cout << b << std::endl;
        b.signForm(f);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---" << std::endl;

    // Test 3 : grade invalide pour le formulaire
    try
    {
        Form f("BadForm", 0, 50);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}