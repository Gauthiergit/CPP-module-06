/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:57:31 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/20 11:30:24 by gpeyre           ###   ########.fr       */
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
	if (!ScalarConverter::checkinput(input))
	{
		std::cout << RED << "Error: bad input" << RESET << std::endl;
		return ;
	}

	float toFloat = std::atof(input.c_str());
	char toChar = static_cast<char>(toFloat);
	int toInt = static_cast<int>(toFloat);
	double toDouble = static_cast<double>(toFloat);
	std::string infinite[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	if (((input[0] == '-' || input[0] == '+') && std::isalpha(input[1])) || std::isalpha(input[0]))
	{
		std::cout << BLUE << "char: " << RESET << "Impossible" << std::endl;
		std::cout << BLUE << "int: " << RESET << "Impossible" << std::endl;

		for(int i = 0; i < 6; i++)
		{
			if (infinite[i] == input)
			{
				if (i < 3)
				{
					std::cout << BLUE << "float: " << RESET << infinite[i] << std::endl;
					std::cout << BLUE << "double: " << RESET << infinite[i + 3] << std::endl;
				}
				else
				{
					std::cout << BLUE << "float: " << RESET << infinite[i - 3] << std::endl;
					std::cout << BLUE << "double: " << RESET << infinite[i] << std::endl;
				}
				return ;
			}
		}
		std::cout << BLUE << "float: " << RESET << "Impossible" << std::endl;
		std::cout << BLUE << "double: " << RESET << "Impossible" << std::endl;
		return ;
	}

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
