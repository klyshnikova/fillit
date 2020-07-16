/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:41:02 by jemendy           #+#    #+#             */
/*   Updated: 2019/08/06 14:13:47 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_tetr_list
{
	int					x[4];
	int					y[4];
	char				c;
	struct s_tetr_list	*next;
}				t_tetr_list;

char			*ft_call_all(char *arg, int p[]);
void			ft_check_figure(char *s, int p[], int i, int x);
void			ft_exit(char *str, int p[]);
void			ft_create_list_and_search_coordinate(char *s, t_tetr_list **l,
				int i, int a);
void			ft_clean_all_for_finish(int p[], char **arr, t_tetr_list **list,
				char *s);
void			ft_clean_map(char **map, int size);
void			ft_delete_list(t_tetr_list **alst);
char			**ft_result(t_tetr_list **list, int p[], int a);
char			**ft_malloc_map(int i);

#endif
