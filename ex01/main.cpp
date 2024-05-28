/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:16:51 by melanieyane       #+#    #+#             */
/*   Updated: 2024/05/28 11:29:12 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Create a Data object and initialize its members
    Data data;
    data.number = 42;
    data.text = "Hello, world!";

    // Display the original Data object
	std::cout << "\033[34m" << "Original Data:" << "\033[0m" << std::endl;
    std::cout << "Number: " << data.number << std::endl;
    std::cout << "Text: " << data.text << std::endl;

    // Serialize the address of the Data object
	std::cout << "***" << std::endl;
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout <<"\033[34m" << "Serialized Data (uintptr_t): " << "\033[0m" << serialized << std::endl;

    // Deserialize the uintptr_t back to a Data pointer
    Data* deserialized = Serializer::deserialize(serialized);

    // Display the deserialized Data object
	std::cout << "***" << std::endl;
    std::cout << "\033[34m" << "Deserialized Data:" << "\033[0m" << std::endl;
    std::cout << "Number: " << deserialized->number << std::endl;
    std::cout << "Text: " << deserialized->text << std::endl;

    // Check that the original pointer and the deserialized pointer are equal
	std::cout << "***" << std::endl;
	std::cout << "Original pointer address: " << &data << std::endl;
    std::cout << "Deserialized pointer address: " << deserialized << std::endl;
    if (deserialized == &data) {
        std::cout << "\033[32m" << "Success: The deserialized pointer is equal to the original pointer." <<  "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m" << "Error: The deserialized pointer is not equal to the original pointer." << "\033[0m" << std::endl;
    }

    return 0;
}
