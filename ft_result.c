/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemendy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:08:02 by jemendy           #+#    #+#             */
/*   Updated: 2019/08/06 16:08:51 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_erase_map(int size, t_tetr_list *list, char **map)
{
	int		x;
	int		l;

	x = 0;
	while (x < size)
	{
		l = 0;
		while (l < size)
		{
			if (map[x][l] == list->c)
				map[x][l] = '.';
			l++;
		}
		x++;
	}
}

static int			ft_find_size(char **map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
		i++;
	return (i);
}

static int			ft_check_and_arrangement(int x1, int y1, t_tetr_list *l,
					char **map)
{
	int				size;

	size = ft_find_size(map);
	if ((l->y)[0] + y1 >= size || (l->y)[1] + y1 >= size ||
		(l->y)[2] + y1 >= size || (l->y)[3] + y1 >= size ||
		(l->x)[0] + x1 >= size || (l->x)[1] + x1 >= size ||
		(l->x)[2] + x1 >= size || (l->x)[3] + x1 >= size)
		return (0);
	if (map[y1 + (l->y)[0]][x1 + (l->x)[0]] == '.' &&
		map[y1 + (l->y)[1]][x1 + (l->x)[1]] == '.' &&
		map[y1 + (l->y)[2]][x1 + (l->x)[2]] == '.' &&
		map[y1 + (l->y)[3]][x1 + (l->x)[3]] == '.')
	{
		map[y1 + (l->y)[0]][x1 + (l->x)[0]] = l->c;
		map[y1 + (l->y)[1]][x1 + (l->x)[1]] = l->c;
		map[y1 + (l->y)[2]][x1 + (l->x)[2]] = l->c;
		map[y1 + (l->y)[3]][x1 + (l->x)[3]] = l->c;
		return (1);
	}
	else
		return (0);
}

static int			ft_place_figure(int size, t_tetr_list *list, char **map)
{
	int x;
	int y;

	y = 0;
	if (list == NULL)
		return (1);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (ft_check_and_arrangement(x, y, list, map))
			{
				if (ft_place_figure(size, list->next, map))
					return (1);
				else
					ft_erase_map(size, list, map);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char				**ft_result(t_tetr_list **list, int count[], int a)
{
	char		**map;
	int			res;
	int			size;

	size = a + count[5];
	res = 0;
	while (res != 1 && size < 15)
	{
		if (size > count[5])
			ft_clean_map(map, size - 1);
		if ((map = ft_malloc_map(size)) == NULL)
			return (NULL);
		res = ft_place_figure(size, *list, map);
		size++;
	}
	count[5] = size;
	return (map);
}
