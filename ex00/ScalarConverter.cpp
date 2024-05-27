/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:32:28 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/27 18:58:42 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
		
ScalarConverter::ScalarConverter(const ScalarConverter &src){(void)src;}

ScalarConverter::~ScalarConverter(){}
		
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs){(void)rhs; return *this;}

void ScalarConverter::convertToChar(double value){
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else {
		if (isprint(static_cast<char>(value)))
			std::cout << "char: '" << static_cast<char>(value) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::convertToInt(double value){
	if (std::isnan(value)
		|| std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::convertToFloat(double value){
	(void)value;
}

void ScalarConverter::convertToDouble(double value){
	(void)value;
}

void convert(const std::string &literal){
	
	char *endptr;
	double value = strtod(literal.c_str(), &endptr);
	
	if (*endptr != '\0'
		&& literal.length() == 1
		&& isprint(literal[0])
		&& !isdigit(literal[0]))
	{
		std::cout << "char: '" << literal[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
	}
	else
	{
		ScalarConverter::convertToChar(value);
		ScalarConverter::convertToInt(value);
		ScalarConverter::convertToFloat(value);
		ScalarConverter::convertToDouble(value);
	}
}