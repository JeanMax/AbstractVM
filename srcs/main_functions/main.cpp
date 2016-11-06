/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:52:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/23 13:49:52 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vm.class.hpp"

/*
** TODO
**	- FILE READER
**	- LEXER
**	- PARSER
**	- EXEC
**	- OTHER stuff requiered to run the program
*/

int		main(int ac, char **av)
{
	Vm * vm = NULL;
	
	if (!(vm = Vm::getInstance()))
	{
		std::cout << "vm instantiation error" << std::endl;
		return (0);
	}
	if (ac == 1)
	{
		std::cout << "I read from standard input" << std::endl;//_DEBUG_//
		vm->run();
	}
	else
	{
		std::cout << "I read from file" << std::endl;//_DEBUG_//
		vm->run(av[1]);
	}
	return (0);
}
