/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:07:30 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/30 16:51:59 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <limits>
#include <iostream>

class Span {
	private:
		std::vector<int>	*_v;
		unsigned int		_pos;
		unsigned int		_limit;
		Span();
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &cp);
		Span &operator=(const Span &cp);
		void addNumber(int num);
		int shortestSpan(void);
		int longestSpan(void);

		class SpanFullException;
		class TooFewValuesStored;
};

#endif
