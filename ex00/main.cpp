/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:15:21 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/20 11:36:04 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	// ScalarConverter convert;
	if (argc != 2)
		std::cerr << RED << "Use: ./convert <input>" << RESET << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
