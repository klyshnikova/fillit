/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:17:55 by vaisha            #+#    #+#             */
/*   Updated: 2019/04/22 17:06:10 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	int		i;
	char	*d;
	char	*s;

	d = (char *)destination;
	s = (char *)source;
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		n--;
		i++;
	}
	return (d);
}
