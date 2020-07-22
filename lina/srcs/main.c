/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:00:17 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 22:18:25 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	handle_single_arg(void)
{
	char	*map_in_str;
	int		size;

	map_in_str = get_stdin();
	size = get_row_count(map_in_str);
	g_map = split_map(map_in_str, size);
	if (check_input_map())
	{
		write(1, "map error\n", 10);
		return ;
	}
	process();
	free_str(g_map);
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc == 1)
	{
		handle_single_arg();
		return (0);
	}
	while (i < argc)
	{
		solve(argv, i);
		i++;
	}
	return (0);
}
