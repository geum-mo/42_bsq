/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:00:05 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 21:57:13 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void			fill_map(char **map)
{
	int i;
	int j;
	int x_index;
	int y_index;

	x_index = g_meta.x_index;
	y_index = g_meta.y_index;
	i = 0;
	while (i < g_meta.max) // index부터 x, y축으로 -1씩 총 max만큼 이동하면서 obstacle은 건너뛰고 full값을 채움
	{
		j = 0;
		while (j < g_meta.max)
		{
			if (map[x_index - i][y_index - j] == g_meta.obstacle)
				break ;
			else
				map[x_index - i][y_index - j] = g_meta.full;
			j++;
		}
		i++;
	}
}

void			get_xy_index(void)
{
	int i;
	int j;
	int max;

	max = g_meta.max;
	i = 0;
	while (i < g_meta.x_size)
	{
		j = 0;
		while (j < g_meta.y_size)
		{
			if (g_arr[i][j] == g_meta.max) // 값이 max인 index를 찾아 그 index를 g_meta에 저장
			{
				g_meta.x_index = i;
				g_meta.y_index = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void			malloc_g_arr(void)
{
	int i;

	i = 0;
	if (!(g_arr = (int **)malloc(sizeof(int *) * g_meta.x_size)))
		return ;
	while (i < g_meta.x_size)
	{
		if (!(g_arr[i] = (int *)malloc(sizeof(int) * g_meta.y_size)))
			return ;
		i++;
	}
}

void			make_g_arr(char **map)
{
	int i;
	int j;

	i = 0;
	while (i < g_meta.x_size)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == g_meta.obstacle)
				g_arr[i][j] = 0; // obstacle이면 0
			else if (i == 0 || j == 0)
				g_arr[i][j] = 1; // obstable이 아닌, 첫째 row 또는 첫째 column 있는 값들은 1?
			else
			{
				g_arr[i][j] =
					min(g_arr[i - 1][j],
							min(g_arr[i][j - 1], g_arr[i - 1][j - 1])) + 1; // 위의 경우 들이 모두 아닌 경우, 해당 값을 XX와 XX의 최소값의 최소값?
				if (g_meta.max < g_arr[i][j])
					g_meta.max = g_arr[i][j];
			}
			j++;
		}
		i++;
	}
}

void			process(void)
{
	char	**new_map;
	int		i;

	i = 0;
	if (!(new_map = (char **)malloc(sizeof(char *) * (g_meta.x_size + 1))))
		return ;
	new_map[g_meta.x_size] = 0;
	while (i < g_meta.x_size)
	{
		if (!(new_map[i] = ft_strndup(g_map[i + 1], g_meta.y_size))) // new_map을 만들어 g_map을 그대로 복사?
			return ;
		i++;
	}
	malloc_g_arr(); //g_map과 동일한 양의 메모리를 g_arr에 할당
	make_g_arr(new_map); // g_arr은 무슨 목적?
	get_xy_index();
	fill_map(new_map);
	print_arr(new_map);
	free_str(new_map);
	free_arr();
}
