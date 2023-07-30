/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:49:27 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/30 17:29:59 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void) {
	Span s1 = Span(2);

	for (int i = 0; i < 5; i++) {
		try {
			s1.addNumber(i);
			std::cout << i << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "s1 ShortestSpan: " << s1.shortestSpan() << std::endl;
	std::cout << "s1 LongestSpan: " << s1.longestSpan() << std::endl;

	Span s2 = Span(50);

	for (int i = 1; i < 50; i += 5) {
		s2.addNumber(i);
	}
	std::cout << "s2 ShortestSpan: " << s2.shortestSpan() << std::endl;
	std::cout << "s2 LongestSpan: " << s2.longestSpan() << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "sp ShortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "sp LongestSpan: " << sp.longestSpan() << std::endl;

	return (0);
}
