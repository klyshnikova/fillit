/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:55:17 by vaisha            #+#    #+#             */
/*   Updated: 2019/08/05 17:01:48 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;

	a = NULL;
	if ((!s1) && (!s2))
		return (NULL);
	if ((!s1) && (s2))
	{
		if (!(a = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(a, s2);
	}
	else if ((s1) && (!s2))
	{
		if (!(a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
			return (NULL);
		ft_strcpy(a, s1);
	}
	if (!(a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1))))
		return (NULL);
	ft_strcpy(a, s1);
	ft_strcat(a, s2);
	return (a);
}
