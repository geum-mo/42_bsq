/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:02:45 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 17:06:47 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve(char *argv[], int i)
{
	char		*map_in_str;
	int			size;

	if (i != 1)
		write(1, "\n", 1);
	if ((map_in_str = input_map(argv[i], map_size(argv[i]))) == 0)
	{
		i++;
		write(1, "map error\n", 10);
		return ;
	}
	size = get_row_count(map_in_str);
	g_map = split_map(map_in_str, size);
	if (check_input_map())
	{
		write(1, "map error\n", 10);
		i++;
		return ;
	}
	make_ans();
	free_str(g_map);
	i++;
}

