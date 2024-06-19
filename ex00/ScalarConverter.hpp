/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:23:53 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/19 13:18:04 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class ScalarConverter
{
	private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter& operator=(const ScalarConverter &change);

	public:

	~ScalarConverter();
	static void convert(const std::string& input);
	static int countoccur(const std::string& input, const char cara);
	static bool checkinput(const std::string& input);
	static bool onlyzero(const std::string& input);
};

#endif