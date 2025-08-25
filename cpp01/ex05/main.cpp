/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavicent <pavicent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:20:50 by pavicent          #+#    #+#             */
/*   Updated: 2025/08/25 18:20:51 by pavicent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl harl;

	std::cout << "\n--- Testing DEBUG ---" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\n--- Testing INFO ---" << std::endl;
	harl.complain("INFO");

	std::cout << "\n--- Testing WARNING ---" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n--- Testing ERROR ---" << std::endl;
	harl.complain("ERROR");

	std::cout << "\n--- Testing UNKNOWN ---" << std::endl;
	harl.complain("RANDOM");

	return (0);
}
