/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:55:41 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/28 14:00:32 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <string>
#include <iostream>
#include <ctime>

Base	*generate(void){
	std::srand(static_cast<unsigned int>(std::time(0)));
	int random = std::rand() % 3;
	
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void	identify(Base *p){
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p){
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast&){}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast&){}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast&){}
}

int main(void){
	Base* ptr = generate();
    
    // Identify using pointer
    std::cout << "Identifying using pointer: ";
    identify(ptr);
    
    // Identify using reference
    std::cout << "Identifying using reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}