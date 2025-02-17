/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:16:15 by epascual          #+#    #+#             */
/*   Updated: 2025/02/17 16:08:04 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"
#include "../Includes/libft.h"

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

void	sa(t_list **x)
{
	char	*vn;

	swap(x);
	ft_printf("sa\n");
}

void	sb(t_list **x)
{
	char	*vn;

	swap(x);
	ft_printf("sb\n");
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
	tmp = (*x)->next;
	(*x)->next = *y;
	*y = *x;
	*x = tmp;
}

void	pa(x, y)
{
	push(x, y);
	ft_printf("pa\n");
}

void	pb(y, x)
{
	push(x, y);
	ft_printf("pb\n");
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

void	ra(t_list **x)
{
	rotate(x);
	ft_printf("ra\n");
}

void	rb(t_list **x)
{
	rotate(x);
	ft_printf("rb\n");
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

void	rra(t_list **x)
{
	reverse_rotate(x);
	ft_printf("rra\n");
}

void	rrb(t_list **x)
{
	reverse_rotate(x);
	ft_printf("rrb\n");
}

void	rrr(t_list **x, t_list **y)
{
	reverse_rotate(x);
	reverse_rotate(y);
	ft_printf("rrr\n");
}
