/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:40:41 by ssghioua          #+#    #+#             */
/*   Updated: 2025/12/20 06:40:42 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

int	main(void) {
	std::srand(std::time(NULL));
	Span	sp = Span(5);
	std::cout << "\n";
	std::cout << "TEST SPAN 5 VALUES\n";
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";
	} catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "TEST SPAN INT MIN/MAX VALUES\n";
	Span	sp1 = Span(4);
	try {
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(-2147483648);
		sp1.addNumber(2147483647);
		std::cout << sp1.shortestSpan() << "\n";
		std::cout << sp1.longestSpan() << "\n";
	} catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "TEST SPAN with 20000 VALUES\n";
	Span	sp2 = Span(20000);
	try {
		for (int i = 0; i < 20000; i++)
			sp2.addNumber(std::rand());
		std::cout << sp2.shortestSpan() << "\n";
		std::cout << sp2.longestSpan() << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n";
	std::cout << "TEST FULL SPAN EXCEPTION TRIGERRED \n";
	Span	sp3 = Span(10000);
	try {
		for (int i = 0; i < 10001; i++)
			sp3.addNumber(std::rand());
		std::cout << sp3.shortestSpan() << "\n";
		std::cout << sp3.longestSpan() << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "TEST NO SHORT SPAN EXCEPTION TRIGERRED \n";
	Span	sp4 = Span(2);
	sp4.addNumber(42);
	try {
		std::cout << sp4.shortestSpan() << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}
	
	std::cout << "\n";
	std::cout << "TEST NO LONGEST SPAN EXCEPTION TRIGERRED \n";
	Span	sp5 = Span(2);
	sp5.addNumber(42);
	try {
		std::cout << sp5.longestSpan() << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "TEST RANGES OF NUMBER FILL\n";
	std::vector<int>	vtest;
	vtest.reserve(5);
	vtest.push_back(10);
	vtest.push_back(20);
	vtest.push_back(30);
	vtest.push_back(40);
	vtest.push_back(50);
	Span	sp6 = Span(4);
	try {
		sp6.fillSpan<std::vector<int>::const_iterator>(vtest.begin(), vtest.end());
		std::cout << sp6.shortestSpan() << "\n";
		std::cout << sp6.longestSpan() << "\n";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << "\n";
	}
	return (0);
}
