/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:46:25 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/30 19:50:14 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <climits>

int	main(void)
{
	std::cout << "--- SUBJECT TEST ---" << std::endl;

	try
	{
		Span	sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- FULL SPAN TEST ---" << std::endl;

	try
	{
		Span	sp(2);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- NOT ENOUGH VALUES TEST ---" << std::endl;

	try
	{
		Span	sp(5);

		sp.addNumber(42);
		sp.shortestSpan();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- 10,000 VALUES TEST ---" << std::endl;

	try
	{
		Span				sp(10000);
		std::vector<int>	numbers;
		int					i;

		i = 0;
		while (i < 10000)
		{
			numbers.push_back(i);
			i++;
		}

		sp.addNumbers(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- RANGE OVERFLOW TEST ---" << std::endl;

	try
	{
		Span				sp(3);
		std::vector<int>	numbers;

		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);

		sp.addNumbers(numbers.begin(), numbers.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- INT LIMITS TEST ---" << std::endl;

	try
	{
		Span	sp(2);

		sp.addNumber(INT_MIN);
		sp.addNumber(INT_MAX);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}