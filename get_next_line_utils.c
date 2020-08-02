/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:48:21 by vtweek            #+#    #+#             */
/*   Updated: 2020/07/12 19:30:08 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_len(char *c)
{
	int		count;

	count = 0;
	while (*(c + count) != '\0')
		count++;
	return (count);
}

char		*ft_strdup(char *str)
{
	char	*c;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(c = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	index;
	size_t			fact_len;
	char			*result;

	index = 0;
	fact_len = 0;
	if (!s || start >= (unsigned int)ft_len((char *)s))
		return (ft_strdup(""));
	while (fact_len < len && s[fact_len + start] != '\0')
		fact_len++;
	if (!(result = (char*)malloc(sizeof(char) * (fact_len + 1))))
		return (NULL);
	while (fact_len > 0 && s[start] != '\0')
	{
		result[index] = s[start];
		start++;
		index++;
		fact_len--;
	}
	result[index] = '\0';
	return (result);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		index;
	char	*new;
	char	*ptr_s1;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	ptr_s1 = s1;
	if (!(new = (char*)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1))))
		return (NULL);
	len = 0;
	while (s1[index])
	{
		new[index] = s1[index];
		index++;
	}
	while (s2[len])
	{
		new[index + len] = s2[len];
		len++;
	}
	new[index + len] = '\0';
	free(ptr_s1);
	return (new);
}

char		*ft_linecopy(const char *src, size_t size)
{
	unsigned char	*ptr_src;
	char			*dst_ptr;
	size_t			len;

	ptr_src = (unsigned char*)src;
	len = 0;
	if (!src)
		return (NULL);
	while (*(ptr_src + len) && (char)*(ptr_src + len) != '\n')
		len++;
	if (!(dst_ptr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	if (size != 0)
	{
		while ((len < size && *(ptr_src + len))
				&& (char)*(ptr_src + len) != '\n')
		{
			*(dst_ptr + len) = *(ptr_src + len);
			len++;
		}
	}
	*(dst_ptr + len) = '\0';
	return (dst_ptr);
}
