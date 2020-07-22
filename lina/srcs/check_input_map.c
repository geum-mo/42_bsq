/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:00:11 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 22:01:56 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		check_first_line(void)
{
	int len;
	int i;
	int size;

	size = 0;
	init_struct(); // 구조체 초기화
	len = 0;
	while (g_map[0][len]) // 첫째 줄 총 길이
		len++;
	i = len - 1; // index니까 -1
	if (i < 3) // 첫 줄엔 4가지 요소가 꼭 있어야 하고, i는 len - 1이므로, i는 3보다 커야함
		return (1);
	g_meta.full = g_map[0][i--]; // 있어야 하는 위치 순서대로
	g_meta.obstacle = g_map[0][i--]; // 있어야 하는 위치 순서대로
	g_meta.empty = g_map[0][i--]; // 있어야 하는 위치 순서대로
	while (i >= 0)
	{
		if (!(g_map[0][i] >= '0' && g_map[0][i] <= '9')) // row 갯수 (숫자만 있어야 함)
			return (1);
		i--;
	}
	g_meta.x_size = ft_atoi(g_map[0], len - 3); // 총 row 갯수 = x_size
	return (0);
}

int		check_row_column_count(int i, int j, int len) // 바로 밑에서 다 초기화하는데 애초에 왜 i, j, len을 매개변수로 줌? 노미넷 25줄 제한 때문에...
{
	i = 1;
	while (g_map[1][g_meta.y_size] != '\0')
		g_meta.y_size += 1; // column 수 count
	while (i <= g_meta.x_size)
	{
		if (g_map[i] == NULL)
			return (1);
		len = 0;
		j = 0;
		while (g_map[i][j]) // map의 처음부터 끝까지 while loop을 돌려서
		{
			if ((g_map[i][j] != g_meta.empty)
					&& (g_map[i][j] != g_meta.obstacle)) // empty가 아니고 obstable이 아닌 칸을 찾으면 return 1
				return (1);
			j++;
			len++; // column 수 count
		}
		if ((len == 0) || (g_meta.y_size != 0 && g_meta.y_size != len)) // column 수 count 비교
			return (1);
		i++;
	}
	if (i != (g_meta.x_size + 1) || g_map[i] != 0) // row 수 count check
		return (1);
	return (0);
}

int		check_input_map(void)
{
	if (g_map[1] == NULL) // g_map[1]부터 값이 나와야 함.
		return (1);
	if (check_first_line() == 1) // g_map[0]이 올바른지 체크
		return (1);
	if (check_row_column_count(1, 0, 0) == 1) // check row column count로 이름 바꾸기
		return (1);
	if (g_meta.x_size == 0 || g_meta.y_size == 0) // row 또는 column 갯수가 0인 경우
		return (1);
	if (g_meta.empty == g_meta.obstacle
			|| g_meta.empty == g_meta.full || g_meta.obstacle == g_meta.empty) // 세 가지값은 서로 같으면 안됨
		return (1);
	return (0);
}
