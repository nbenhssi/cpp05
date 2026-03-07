/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:22:40 by nbenhssi          #+#    #+#             */
/*   Updated: 2026/03/03 15:09:27 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"


int main()
{
    try
	{
		Bureaucrat A1("A1", 200);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
    try
	{
		Bureaucrat A2("A2", -10);
	}
	catch(const std::exception &e)
	{

		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
    try
	{
		Bureaucrat A2("A2", 20);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}