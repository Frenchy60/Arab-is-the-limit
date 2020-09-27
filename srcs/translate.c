/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:03:38 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 17:58:52 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
** Verify if the string passed as parameter only contains numeric char
*/

int		ft_check_str(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (ft_error(1));
	if (i < 1)
		return (ft_error(1));
	return (0);
}

/*
** Double recursively translate the number @main with its written syntax
*/

int		ft_translate_r(char *tab, t_dict *dict, int main)
{
	t_dict	*tmp;

	tmp = dict;
	ft_fix_tab(tab);
	while (ft_tabcmp(tab, dict->digit) < 0 && (dict->next))
		dict = dict->next;
	if (dict->next && ft_tabcmp(tab, "0"))
	{
		if (ft_strlen(tab) > 2)
		{
			ft_translate_r(ft_div_tab(tab, dict->digit), dict, 0);
		}
		ft_putstr(dict->letter);
		if (ft_strlen(dict->digit) != 1 || !main)
		{
			write(1, " ", 1);
		}
		ft_translate_r(ft_mod_tab(tab, dict->digit), dict->next, main);
	}
	free(tab);
	return (0);
}

/*
** Does a few initals checks to verify that all is set properly then calls the
** recursive function ft_translate_r()
*/

int		ft_translate(char *str, t_dict *dict)
{
	char	*tab;

	if (ft_check_str(str))
		return (1);
	if (!(tab = ft_strdup(str)))
		return (ft_error(2));
	if (ft_strlen(str) > ft_strlen(dict->digit) + 2)
		return (ft_error(1));
	ft_translate_r(tab, dict, 1);
	write(1, "\n", 1);
	return (0);
}
