/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:03:38 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 15:12:26 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

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

// doens't handle 0;
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
//			printf("Dividing\n");
			ft_translate_r(ft_div_tab(tab, dict->digit), dict, 0);
		}
		ft_putstr(dict->letter);
		if (ft_strlen(dict->digit) != 1 || !main)
		{
			write(1, " ", 1);
		}
//		printf("Modding\n");
		ft_translate_r(ft_mod_tab(tab, dict->digit), dict->next, main);
//		printf("Modding end\n");
	}
	free(tab);
	return (0);
}

int		ft_translate(char *str, t_dict *dict)
{
	char	*tab;

	if (ft_check_str(str))
		return (1);
	if (!(tab = ft_strdup(str)))
		return (ft_error(2));
	if (ft_strlen(str) > ft_strlen(dict->digit) + 2)
		return (ft_error(1));
//	ft_add_elem_end(&dict, ft_gen_elem(NULL, NULL, NULL));
	return (ft_translate_r(tab, dict, 1));
}
