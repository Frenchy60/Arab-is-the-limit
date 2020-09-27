/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:11:52 by agraton           #+#    #+#             */
/*   Updated: 2020/09/27 16:50:56 by agraton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_dict
{
	struct s_dict	*next;
	char			*letter;
	char			*digit;
}					t_dict;

int					ft_strlen(char *str);
void				ft_putstr(char *str);
void				ft_putchar(char c);
int					ft_strcmp(char *s1, char *s2);
int					*ft_dup_tab(int *tab, int length);
int					ft_error(int i);
t_dict				*ft_gen_elem(char *letter, char *digit, t_dict *next);
t_dict				*ft_gen_dict(char *file);
void				ft_add_elem_end(t_dict **begin, t_dict *dict);
int					ft_check_last_elem(t_dict **begin);
void				ft_free_dict(t_dict *dict);
char				*ft_strdup(char *str);
char				*ft_strndup(char *str, int n);
int					ft_dict_size(t_dict *dict);
t_dict				*ft_remove_last_dict_elem(t_dict *dict);
void				ft_tab_sub(char *src, char *sub, int offset);
void				ft_tab_add(char *src, char *add, int offset);
int					ft_tabcmp(char *tab1, char *tab2);
int					ft_tabcmp_e(char *tab1, char *tab2, int offset);
char				*ft_mul_tab(char *src, char *mul);
char				*ft_div_tab(char *src, char *div);
char				*ft_mod_tab(char *src, char *mod);
void				ft_sort_dict(t_dict **start);
int					ft_translate(char *str, t_dict *dict);
int					ft_tab_cmp_e(char *tab1, char *tab2, int offset);
void				ft_fix_tab(char *tab);

#endif
