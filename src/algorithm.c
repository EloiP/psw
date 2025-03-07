/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:46:43 by epascual          #+#    #+#             */
/*   Updated: 2025/02/27 16:22:22 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/psw.h"

void	algorithm(t_list *a, t_list *b)
{
	a->next = NULL;
	b->next = NULL;
	exit(0);
}

void	selector(int argc, t_list **a, t_list **b)
{
    if (argc <= 3)
        algorithm(*a, *b);
}
