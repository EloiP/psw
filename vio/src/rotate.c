/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:52 by epascual          #+#    #+#             */
/*   Updated: 2025/05/10 11:03:44 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

//Los primeros seran los ultimos
/*void	rotate(t_list **x)
{
	t_list	*uno;
	t_list	*ulti;

	if (ft_lstsize(*x) < 2)
		return ;
	uno = *x;
	ulti = ft_lstlast(*x);
	*x = uno->next;
	ulti->next = uno;
}*/
void rotate(t_list **x)
{
    t_list *uno;
    t_list *ulti;

    if (x == NULL || *x == NULL || ft_lstsize(*x) < 2)
        return; // Check for NULL pointers and list size

    uno = *x; // Get the first element
    ulti = ft_lstlast(*x); // Get the last element
    if (ulti == NULL) // Check if the last element is valid
        return;

    *x = uno->next; // Update head to the second element
    if (*x == NULL) // If the list only had one element
        return;

    ulti->next = uno; // Link the last element to the former first element
    uno->next = NULL; // Ensure the new last element points to NULL
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
