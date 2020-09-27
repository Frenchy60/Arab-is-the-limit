/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:44:04 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 17:58:55 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
** Fetch the last line of the dict to verify it is zero and then prints it
*/

void		ft_print_zero(t_dict *dict)
{
	while (dict->next)
		dict = dict->next;
	if (ft_tabcmp(dict->digit, "0"))
	{
		ft_error(1);
		return ;
	}
	ft_putstr(dict->letter);
	write(1, "\n", 1);
}

/*
** Starts by initiating a struct t_dict
** If we don't have the proper amount of arguments, we write an error message
** on the stander output
** If the main is called with 2 arguments, we use the dictionnary Basedict .txt
** If called with 3 arguments, we use the dictionnary passed in the first param
** We sort the dictionnary by descending order
** If the number to translate is different than 0, we translate it normally
** Else, we call a function that will get the last line of the dictionarry (0)
** After translating, we free all the memory allocated by malloc for our dict
*/

int			main(int argc, char **argv)
{
	t_dict	*dict;

	if (argc != 2 && argc != 3)
	{
		return (ft_error(2));
	}
	if (argc == 2)
		dict = ft_gen_dict("Dictionaries/Basedict.txt");
	if (argc == 3)
		dict = ft_gen_dict(argv[1]);
	if (dict)
		ft_sort_dict(&dict);
	if (ft_tabcmp(argv[argc - 1], "0") && dict)
		ft_translate(argv[argc - 1], dict);
	else if (dict)
		ft_print_zero(dict);
	ft_free_dict(dict);
	return (0);
}
