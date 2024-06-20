/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:12:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/20 14:23:47 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer &copy) { *this = copy; }

Serializer&	Serializer::operator=(const Serializer &change) { (void)change; return *this; }

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t int_ptr = reinterpret_cast<uintptr_t>(ptr);
	return (int_ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* data_ptr = reinterpret_cast<Data*>(raw);
	return (data_ptr);
}