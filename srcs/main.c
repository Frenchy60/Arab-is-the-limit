/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:44:04 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 16:47:18 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

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
}

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
	ft_sort_dict(&dict);
	if (ft_tabcmp(argv[argc - 1], "0"))
		ft_translate(argv[argc - 1], dict);
	else
		ft_print_zero(dict);
	return (0);
}
