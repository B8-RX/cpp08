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
	
	const std::vector<int> cv = v;

	try {
		std::vector<int>::iterator it = easyfind(v, 5);
		std::cout << "Element found in v : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	try {
		std::vector<int>::const_iterator it = easyfind(cv, 2);
		std::cout << "Element found in cv : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	int set[] = {9, 8, 7, 6};
	std::list<, sizeof(set)/sizeof(*set)>;
	// const std::list<int> cl = {5, 6, 7, 8};

	try {
		std::list<int>::iterator it = easyfind(l, 9);
		std::cout << "Element found in l : " << *it << "\n";
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	
	// try {
	// 	std::list<int>::iterator it = easyfind(cl, 9);
	// 	std::cout << "Element found in l : " << *it << "\n";
	// } catch (std::exception& e) {
	// 	std::cerr << e.what() << "\n";
	// }
	return (0);
}
