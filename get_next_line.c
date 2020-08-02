/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:59:22 by vtweek            #+#    #+#             */
/*   Updated: 2020/07/12 19:15:12 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	char	find;
	char	*ptr;

	ptr = (char*)s;
	find = (char)c;
	while (*(ptr) != '\0' && *ptr != find)
		ptr++;
	if (*(char*)ptr == find)
		return ((char*)ptr);
	return (0);
}

int			result(int flag, char **saved_string)
{
	if (flag == 1)
	{
		free(*saved_string);
		*saved_string = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*svd;
	char			tmp[BUFFER_SIZE + 1];
	int				r;
	int				end_flag;
	char			*temp;

	r = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || !line || read(fd, tmp, 0) != 0)
		return (-1);
	if (!svd)
		svd = ft_strdup("");
	while (!(ft_strchr(svd, '\n')) && (r = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[r] = '\0';
		svd = ft_strjoin(svd, tmp);
	}
	*line = ft_linecopy(svd, ft_len(svd));
	if (r < 0 || !(*line))
		return (-1);
	end_flag = (!ft_strchr(svd, '\n')) ? 1 : 0;
	temp = ft_substr(svd, ft_len(*line) + 1, ft_len(svd) - ft_len(*line));
	free(svd);
	svd = temp;
	return (result(end_flag, &svd));
}
