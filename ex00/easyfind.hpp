/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:32:18 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/02 18:38:41 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>

class NotFoundException : public std::exception {
	virtual const char *what() const throw() { return ("NotFoundException: Element not found!"); }
};

template <typename T> typename T::iterator easyfind(T &cont, int x) {
	typename T::iterator	res = std::find(cont.begin(), cont.end(), x);
	if (res == cont.end())
		throw NotFoundException();
	return (res);
}

template <typename T> typename T::iterator easyfind(T const &cont, int x) {
	typename T::iterator	res = std::find(cont.begin(), cont.end(), x);
	if (res == cont.end())
		throw NotFoundException();
	return (res);
}

#endif
