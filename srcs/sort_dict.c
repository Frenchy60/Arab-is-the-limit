/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 07:28:10 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 17:49:57 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
** Swap the current struct with the next one, if they are not in descending
** order (by some kind of black magic)
*/

void		ft_swap_if_dict(t_dict **start)
{
	t_dict	*tmp;

	if ((ft_tabcmp((*start)->digit, (*start)->next->digit)) < 0)
	{
		tmp = (*start)->next->next;
		(*start)->next->next = *start;
		(*start) = (*start)->next;
		(*start)->next->next = tmp;
	}
}

/*
** Sorts the dictionary (represented by a chain of struct) by descending order
*/

void		ft_sort_dict(t_dict **start)
{
	t_dict	*tmp;
	int		i;

	ft_remove_last_dict_elem(*start);
	i = -1;
	while (++i < ft_dict_size(*start))
	{
		ft_swap_if_dict(start);
		tmp = *start;
		while (tmp->next->next)
		{
			ft_swap_if_dict(&(tmp->next));
			tmp = tmp->next;
		}
	}
}
