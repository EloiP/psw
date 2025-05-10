/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:52:59 by epascual          #+#    #+#             */
/*   Updated: 2024/12/13 21:09:49 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

void	*ft_calloc(unsigned long nelem, unsigned long elsize)
{
	void			*ptr;
	unsigned long	n;

	n = nelem * elsize;
	if ((nelem * elsize) > 2147483647)
		return (NULL);
	ptr = (void *)malloc(n);
	if (!ptr)
		return (NULL);
	while (0 < n)
	{
		((unsigned char *)ptr)[n -1] = 0;
		n--;
	}
	return (ptr);
}

unsigned long	ft_strlen(const char *str)
{
	unsigned long	ret;

	ret = 0;
	while (*str)
	{
		str++;
		ret++;
	}
	return (ret);
}

char	*ft_strchr(char *save, char c)
{
	unsigned long	i;

	i = 0;
	while (save[i] != c && save[i] != '\0')
		i++;
	if (save[i] == c)
		return (save);
	return (NULL);
}
