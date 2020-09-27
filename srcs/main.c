/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:44:04 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 11:43:13 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int			main(int argc, char **argv)
{
	t_dict	*dict;
	if (argc != 3)
	{
		write(1, "DUMBASS!\n", 9);
		return (1);
	}	
	dict = ft_gen_dict(argv[1]);
	ft_sort_dict(&dict);
	printf("Dictionary:\n");
	ft_print_dict(dict);
	printf("Translation:\n");
	ft_translate(argv[2], dict);
	return (0);
}
