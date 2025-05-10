/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:22 by epascual          #+#    #+#             */
/*   Updated: 2025/05/10 11:01:54 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

//Un regalito
void	push(t_list *x, t_list *y)
{
	t_list	*tmp;

	if (ft_lstsize(y) < 1)
		return ;
	tmp = (x)->next;
	(x)->next = y;
	y = x;
	x = tmp;
}

void	pa(t_list *x, t_list *y)
{
	push(x, y);
	ft_printf("pa\n");
}

void	pb(t_list *y, t_list *x)
{
	push(x, y);
	ft_printf("pb\n");
}
