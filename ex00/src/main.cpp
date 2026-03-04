/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 03:23:00 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/02 12:24:10 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    Bureaucrat a;
    Bureaucrat b(1);
    Bureaucrat c("#C",1);
    Bureaucrat d("#D");
    Bureaucrat e(c);
    
    std::cout << "" << std::endl;
    
    b = d;
    
    b.decrementGrade();
    e.incrementGrade();
    
    std::cout << "" << std::endl;
    
    try{
        Bureaucrat f("#F",0);
        Bureaucrat g("#G",155);
    }
    catch(std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try{
        Bureaucrat h("#H",200);
        Bureaucrat i("#I",0);
    }
    catch(std::exception &e){
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try{
        a.incrementGrade();
    }
    catch(std::exception &e){
        std::cout << "Exception: " << a.getName() << " : " << e.what() << std::endl;
    }
    try{
        c.decrementGrade();
    }
    catch(std::exception &e){
        std::cout << "Exception: " << c.getName() << " : " << e.what() << std::endl;
    }

    std::cout << "" << std::endl;
    return 0;
}
