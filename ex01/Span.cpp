/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:00:35 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/30 19:52:20 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <climits>

Span::Span()
	: max_capacity(0)
{
}

Span::Span(unsigned int n)
:	max_capacity(n)
{
}

Span::Span(const Span &other)
:	values(other.values), max_capacity(other.max_capacity)
{
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->values = other.values;
		this->max_capacity = other.max_capacity;
	}

	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int value)
{
	if (values.size() < max_capacity)
		values.push_back(value);
	else
		throw std::runtime_error("Span is full");
}

long long	Span::shortestSpan()
{
	if (values.size() < 2)
		throw std::runtime_error("Not enough values to calculate span");

	std::vector<int>	sorted_values(values);

	std::sort(sorted_values.begin(), sorted_values.end());

	size_t			i;
	long long		shortest;
	long long		value;

	i = 1;
	shortest = static_cast<long long>(sorted_values[1]) - sorted_values[0];
	while (i < sorted_values.size() - 1)
	{
		value = static_cast<long long>(sorted_values[i + 1]) - sorted_values[i];
		if (value < shortest)
			shortest = value;
		i++;
	}

	return (shortest);
}

long long	Span::longestSpan()
{
	if (values.size() < 2)
		throw std::runtime_error("Not enough values to calculate span");

	long long	max_value;
	long long	min_value;

	max_value = *std::max_element(values.begin(), values.end());
	min_value = *std::min_element(values.begin(), values.end());

	return (max_value - min_value);
}