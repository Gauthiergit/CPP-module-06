/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:23:53 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/17 17:26:37 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
	/*private content*/

	public:
	ScalarConverter();
	ScalarConverter(/*param*/);
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter &change);
};

#endif