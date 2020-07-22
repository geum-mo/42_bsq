/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:01:28 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 17:15:04 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		map_size(char *file_name)
{
	int		size;
	int		fd;
	char	buff[4096];

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	size = 0;
	while (read(fd, buff, 1))
		size++;
	close(fd);
	return (size);
}

char	*input_map(char *file_name, int size)
{
	char	*s;
	int		fd;

	if (!(s = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	read(fd, s, size);
	s[size] = '\0';
	close(fd);
	return (s);
}

int		get_row_count(char *strmap)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (strmap[i])
	{
		if (strmap[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**split_map(char *map_in_str, int size)
{
	int		i;
	char	**temp;
	int		len;

	i = 0;
	if (!(temp = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	len = 0;
	temp[size] = 0;
	while (*map_in_str)
	{
		if (*map_in_str == '\n')
		{
			if (len != 0)
				temp[i++] = ft_strndup(map_in_str - len, len); //
			len = 0;
		}
		else
			len++;
		map_in_str++;
	}
	if (len != 0)
		temp[i] = ft_strndup(map_in_str - len, len);
	return (temp);
}
