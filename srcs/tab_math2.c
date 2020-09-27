/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:49:58 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 16:46:54 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_fix_tab(char *tab)
{
	int		i;

	while (tab[0] == '0' && ft_strlen(tab) > 1)
	{
		i = -1;
		while (tab[++i + 1])
		{
			tab[i] = tab[i + 1];
		}
		tab[i] = '\0';
	}
}

/*
** This does ft_tabcmp(tab1, tab2 * 10^offset);
*/

int		ft_tabcmp_e(char *tab1, char *tab2, int offset)
{
	int		i;

	i = 0;
	while (ft_strlen(tab1) != ft_strlen(tab2) + offset && ft_strlen(tab2))
	{
		if (ft_strlen(tab1) > ft_strlen(tab2) + offset)
		{
			if (tab1[1] == '0')
				tab1 += 1;
			else
				return (tab1[0] - '0');
		}
		else
		{
			if (tab2[0] == '0')
				tab2 += 1;
			else
				return ('0' - tab2[0]);
		}
	}
	while (tab1[i] && tab1[i] == tab2[i])
		i++;
	return (tab1[i] - tab2[i]);
}

/*
** This does newtab = tab % mod
*/

char	*ft_mod_tab(char *src, char *mod)
{
	char	*ntab;
	int		i;

	ft_fix_tab(mod);
	ntab = ft_strdup(src);
	i = -1;
	while (++i + ft_strlen(mod) <= ft_strlen(ntab))
	{
		while (ft_tabcmp_e(ntab, mod, ft_strlen(src) - ft_strlen(mod) - i) >= 0)
		{
			ft_tab_sub(ntab, mod, ft_strlen(src) - ft_strlen(mod) - i);
		}
	}
	return (ntab);
}
