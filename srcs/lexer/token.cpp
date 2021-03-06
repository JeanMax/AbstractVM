/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 17:59:05 by bmbarga           #+#    #+#             */
/*   Updated: 2017/09/24 14:53:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.hpp"
#include  "error.h"

std::string			conv_tok_type(int type)
{
	std::string		str;

	if (type == UNKNOWN)
		str = "UNKNOWN";
	else if (type == INSTR)
		str = "INSTR";
	else if (type == VALTYPE)
		str = "VALTYPE";
	else if (type == VALUE)
		str = "VALUE";
	else if (type == END)
		str = "END";
	else
		str = "Don't know that type";
	return (str);
}

void			put_tok(t_tok t)
{
	std::cout << "type : [" << conv_tok_type(t.type) << "]"	\
				<< " | val : [" << t.val		\
				<< "]";
}

void			put_tok_list(std::list<t_tok*> l)
{
	std::cout << "\tList : " << std::endl;
	std::cout << "\t{" << std::endl;
	for (std::list<t_tok*>::const_iterator it = l.begin();
			it != l.end(); it++)
	{
		std::cout << "\t\t";
		put_tok(**it);
		std::cout << std::endl;
	}
	std::cout << "\t}" << std::endl << std::endl;
}

void			put_tok_tab(t_tok_tab tab)
{
	std::cout << "Vector : " << std::endl;
	std::cout << "{" << std::endl;
	for (t_tok_tab::const_iterator it = tab.begin();
			it != tab.end(); it++)
	{
		put_tok_list(**it);
	}
	std::cout << "}" << std::endl;
}

void			clear_partial_tab(t_tok_tab *toks,
					t_tok_tab::const_iterator b,
					t_tok_tab::const_iterator e)
{
	std::list<t_tok*>		l;

	for (t_tok_tab::const_iterator it = b; it != e; it++)
	{
		l = **it;
		for (std::list<t_tok*>::const_iterator lt = l.begin();
				lt != l.end(); lt++)
		{
 			delete (*lt);
		}
		delete (*it);
	}
	(void)toks;
	toks->erase(b, e);
}

void			clear_tok_tab(t_tok_tab **toks)
{
	std::list<t_tok*>		l;
	t_tok_tab				*tmp;

	if (!toks || !*toks)
		ERROR("toks");
	tmp = *toks;
	for (t_tok_tab::const_iterator it = tmp->begin(); it != tmp->end(); it++)
	{
		l = **it;
		for (std::list<t_tok*>::const_iterator lt = l.begin();
				lt != l.end(); lt++)
		{
 			delete (*lt);
		}
		delete (*it);
	}
	tmp->erase(tmp->begin(), tmp->end());
	*toks = NULL;
}
