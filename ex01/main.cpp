/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:49:27 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/31 10:46:22 by fmanzana         ###   ########.fr       */
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

	for (int i = 1; i < 50; i++) {
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

	Span s3 = Span(100);

	s3.addNumber(5);
	s3.addNumber(1);
	s3.addNumber(2);
	s3.addNumber(4);
	s3.addNumber(9);
	std::cout << "s3 num of elements (before inserting another vector): " << s3.getPos() << std::endl;

	std::vector<int> s;
	s.push_back(50);
	s.push_back(24);
	s.push_back(45);
	s.push_back(64);
	s.push_back(34);
	s.push_back(12);
	s.push_back(54);
	s.push_back(76);
	s.push_back(77);
	s3.addNumber(s.begin(), s.end());

	std::vector<int> myVectorS3 = s3.getVector();
	std::cout << "s3 numbers: ";
	for (std::vector<int>::iterator i = myVectorS3.begin(); i != myVectorS3.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "s3 num of elements (after inserting another vector): " << s3.getPos() << std::endl;

	return (0);
}
