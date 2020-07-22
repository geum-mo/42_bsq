/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekang <gekang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:59:30 by gekang            #+#    #+#             */
/*   Updated: 2020/07/22 17:05:28 by gekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct	s_map
{
	int			i_size;
	int			j_size;

	char		empty;
	char		obstacle;
	char		full;

	int			i_index;
	int			j_index;
	int			max;
}				t_map;

char			**g_map;
t_map			g_info;
int				**g_arr;

void			free_arr(void);
void			free_str(char **str);
void			solve(char *argv[], int i);
void			arg_one(void);

void			init_struct(void);
void			print_arr(char **arr);
int				min(int a, int b);
int				ft_strlen(char *str);
int				ft_atoi(char *str, int len);

int				map_size(char *file_name);
char			*input_map(char *fle_name, int size);
int				get_row_count(char *strmap);
char			*ft_strndup(char *str, int size);
char			**split_map(char *strmap, int size);

char			*ft_strndupcat(char *dest, char *src, int size);
char			*get_stdin(void);

void			fill_map(char **map);
void			find_index(void);
void			malloc_g_arr(void);
void			make_g_arr(char **map);
void			make_ans(void);

int				check_input_map(void);
int				line_is_valid(int i, int j, int len);
int				check_first_line(void);

#endif
