/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baselib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:35:35 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 06:14:17 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

char		*ft_strdup(char *str)
{
	int		size;
	char	*newstr;
	int		i;

	i = -1;
	size = ft_strlen(str);
	if (!(newstr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (str[++i])
		newstr[i] = str[i];
	newstr[i] = '\0';
	return (newstr);
}

int			*ft_dup_tab(int *tab, int length)
{
	int		*newtab;
	int		i;

	if (!(newtab = malloc(sizeof(int) * (length + 1))))
		return (NULL);
	i = -1;
	while (++i < length)
		newtab[i] = tab[i];
	newtab[i] = -1;
	return (newtab);
}
