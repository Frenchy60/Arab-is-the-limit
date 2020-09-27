/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baselib2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:36:51 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 11:48:14 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char		*ft_strndup(char *str, int n)
{
	char	*newstr;
	int		i;

	i = -1;
	if (!(newstr = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (++i < n)
		newstr[i] = str[i];
	newstr[i] = '\0';
	return (newstr);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
