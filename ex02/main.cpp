/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 21:42:15 by rexposit          #+#    #+#             */
/*   Updated: 2026/10/01 00:15:37 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <string>

int	main(void)
{
	std::cout << "--- SUBJECT TEST ---" << std::endl;

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top (expected 17): " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size (expected 1): " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Elements (expected 5 3 5 737 0): ";

	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	ite;

	it = mstack.begin();
	ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	std::stack<int>	s(mstack);

	std::cout << "\n--- COPY CONSTRUCTOR TEST ---" << std::endl;

	MutantStack<int>	copy(mstack);

	std::cout << "Original size: " << mstack.size() << std::endl;
	std::cout << "Copy size:     " << copy.size() << std::endl;
	std::cout << "Original top:  " << mstack.top() << std::endl;
	std::cout << "Copy top:      " << copy.top() << std::endl;

	copy.pop();

	std::cout << "Copy size after pop (expected 4): " << copy.size() << std::endl;
	std::cout << "Original size (expected 5):       " << mstack.size() << std::endl;

	std::cout << "\n--- ASSIGNMENT OPERATOR TEST ---" << std::endl;

	MutantStack<int>	assigned;

	assigned = mstack;

	std::cout << "Assigned size (expected 5): " << assigned.size() << std::endl;
	std::cout << "Assigned top (expected 0):  " << assigned.top() << std::endl;

	std::cout << "\n--- STRING TEST ---" << std::endl;

	MutantStack<std::string>	strings;

	strings.push("Hello");
	strings.push("from");
	strings.push("MutantStack");

	std::cout << "Elements (expected: Hello from MutantStack): ";

	MutantStack<std::string>::iterator	str_it;
	MutantStack<std::string>::iterator	str_ite;

	str_it = strings.begin();
	str_ite = strings.end();

	while (str_it != str_ite)
	{
		std::cout << *str_it << " ";
		++str_it;
	}
	std::cout << std::endl;
}