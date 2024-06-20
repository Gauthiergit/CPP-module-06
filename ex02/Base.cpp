/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:11:29 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/20 16:50:15 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base * generate(void)
{
	std::srand(std::time(0));
	int random_number = std::rand() % 3;
	switch (random_number)
	{
	case 0:
		std::cout << BLUE << "A object instanciates" << RESET << std::endl;
		return (new A);
	case 1:
		std::cout << BLUE << "B object instanciates" << RESET << std::endl;
		return (new B);
	case 2:
		std::cout << BLUE << "C object instanciates" << RESET << std::endl;
		return (new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << GREEN << "A object identified !" << RESET << std::endl;
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << GREEN << "B object identified !" << RESET << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << GREEN << "C object identified !" << RESET << std::endl;
	else
		std::cerr << RED << "Object not identified :(" << RESET << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& obj = dynamic_cast<A&>(p);
		(void)obj;
		std::cout << GREEN << "A object identified !" << RESET << std::endl;
		return ;
	}
	catch(...) {}

	try
	{
		B& obj = dynamic_cast<B&>(p);
		(void)obj;
		std::cout << GREEN << "B object identified !" << RESET << std::endl;
		return ;
	}
	catch(...) {}

	try
	{
		C& obj = dynamic_cast<C&>(p);
		(void)obj;
		std::cout << GREEN << "C object identified !" << RESET << std::endl;
		return ;
	}
	catch(...) {}

	std::cerr << RED << "Object not identified :(" << RESET << std::endl;
}