/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:31:01 by pavicent          #+#    #+#             */
/*   Updated: 2026/01/20 09:31:03 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Data data;
    data.number = 42;
    data.text = "Hello 42";

    std::cout << "Original Data address: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized address: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "✅ SUCCESS: pointers match!" << std::endl;
    else
        std::cout << "❌ ERROR: pointers do not match!" << std::endl;

    std::cout << "Data content via deserialized pointer:" << std::endl;
    std::cout << "number = " << ptr->number << std::endl;
    std::cout << "text   = " << ptr->text << std::endl;

    return (0);
}
