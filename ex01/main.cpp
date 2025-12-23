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
	Span s = Span(5);

	try {
		s.addNumber(-20);
		s.addNumber(25);
		s.addNumber(302);
		s.addNumber(72);
		s.addNumber(103);
		std::cout << "span = " << s.shortestSpan() << "\n";
		s.addNumber(99);
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	
	return (0);
}
