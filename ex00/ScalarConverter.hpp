/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:32:30 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/28 08:20:23 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

class ScalarConverter{
	
	public:
		static void convert(const std::string &literal);

		static void convertToChar(double value);
		static void convertToInt(double value);
		static void convertToFloat(double value);
		static void convertToDouble(double value);
		
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		
		ScalarConverter &operator=(const ScalarConverter &rhs);
};

#endif