/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:51:52 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 17:23:16 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
** Prints the error according to the parameter passed
*/

int			ft_error(int i)
{
	if (i == 0)
		write(1, "Dict Error\n", 11);
	if (i == 1)
		write(1, "Error\n", 6);
	if (i == 2)
		write(1, "Malloc: Ran out of space\n", 25);
	return (1);
}
