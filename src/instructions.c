/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:16:15 by epascual          #+#    #+#             */
/*   Updated: 2025/02/03 13:40:31 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

//El cambio es inevitable
void	swap(t_list **x)
{
	void	*tmp;

	if ((ft_lstsize(*x) < 2) || (*x == NULL) || (*x->next == NULL))
		return ;
	tmp = (*x)->content;
	(*x)->content = (*x)->next->content;
	(*x)->next->content = tmp;
}

/*Alternativa:
 * t_list* tmp; 
 * tmp = *x; 
 * *x = (*x)->next; 
 * (*x)->next = tmp*/

void	sx(t_list **x)
{
	char	*vn;

	vn = GET_VNAME(**x);
	swap(x);
	ft_printf("s%s\n", vn);
}

void	ss(t_list **x, t_list **y)
{
	swap(x);
	swap(y);
	ft_printf("ss\n");
}

//Un regalito
void	push(x, y)
{
	t_list	*tmp;
	char	*vn;

	if (ft_lstsize(y) < 1)
		return ;
	vn = GET_VNAME(x);
	tmp = (*x)->next;
	(*x)->next = *y;
	*y = *x;
	*x = tmp;
	ft_printf("p%s\n", vn);
}

void	pa(x, y)
{
	push(x, y);
}

void	pb(y, x)
{
	push(x, y);
}

//Los primeros seran los ultimos
void	rotate(t_list **x)
{
	t_list	*uno;
	t_list	*ulti;

	if (ft_lstsize(x) < 2)
		return ;
	uno = *x;
	ulti = ft_lstlast(*x);
	*x = uno->next;
	ulti->next = uno;
}

void	rx(t_list **x)
{
	char	*vn;

	vn = GET_VNAME(x);
	rotate(x);
	ft_printf("r%s\n", vn);
}

//Y los ultimos seran los primeros
void	reverse_rotate(t_list **x)
{
	t_list	*tmp;
	t_list	*uno;
	t_list	*ulti;

	if (ft_lstsize(x) < 2)
		return ;
	uno = ft_lstlast(*x);
	ulti = ft_lstalast(*x);
	tmp = *x;
	*x = uno;
	(*x)->next = tmp;
	ulti->next = NULL;
}

void	rrx(t_list **x)
{
	char	*vn;

	vn = GET_VNAME(x);
	reverse_rotate(x);
	ft_printf("rr%s\n", vn);
}

void	rrr(t_list **x, t_list **y)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
