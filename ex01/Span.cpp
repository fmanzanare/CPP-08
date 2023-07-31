/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:12:47 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/31 11:10:43 by fmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::SpanFullException : public std::exception {
	virtual const char *what() const throw() {
		return ("SpanFullException: The Span is already full.");
	}
};

class Span::TooFewValuesStored : public std::exception {
	virtual const char *what() const throw() {
		return ("TooFewValuesStored: The Span is empty or only has 1 value.");
	}
};

Span::Span() {}

Span::Span(unsigned int N) {
	this->_v = new std::vector<int>(N, 0);
	this->_pos = 0;
	this->_limit = N;
	this->_max = INT_MIN;
	this->_min = INT_MAX;
}

Span::~Span() {
	delete this->_v;
}

Span::Span(const Span &cp) {
	int	N = cp._v->size();
	this->_v = new std::vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		(*this->_v)[i] = cp._v->at(i);
	}
	this->_pos = cp._pos;
	this->_max = cp._max;
	this->_min = cp._min;
}

Span &Span::operator=(const Span &cp) {
	delete this->_v;
	int	N = cp._v->size();
	this->_v = new std::vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		(*this->_v)[i] = cp._v->at(i);
	}
	this->_pos = cp._pos;
	this->_max = cp._max;
	this->_min = cp._min;
	return (*this);
}

void Span::addNumber(int num) {
	if ((this->_pos + 1) > this->_limit) {
		throw SpanFullException();
	}

	(*this->_v)[this->_pos] = num;
	if (num > this->_max)
		this->_max = num;
	if (num < this->_min)
		this->_min = num;
	this->_pos++;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if ((this->_pos + 1) > this->_limit)
		throw SpanFullException();
	this->_v->insert((this->_v->begin() + this->_pos), begin, end);
	this->_max = *std::max_element(begin, end);
	this->_min = *std::min_element(begin, end);
	this->_pos += std::distance(begin, end);
}

int Span::shortestSpan(void) {
	if (this->_pos < 1) {
		throw TooFewValuesStored();
	}

	int shortest = INT_MAX;
	int	dif = 0;
	for (int i = 0; i < (int)this->_pos; i++) {
		for (int j = (i + 1); j < (int)this->_pos; j++) {
			dif = (*this->_v)[i] - (*this->_v)[j];
			if (dif < 0)
				dif *= -1;
			if (shortest > dif)
				shortest = dif;
		}
	}

	return (shortest);
}

int Span::longestSpan(void) {
	if (this->_pos < 1) {
		throw TooFewValuesStored();
	}

	return (this->_max - this->_min);
}

std::vector<int> Span::getVector(void) {
	return (*this->_v);
}

int Span::getPos(void) {
	return (this->_pos);
}
