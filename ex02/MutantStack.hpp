/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 21:42:27 by rexposit          #+#    #+#             */
/*   Updated: 2026/10/01 00:10:45 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack	&operator=(const MutantStack &other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"

#endif