/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:39:13 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/30 15:15:01 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	std::vector<int>	vector;
	std::list<int>		list;

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);

	list.push_back(10);
	list.push_back(20);
	list.push_back(30);

	try
	{
		std::vector<int>::iterator	it;

		std::cout << "Searching the integer 20 inside vector..." << std::endl;
		it = easyfind(vector, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator	it;

		std::cout << "\nSearching the integer 42 inside vector..." << std::endl;
		it = easyfind(vector, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator	it;

		std::cout << "\nSearching the integer 30 inside list..." << std::endl;
		it = easyfind(list, 30);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator	it;

		std::cout << "\nSearching the integer 42 inside list..." << std::endl;
		it = easyfind(list, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}