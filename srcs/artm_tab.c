/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artm_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:33:58 by adesmet           #+#    #+#             */
/*   Updated: 2020/09/27 07:40:44 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_table(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}
// Doesn't work for tabs of different sizes?
int		ft_tab_cmp(char *tab, char *tab2)
{
	int i;
	int j;

	i = 0;
	while (tab[i] == '0')
	{
		i++;
	}
	j = 0;
	while (tab2[j] == '0')
	{
		j++;
	}
	while (tab[i] && tab2[j])
	{
		if (tab[i] > tab2[j])
			return (1);
		if (tab[i] < tab2[j])
			return (-1);
		i++;
		j++;
	}
	return (0);
}

void	ft_sub(char *tab, char *tab2)
{
	int i;
	int j;
	int flag;

	i = ft_count_table(tab) - 1;
	j = ft_count_table(tab2) - 1;
	flag = 0;
	while (i >= 0 && j >= 0)
	{
		tab[i] = tab[i] - tab2[j] + flag;
		flag = 0;
		if (tab[i] < 0)
		{
			tab[i] += 10;
			flag = -1;
		}
		tab[i] += '0';
		i--;
		j--;
	}
	if (flag != 0)			//What if tab[i] == 0 (and tab[i - 1] = 1 for example)
		tab[i] += flag;
}

void	ft_sum(char *tab, char *tab2)
{
	int i;
	int j;
	int flag;

	i = ft_count_table(tab) - 1;
	j = ft_count_table(tab2) - 1;
	flag = 0;
	while (i >= 0 && j >= 0)
	{
		tab[i] = tab[i] + tab2[j] + flag - (2 * '0');
		flag = 0;
		if (tab[i] > 10)
		{
			tab[i] -= 10;
			flag = 1;
		}
		tab[i] += '0';
		i--;
		j--;
	}
	if (flag != 0)		//What if tab[i] == 9?
		tab[i] += flag;
}
// What if mult > INT_MAX
void	ft_mult(char *tab, char *tab2, int base)
{
	int i;
	int mult;

	i = 0;
	mult = 0;
	while (tab2[i])
	{
		mult = (mult * base) + tab2[i] - '0';
		i++;
	}
	while (mult > 1)
	{
		ft_sum(tab, tab2, base);
		mult--;
	}
}
// What if mod > INT_MAX
void	ft_mod(char *tab, char *tab2, int base)
{
	int i;
	int mod;

	i = 0;
	mod = 0;
	while (tab2[i])
	{
		mod = (mod * base) + tab2[i] - '0';
		i++;
	}
	while (mod > 0)
	{
		ft_sub(tab, tab2, base);
		mod--;
	}
}
