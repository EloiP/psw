/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:22 by epascual          #+#    #+#             */
/*   Updated: 2025/06/02 18:15:24 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

//Un regalito
/*void	push(t_list **x, t_list **y)
{
	t_list	*tmp;

	if (!x || !*x)
		return ;
	if (ft_lstsize(*y) < 1)
		return ;
	tmp = *x;
	*x = (*x)->next;
	tmp->next = *y;
	*y = tmp;
}*/

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	/*if ((*src)->next == NULL)
	{
		(*src)->next = NULL;
		*dst = *src;
		*src = NULL;
	}
	else
	{*/
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
	//}
}

void	pa(t_list **x, t_list **y)
{
	push(y, x);
	ft_printf("pa\n");
}

void	pb(t_list **y, t_list **x)
{
	push(y, x);
	ft_printf("pb\n");
}
