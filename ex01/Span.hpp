/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:07:30 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/31 11:10:39 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <limits>
#include <iostream>
#include <iterator>

class Span {
	private:
		std::vector<int>	*_v;
		unsigned int		_pos;
		unsigned int		_limit;
		int					_max;
		int					_min;
		Span();
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &cp);
		Span &operator=(const Span &cp);
		void addNumber(int num);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void);
		int longestSpan(void);

		std::vector<int> getVector(void);
		int getPos(void);

		class SpanFullException;
		class TooFewValuesStored;
};

#endif
