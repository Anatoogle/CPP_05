/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:29:28 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/03 23:14:03 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int main()
{
    Form a;
    Form b("A38", 1, 1);
    Form c("A40", 50, 50);
    Form d("A50", 150, 150);
    Form e;
    Form f(b);

    Bureaucrat b1("B1", 1);
    Bureaucrat b2("B2", 150);
    
    std::cout << std::endl;
    
    e = b;

    std::cout << std::endl;
    
    return 0;
}
