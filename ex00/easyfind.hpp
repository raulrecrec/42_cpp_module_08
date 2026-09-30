/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 14:39:52 by rexposit          #+#    #+#             */
/*   Updated: 2026/09/30 15:02:41 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	iterator;

	iterator = std::find(container.begin(), container.end(), value);
	if (iterator != container.end())
		return (iterator);
	else
		throw std::runtime_error("Value not found");
}

#endif