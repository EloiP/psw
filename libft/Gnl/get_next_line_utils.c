/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:52:59 by epascual          #+#    #+#             */
/*   Updated: 2025/02/17 14:04:26 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
