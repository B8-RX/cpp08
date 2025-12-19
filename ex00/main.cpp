/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 03:56:31 by ssghioua          #+#    #+#             */
/*   Updated: 2025/12/17 03:56:32 by ssghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int	main(void) {
	
	std::vector<int> v;
	v.reserve(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	std::cout << "vector container\n";
	try {
		std::vector<int>::iterator it = easyfind(v, 99);
		std::cout << "Element found in container v : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	try {
		std::vector<int>::iterator it = easyfind(v, 2);
		std::cout << "Element found in container v : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	
	const std::vector<int> cv = v;
	std::cout << "\n\n";
	std::cout << "const vector container\n";
	try {
		std::vector<int>::const_iterator it = easyfind(cv, 99);
		std::cout << "Element found in container cv : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	try {
		std::vector<int>::const_iterator it = easyfind(cv, 2);
		std::cout << "Element found in container cv : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::list<int> l;
	l.assign(v.begin(), v.end());
	std::cout << "\n\n";
	std::cout << "list container\n";
	try {
		std::list<int>::iterator it = easyfind(l, 99);
		std::cout << "Element found in container l : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	try {
		std::list<int>::iterator it = easyfind(l, 2);
		std::cout << "Element found in container l : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	
	const std::list<int> cl = l;
	std::cout << "\n\n";
	std::cout << "const list container\n";
	try {
		std::list<int>::const_iterator it = easyfind(cl, 99);
		std::cout << "Element found in container cl : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	try {
		std::list<int>::const_iterator it = easyfind(cl, 2);
		std::cout << "Element found in container cl : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	return (0);
}
