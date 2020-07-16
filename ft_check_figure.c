/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:41:13 by jemendy           #+#    #+#             */
/*   Updated: 2019/08/06 14:04:04 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_check_touches(char *s, int count[], int i)
{
	if (s[i - 1] == '#')
		count[6]++;
	if (s[i - 5] == '#')
		count[6]++;
	if (s[i + 1] == '#')
		count[6]++;
	if (s[i + 5] == '#')
		count[6]++;
}

void		ft_check_figure(char *s, int count[], int i, int x)
{
	while (s[i] != '\0')
	{
		if (i % 21 == 0)
		{
			x = 0;
			count[4] = 0;
			count[6] = 0;
		}
		if (s[i] == '#')
		{
			if (s[i - 1] != '#' && s[i + 1] != '#' && (s[i - 5] != '#'
				|| (s[i - 5] == '#' && x - 5 < 0)) && (s[i + 5] != '#'
				|| (s[i + 5] == '#' && x + 5 > 19)))
				ft_exit(s, count);
			ft_check_touches(s, count, i);
			count[4]++;
			if (count[4] == 4 && count[6] < 6)
				ft_exit(s, count);
		}
		i++;
		x++;
	}
}
