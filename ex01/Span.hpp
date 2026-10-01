/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:50:49 by rexposit          #+#    #+#             */
/*   Updated: 2026/10/01 19:29:30 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>

class Span
{
	private:
		std::vector<int>	values;
		unsigned int		max_capacity;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span	&operator=(const Span &other);
		~Span();

		void		addNumber(int value);
		long long	shortestSpan();
		long long	longestSpan();

		template <typename Iterator>
		void	addNumbers(Iterator first, Iterator last);
};

template <typename Iterator>
void	Span::addNumbers(Iterator first, Iterator last)
{
	if (values.size() + std::distance(first, last) > max_capacity)
		throw std::runtime_error("Not enough space to add those values");

	values.insert(values.end(), first, last);
}

#endif