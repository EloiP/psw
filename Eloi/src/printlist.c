/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:16:15 by epascual          #+#    #+#             */
/*   Updated: 2025/02/28 14:42:03 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/psw.h"

void	ft_printlist(t_list *a)
{
	int tmp;

	if (a == NULL)
		return ;
	while (a)
	{
		tmp = (*(long *)(a->content));
		ft_printf("stack num is: %i\n", tmp);
		a = a->next;
	}
}
