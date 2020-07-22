/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 00:41:29 by yepark            #+#    #+#             */
/*   Updated: 2020/07/22 16:59:32 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strndup_and_concat(char *dest, char *src, int size)
{
	char	*result;
	int		i;
	char	*ptr;

	ptr = dest;
	i = 0;
	if ((result = (char*)malloc(sizeof(char) * (size + 1))) == 0)
		return (0);
	while (i < size && *ptr) // 이미 저장된 dest로 string을 채우고 나서 ,
	{
		result[i] = *ptr;
		i++;
		ptr++;
	}
	while (i < size && *src) // 새롭게 추가될 src를 나머지 빈 자리에 넣는다
	{
		result[i] = *src;
		i++;
		src++;
	}
	result[i] = '\0';
	free(dest); // get_stdin 함수에서 할당한 result의 메모리를 free
	return (result);
}

char	*get_stdin(void)
{
	char	*result;
	char	*buff;
	int		read_size;
	int		result_size;

	result_size = 0;
	if ((result = (char*)malloc(sizeof(char) * (1024 + 1))) == 0)
		return (0);
	if ((buff = (char*)malloc(sizeof(char) * (1024 + 1))) == 0)
		return (0);
	while ((read_size = read(0, buff, 1024)) > 0)
	{
		result_size += read_size;
		buff[read_size] = '\0';
		result = ft_strndup_and_concat(result, buff, result_size);
	}
	free(buff);
	return (result);
}
