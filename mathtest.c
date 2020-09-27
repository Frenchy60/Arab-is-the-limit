/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:39:12 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 14:05:21 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_div_tab(char *src, char *div);
void	ft_tab_sub(char *src, char *sub, int offset);
char	*ft_mod_tab(char *src, char *mod);


int			main(void)
{
	char *ans;
	char *tab = malloc(sizeof(char)*5);
	tab[0] = '0';
	tab[1] = '1';
	tab[2] = '4';
	tab[3] = '6';
	tab[4] = '\0';
	char *tab2 = malloc(sizeof(char)*5);
	tab2[0] = '0';
	tab2[1] = '0';
	tab2[2] = '1';
	tab2[3] = '0';
	tab2[4] = '\0';
	ans = ft_mod_tab(tab, tab2);
//	ft_tab_sub(tab, tab2, 1);
	printf("%s\n", ans);
}
