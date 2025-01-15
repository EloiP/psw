/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:16:15 by epascual          #+#    #+#             */
/*   Updated: 2025/01/15 14:29:11 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//El cambio es inevitable
void	swap(t_list **x)
{
	void *tmp;
	if ((lstlen(*x)<2) || (*x == NULL) || (*x->next == NULL))
		return ;
	tmp = (*x)->content;
	(*x)->content = (*x)->next->content;
	(*x)->next->content = tmp;
}
/*Alternativa:
 * t_list *tmp; 
 * tmp = *x; 
 * *x = (*x)->next; 
 * (*x)->next = tmp*/
void	sx(t_list x)
{
	char*	vn;

	vn = GET_VNAME(x);
	swap(x);
	ft_printf("s%s\n", vn);
}

void	ss(x,y)
{
	swap(x);
	swap(y);
	ft_printf("ss\n");
}

void	push(x,y)
{
	if (llen(y)<1)
		return ;
}
//Los primeros seran los ultimos
void	rotate(x)
{
if (llen(x)<2)
		return (0);
}
//Y los ultimos seran los primeros
void	reverse rotate(x)
{
if (llen(x)<2)
		return (0);
}
