/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_mgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:03:43 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 17:03:49 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_arr(void)
{
	int	i;

	i = 0;
	while (i < g_info.i_size)
	{
		free(g_arr[i]);
		i++;
	}
	free(g_arr);
}

void	free_str(char **str)
{
	int			i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
