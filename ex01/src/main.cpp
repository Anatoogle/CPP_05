/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:29:28 by asemykin          #+#    #+#             */
/*   Updated: 2026/03/12 08:53:43 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2)
        return 0;
    int check = atoi(argv[1]);
    switch(check){
        case 1:
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
            
            break;
        }
        case 2:
        {
            Bureaucrat  tony("Tony", 100);
            Form        a38("A38", 50, 50);

            std::cout << a38 << std::endl;
            tony.signForm(a38);
            std::cout << a38 << std::endl;
            
            break;
        }
        case 3:
        {
            Bureaucrat  tony("Tony", 30);
            Form        a38("A38", 50, 50);

            std::cout << a38 << std::endl;
            tony.signForm(a38);
            std::cout << a38 << std::endl;
            
            break;
        }
        case 4:
        {
            try{
                Bureaucrat  tony("Tony", 0);
                std::cout << "should not get executed" << std::endl;
                Form        a38("A38", 0, 150);
            }
            catch(std::exception &e){
                std::cout << "Exception: " << e.what() << std::endl;
            }

            try{
                Form        a38("A38", 0, 100);
                std::cout << "should not get executed" << std::endl;
                Bureaucrat  tony("Tony", 0);
            }
            catch(std::exception &e){
                std::cout << "Exception: " << e.what() << std::endl;
            }

            try{
                Form        a38("A38", 50, 151);
                std::cout << "should not get executed" << std::endl;
                Bureaucrat  tony("Tony", 0);
            }
            catch(std::exception &e){
                std::cout << "Exception: " << e.what() << std::endl;
            }            

            break;
        }
    }

    return 0;
}
