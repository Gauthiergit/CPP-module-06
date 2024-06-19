/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:57:31 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/19 13:19:42 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &copy) { *this = copy; }

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &change) { (void)change; return *this; }

ScalarConverter::~ScalarConverter() {}

int ScalarConverter::countoccur(const std::string& input, const char cara)
{
	int count = 0;
	for(unsigned int i = 0; i < input.length(); i++)
	{
		if (input[i] == cara)
			count++;
	}
	return (count);
}

bool ScalarConverter::checkinput(const std::string& input)
{
	int point_nb = ScalarConverter::countoccur(input, '.');
	if (point_nb > 1)
		return false;
	else if (point_nb)
	{
		unsigned int i = 0;
		for(; i < input.length() && (std::isdigit(input[i]) || input[i] == '.'); i++);
		if (i >= 3 && (input[i] == 'f' || !input[i]))
			return true;
		else
			return false;
	}
	return true;
}

bool ScalarConverter::onlyzero(const std::string& input)
{
	unsigned int i = 0;
	for(; i < input.length() && std::isdigit(input[i]); i++);
	i++;
	for(; i < input.length() && input[i] == '0'; i++);
	if (!input[i] || input[i] == 'f')
		return (true);
	return (false);
}

void	ScalarConverter::convert(const std::string& input)
{
	char 		toChar;
	int 		toInt = 0;
	float 		toFloat = 0.0f;
	double		toDouble = 0.0;

	if (!ScalarConverter::checkinput(input))
	{
		std::cout << RED << "Error: bad input" << RESET << std::endl;
		return ;
	}

	toFloat = std::atof(input.c_str());
	toChar = static_cast<char>(toFloat);
	toInt = static_cast<int>(toFloat);
	toDouble = static_cast<double>(toFloat);

	if (!std::isprint(toChar))
		std::cout << BLUE << "char: " << RESET << "Non displayable" << std::endl;
	else
		std::cout << BLUE << "char: " << RESET << "'" << toChar << "'" << std::endl;
	
	if (ScalarConverter::countoccur(input, '.') && ScalarConverter::onlyzero(input))
	{
		std::cout << BLUE << "int: " << RESET << toInt << std::endl;
		std::cout << BLUE << "float: " << RESET << toFloat << ".0f"<< std::endl;
		std::cout << BLUE << "double: " << RESET << toDouble << ".0" << std::endl;
	}
	else if (ScalarConverter::countoccur(input, '.'))
	{
		std::cout << BLUE << "int: " << RESET << toInt << std::endl;
		std::cout << BLUE << "float: " << RESET << toFloat << "f" << std::endl;
		std::cout << BLUE << "double: " << RESET << toDouble << std::endl;
	}
	else
	{
		std::cout << BLUE << "int: " << RESET << toInt << std::endl;
		std::cout << BLUE << "float: " << RESET << toFloat << ".0f"<< std::endl;
		std::cout << BLUE << "double: " << RESET << toDouble << ".0" << std::endl;
	}
}
