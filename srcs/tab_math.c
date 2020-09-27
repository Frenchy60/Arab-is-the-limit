/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 07:46:11 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 14:02:25 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
** This does: src = src + add * 10^offset;
*/
void	ft_tab_add(char *src, char *add, int offset)
{
	int		i;
	int		j;
	int		flag;

	i = ft_strlen(src) - 1 - offset;
	j = ft_strlen(add) - 1;
	flag = 0;
	while (j >= 0 && i >= 0)
	{
		src[i] += add[j] + flag - '0';
		flag = 0;
		if (src[i] > '9')
		{
			flag = 1;
			src[i] -= 10;
		}
		i--;
		j--;
	}
	while (flag-- && i >= 0)
	{
		src[i] += 1;
		if (src[i--] == '9' + 1)
			src[i + 1] -= 10 + flag++;
	}
}

/*
** This does: src = src - sub * 10^offset;
*/

void	ft_tab_sub(char *src, char *sub, int offset)
{
	int		i;
	int		j;
	int		flag;

	i = ft_strlen(src) - 1 - offset;
	j = ft_strlen(sub) - 1;
	flag = 0;
	while (j >= 0 && i >= 0)
	{
		src[i] = src[i] - sub[j] + '0' + flag;
		flag = 0;
		if (src[i] < '0')
		{
			flag = -1;
			src[i] += 10;
		}
		i--;
		j--;
	}
	while (flag++ && i >= 0)
	{
		src[i] -= 1;
		if (src[i--] == '0' - 1)
			src[i + 1] += 10 + flag--;
	}
}

/*
** This does: ntab = src * mul
*/

char	*ft_mul_tab(char *src, char *mul)
{
	char	*ntab;
	int		i;
	int		o;

	if (!(ntab = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(mul) + 1))))
		return (NULL);
	i = -1;
	while (++i <= ft_strlen(src) + ft_strlen(mul))
		ntab[i] = '0';
	ntab[i] = '\0';
	i = ft_strlen(mul);
	while (--i >= 0)
	{
		o = -1;
		while (++o + '0' < mul[i])
			ft_tab_add(ntab, src, i - ft_strlen(mul) + 1);
	}
	return (ntab);
}

/*
** Checks which number is bigger.
** returns >0 if tab1 is bigger
** returns <0 if tab2 is bigger
** returns  0 if tab1 = tab2
*/

int		ft_tabcmp(char *tab1, char *tab2)
{
	int		i;

	i = 0;
	while (ft_strlen(tab1) != ft_strlen(tab2))
	{
		if (ft_strlen(tab1) > ft_strlen(tab2))
		{
			if (tab1[0] == '0')
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
** This does: ntab = src / div
NOT COMPLETED
*/

char	*ft_div_tab(char *src, char *div)
{
	char	*ntab;
	char	*tmp;
	int		i;

	ft_fix_tab(div);
	tmp = ft_strdup(src);
	if (!(ntab = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = -1;
	while (++i <= ft_strlen(src))
		ntab[i] = '0';
	ntab[i] = '\0';
	i = -1;
	while (++i + ft_strlen(div) <= ft_strlen(src)) //= needed???
	{
		ntab[i] = '0';
		while (ft_tabcmp_e(tmp, div, ft_strlen(src) - ft_strlen(div) - i) >= 0)
		{		//Shouldn't it be >= 0??
			ntab[i]++;
//			printf("Startsubing\n");
			ft_tab_sub(tmp, div, ft_strlen(src) - ft_strlen(div) - i);
//			printf("Endsubbing: %s$%s$\n", tmp, ntab);
		}
	}
	ntab[i] = '\0';
	free (tmp);
	return (ntab);
}


