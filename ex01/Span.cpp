/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanzana <fmanzana@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:12:47 by fmanzana          #+#    #+#             */
/*   Updated: 2023/07/30 17:30:17 by fmanzana         ###   ########.fr       */
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
}

Span &Span::operator=(const Span &cp) {
	delete this->_v;
	int	N = cp._v->size();
	this->_v = new std::vector<int>(N, 0);
	for (int i = 0; i < N; i++) {
		(*this->_v)[i] = cp._v->at(i);
	}
	this->_pos = cp._pos;
	return (*this);
}

void Span::addNumber(int num) {
	if ((this->_pos + 1) > this->_limit) {
		throw SpanFullException();
	}

	(*this->_v)[this->_pos] = num;
	this->_pos++;
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

	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < (int)this->_pos; i++) {
		if (this->_v->at(i) < min) {
			min = this->_v->at(i);
		}
		if (this->_v->at(i) > max) {
			max = this->_v->at(i);
		}
	}

	return (max - min);
}
