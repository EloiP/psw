/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:52:04 by epascual          #+#    #+#             */
/*   Updated: 2025/02/11 18:33:12 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_isalnum(int c)
{
	if ((c < 65 || c > 122 || (c < 97 && c > 90)) && (c < 48 || c > 57))
	{
		return (0);
	}
	return (1);
}
