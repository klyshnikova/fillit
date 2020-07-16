/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:53:11 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/23 16:03:23 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	long	a;

	i = 1;
	a = n;
	if (n < 0)
		i++;
	while ((n = n / 10) != 0)
		i++;
	if ((res = ft_strnew(i)))
	{
		(a == 0) ? (res[0] = '0') : 0;
		if (a < 0)
		{
			res[0] = '-';
			a = a * (-1);
		}
		while (a != 0)
		{
			res[--i] = a % 10 + '0';
			a = a / 10;
		}
	}
	return (res);
}
