/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:10:34 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 17:55:36 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
** Adds the structure element @dict at the end of the chain of structure @begin
*/

void		ft_add_elem_end(t_dict **begin, t_dict *dict)
{
	if (!*begin)
	{
		*begin = dict;
		return ;
	}
	if (!(*begin)->next)
	{
		(*begin)->next = dict;
		return ;
	}
	ft_add_elem_end(&((*begin)->next), dict);
}

/*
** Verify the validity of the variables of the last element of the chain of
** structure @begin, returns :
** -1 if either or both are incorrect
** 1  if they are both valid
** 0  if they are both null, which signify the end of file
*/

int			ft_check_last_elem(t_dict **begin)
{
	if ((*begin)->next)
		return (ft_check_last_elem(&((*begin)->next)));
	if ((*begin)->letter)
		if (!(*begin)->letter[0])
			return (-1);
	if ((*begin)->digit)
		if (!(*begin)->digit[0])
			return (-1);
	if ((*begin)->letter && (*begin)->digit)
		return (1);
	if (!((*begin)->letter) && !((*begin)->digit))
		return (0);
	return (-1);
}

/*
** Free the memory allocated by malloc for the dictionary
*/

void		ft_free_dict(t_dict *dict)
{
	if (!dict)
		return ;
	ft_free_dict(dict->next);
	if (dict->letter)
		free(dict->letter);
	if (dict->digit)
		free(dict->digit);
	free(dict);
}

/*
** Recursively check the size of the Dick
*/

int			ft_dict_size(t_dict *dict)
{
	if (!dict)
		return (0);
	return (1 + ft_dict_size(dict->next));
}

/*
** Removes the last element of the struct @dict
*/

t_dict		*ft_remove_last_dict_elem(t_dict *dict)
{
	t_dict	*tmp;

	if (ft_dict_size(dict) < 41)
	{
		ft_free_dict(dict);
		return (NULL);
	}
	tmp = dict;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_free_dict(tmp->next);
	tmp->next = NULL;
	return (dict);
}
