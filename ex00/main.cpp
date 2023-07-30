/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:32:32 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/30 13:30:05 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) {
	std::vector<int> v;
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}
	std::cout << "VECTOR: ";
	for (int i = 0; i < 5; i++) {
		std::cout << *::easyfind(v, i) << " ";
	}
	std::cout << std::endl;
	try {
		std::cout << "VECTOR: ";
		std::cout << *::easyfind(v, 15) << std::endl;
	} catch (std::exception &e) {
		std::cout << "VECTOR: " << e.what() << std::endl;
	}

	std::list<int> list;
	for (int i = 10; i < 15; i++) {
		list.push_front(i);
	}
	std::cout << "LIST: ";
	for (int i = 10; i < 15; i++) {
		std::cout << *::easyfind(list, i) << " ";
	}
	std::cout << std::endl;
	try {
		std::cout << "LIST: ";
		std::cout << *::easyfind(list, 14) << std::endl;
	} catch (std::exception &e) {
		std::cout << "LIST: " << e.what() << std::endl;
	}

	return (0);
}
