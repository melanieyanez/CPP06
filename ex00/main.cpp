/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:39:04 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/28 09:17:14 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv){

	if (argc != 2)
	{
		std::cerr << "Please enter only one argument!" << std::endl;
		return 1;
	}
	ScalarConverter::convert(std::string(argv[1]));
	
	return 0;
}