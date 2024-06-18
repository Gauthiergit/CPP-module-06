/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:57:31 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/18 18:05:12 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { *this = copy; }

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &change) { (void)change; return *this; }

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& input)
{
	char 		toChar;
	int 		toInt = 0;
	float 		toFloat = 0.0f;
	double		toDouble = 0.0;

	// if (input[input.length() - 1] == 'f')

 
	toFloat = std::atof(input.c_str());
	toChar = static_cast<char>(toFloat);
	toInt = static_cast<int>(toFloat);
	toDouble = static_cast<double>(toFloat);

	if (!std::isprint(toChar))
		std::cout << BLUE << "char: " << RESET << "Non displayable" << std::endl;
	else
		std::cout << BLUE << "char: " << RESET << "'" << toChar << "'" << std::endl;
	std::cout << BLUE << "int: " << RESET << toInt << std::endl;
	std::cout << BLUE << "float: " << RESET << toFloat << ".0f"<< std::endl;
	std::cout << BLUE << "double: " << RESET << toDouble << ".0" << std::endl;
}

// chercher un point dans la string 