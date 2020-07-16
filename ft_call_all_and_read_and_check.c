/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_all_and_read_and_check.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:44:51 by jemendy           #+#    #+#             */
/*   Updated: 2019/08/06 15:38:14 by jemendy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_count_chars_for_memory(char *arg, int count[])
{
	int		fd;
	char	ch;
	int		c;

	c = 0;
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		c++;
		if (c > 545)
		{
			close(fd);
			ft_putstr("error\n");
			ft_bzero(count, 32);
			exit(1);
		}
	}
	close(fd);
	return (c);
}

static int		ft_side_lenght(int num)
{
	int s;
	int temp;
	int result;

	result = 0;
	temp = num;
	while (result == 0)
	{
		s = 1;
		while (s * s < temp)
		{
			s++;
			if (s * s == temp)
				result = s;
			else
				result = 0;
		}
		temp++;
	}
	return (result);
}

static void		ft_check_every_char(char *str, int count[], char ch)
{
	if (count[0] > 128 || count[1] > 4)
		ft_exit(str, count);
	if (ch != '.' && ch != '#' && ch != '\n')
		ft_exit(str, count);
	count[2]++;
	if (ch == '#')
		count[4]++;
	if (ch == '\n')
	{
		if ((++count[0] + 1) % 5 == 0)
		{
			count[3]++;
			if (count[4] != 4)
				ft_exit(str, count);
			count[4] = 0;
		}
	}
	if ((ch == '.' || ch == '#') && count[1] > 3)
		ft_exit(str, count);
	if (ch != '\n' && count[2] % 21 == 0 && count[0] != 0)
		ft_exit(str, count);
	if (ch == '\n')
		count[1] = 0;
	else
		count[1]++;
}

char			*ft_call_all(char *arg, int count[])
{
	int		fd;
	char	ch;
	char	*str;
	int		c;

	c = ft_count_chars_for_memory(arg, count);
	if ((str = (char *)malloc(sizeof(char) * (c + 1))) == NULL)
		ft_exit(str, count);
	fd = open(arg, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		ft_check_every_char(str, count, ch);
		str[count[2] - 1] = ch;
	}
	str[count[2]] = '\0';
	if (count[2] < 20)
		ft_exit(str, count);
	if (count[0] > 129 || count[0] < 4 || (count[0] + 1) % 5 != 0)
		ft_exit(str, count);
	if (((count[0] + 1) != 5 * count[3]) || ((count[2] + 1) != count[3] * 21))
		ft_exit(str, count);
	close(fd);
	count[5] = ft_side_lenght(count[3] * 4);
	return (str);
}
