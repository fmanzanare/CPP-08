/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:15:12 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/31 13:08:09 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T> class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &cp);
		MutantStack &operator=(const MutantStack &cp);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};

template <typename T> MutantStack<T>::MutantStack() {}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &cp) {
	*this = cp;
}

template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack &cp) {
	std::stack<T>::operator=(cp);
	return (*this);
}

template <typename T> typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
	return (this->c.begin());
}

template <typename T> typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
	return (this->c.end());
}

#endif
