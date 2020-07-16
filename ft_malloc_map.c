/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:42:39 by jemendy           #+#    #+#             */
/*   Updated: 2019/08/06 14:08:21 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_malloc_map(int i)
{
	int		x;
	int		l;
	char	**map;

	x = 0;
	if ((map = (char**)malloc(sizeof(char*) * i + 1)) == NULL)
		return (NULL);
	while (x < i)
	{
		l = 0;
		if ((map[x] = (char*)malloc(sizeof(char) * i + 1)) == NULL)
		{
			ft_clean_map(map, x);
			return (NULL);
		}
		while (l < i)
			map[x][l++] = '.';
		map[x][i] = '\0';
		x++;
	}
	map[i] = 0;
	return (map);
}
