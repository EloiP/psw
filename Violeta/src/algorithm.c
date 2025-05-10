/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:46:43 by epascual          #+#    #+#             */
/*   Updated: 2025/05/10 11:01:02 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
No entiendo por qué hacer distinción entre dos, tres y menos de 5. Yo lo dejaría solo a menos de 5
*/
void	algorithm(t_stacks *stacks)
{
	int	size;

	size = ft_lstsize(stacks->a);
	if (checkorder(stacks->a))
		return ;
	if (size == 2)
		sort_two(stacks->a);
	else if (size == 3)
		sort_three(stacks->a);
	else if (size <= 5)
		sort_small(stacks);
	else
	{
		index_stack(stacks->a);
		radix_sort(&stacks->a, &stacks->b);
	}
}

/*		Esto pa que es??
void	selector(int argc, t_list **a, t_list **b)
{
    if (argc <= 3)
        algorithm(*a, *b);
}
*/
