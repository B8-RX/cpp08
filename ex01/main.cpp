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
#include <exception>
#include <iostream>

int	main(void) {
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";
		sp.addNumber(99);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	
	return (0);
}
