/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 03:23:00 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/02 04:30:33 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat a;
    Bureaucrat b(1);
    Bureaucrat c("#C",100);
    Bureaucrat d("#D",125);
    Bureaucrat e(c);
    
    std::cout << "" << std::endl;
    
    b = d;
    
    a.decrementGrade(5);
    c.incrementGrade(5);
    
    std::cout << "" << std::endl;
    
    try{
        a.decrementGrade(200);
    }
    catch(std::exception &e){
        std::cout << "Exception: " << a.getName() << " : " << e.what() << std::endl;
    }

    try{
        c.incrementGrade(300);
    }
    catch(std::exception &e){
        std::cout << "Exception: " << c.getName() << " : " << e.what() << std::endl;
    }

    std::cout << "" << std::endl;
    return 0;
}
