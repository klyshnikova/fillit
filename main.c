/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaisha <vaisha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:45:14 by jemendy           #+#    #+#             */
/*   Updated: 2019/08/06 12:35:20 by vaisha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print_map(char **map, int m)
{
	while (map != NULL && *map != NULL && map[m])
	{
		ft_putstr(map[m++]);
		ft_putchar('\n');
	}
}

int				main(int argc, char **argv)
{
	int			count[7];
	char		*str;
	t_tetr_list	*l;
	char		**map;

	l = NULL;
	map = NULL;
	ft_bzero(count, 32);
	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(1);
	}
	str = ft_call_all(argv[1], count);
	ft_check_figure(str, count, 0, 0);
	ft_create_list_and_search_coordinate(str, &l, 0, 0);
	if (l == NULL)
		ft_exit(str, count);
	if ((map = ft_result(&l, count, 0)) == NULL)
		ft_putstr("error\n");
	ft_print_map(map, 0);
	ft_clean_all_for_finish(count, map, &l, str);
}
