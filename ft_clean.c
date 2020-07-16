/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:42:20 by jemendy           #+#    #+#             */
/*   Updated: 2019/08/06 14:20:22 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_map(char **map, int size)
{
	while (size >= 0)
		free(map[size--]);
	free(map);
	map = NULL;
}

void	ft_clean_all_for_finish(int count[], char **map, t_tetr_list **list,
		char *s)
{
	if (map != NULL && *map != NULL)
		ft_clean_map(map, count[5] - 1);
	ft_delete_list(list);
	free(s);
	ft_bzero(count, 32);
}

void	ft_delete_list(t_tetr_list **alst)
{
	t_tetr_list	*list;
	t_tetr_list	*fwd;

	list = *alst;
	while (list)
	{
		fwd = list->next;
		ft_bzero(list->x, 16);
		ft_bzero(list->y, 16);
		list->c = '\0';
		free(list);
		list = fwd;
	}
	*alst = NULL;
}

void	ft_exit(char *str, int count[])
{
	ft_putstr("error\n");
	ft_bzero(count, 32);
	free(str);
	exit(1);
}
