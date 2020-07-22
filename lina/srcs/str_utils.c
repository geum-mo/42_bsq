/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:45:42 by llim              #+#    #+#             */
/*   Updated: 2020/07/22 19:03:34 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strndup(char *str, int size)
{
	char	*temp;
	int		i;

	if (!(temp = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int		ft_atoi(char *str, int len)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < len)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void	print_arr(char **arr)
{
	int i;

	i = 0;
	while (i < g_info.i_size)
	{
		write(1, arr[i], g_info.j_size);
		write(1, "\n", 1);
		i++;
	}
}

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	init_struct(void)
{
	g_info.i_size = 0;
	g_info.j_size = 0;
	g_info.empty = 0;
	g_info.obstacle = 0;
	g_info.full = 0;
	g_info.i_index = 0;
	g_info.j_index = 0;
	g_info.max = 1;
}

