/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:27:32 by fmanzana          #+#    #+#             */
/*   Updated: 2023/08/02 19:10:54 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main(void) {
	MutantStack<int> mstack;

	std::cout << "First operations over mstack: " << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << std::endl;


	std::cout << "Second operations over mstack: " << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << "std::stack s build through copy constructor: " << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Top of std::stack s: " << s.top() << std::endl;
	s.pop();
	std::cout << "Top of std::stack s -after removing previus top element-: " << s.top() << std::endl;

	return (0);
}
