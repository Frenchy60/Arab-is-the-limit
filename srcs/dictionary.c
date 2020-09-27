/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:45:42 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 17:23:25 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
** Allocates memory for a new element of the struct and instanciate it with the
** values passed as parameters
*/

t_dict		*ft_gen_elem(char *letter, char *digit, t_dict *next)
{
	t_dict	*dict;

	if (!(dict = malloc(sizeof(t_dict))))
		return (NULL);
	dict->letter = letter;
	dict->digit = digit;
	dict->next = next;
	return (dict);
}

/*
** Removes all the extra white spaces before or after the digits
*/

char		*ft_fixdigit(char *str)
{
	int		i;
	int		o;
	char	*newstr;

	i = 0;
	o = 0;
	if (!str)
		return (NULL);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i + o] == ' ')
		o++;
	if (i + o != ft_strlen(str))
	{
		free(str);
		return (ft_strdup("\0"));
	}
	if (!o)
		return (str);
	newstr = ft_strndup(str, i);
	free(str);
	return (newstr);
}

/*
** Remove all the extra white spaces before or after the letters
*/

char		*ft_fixletter(char *str)
{
	int		i;
	int		o;
	char	*newstr;

	i = 0;
	o = 0;
	if (!str)
		return (NULL);
	while (str[o] == ' ')
		o++;
	while (str[o + i] >= 33 && str[o + i] <= 126)
		i++;
	if (i + o != ft_strlen(str))
	{
		free(str);
		return (ft_strdup("\0"));
	}
	newstr = ft_strdup(&str[o]);
	free(str);
	return (newstr);
}

/*
** Fetch the text from the file untill @end and returns it
*/

char		*ft_fetch_text(int fd, char end)
{
	char	buff[100];
	int		i;

	i = 0;
	if (!(read(fd, &buff[i], 1)))
		return (NULL);
	while (buff[i] && buff[i] != end && i < 99)
		if (!(read(fd, &buff[++i], 1)))
		{
			buff[i] = '\0';
			i = 100;
		}
	if (i != 100)
		buff[i] = '\0';
	return (ft_strdup(buff));
}

/*
** Open the file of the dictionnary, prints an error if the file is not readable
** Fetch the differents part of the text we need then implement the struct
** Adds them to the struct and checks if it's valid
*/

t_dict		*ft_gen_dict(char *file)
{
	int		fd;
	t_dict	*dict;
	char	*digit;
	char	*letter;
	int		flag;

	if (1 >= (fd = open(file, O_RDWR)))
		return ((ft_error(0)) ? NULL : NULL);
	flag = 1;
	dict = NULL;
	while (flag)
	{
		digit = ft_fetch_text(fd, ':');
		letter = ft_fetch_text(fd, '\n');
		ft_add_elem_end(&dict, ft_gen_elem(
					ft_fixletter(letter), ft_fixdigit(digit), NULL));
		if (-1 == (flag = ft_check_last_elem(&dict)))
		{
			ft_free_dict(dict);
			ft_error(0);
			return (NULL);
		}
	}
	return (dict);
}
