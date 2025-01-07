/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:02 by epascual          #+#    #+#             */
/*   Updated: 2025/01/07 16:52:02 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/psw.h"
#include "include/libft.h"

/*Parece ser que sa = sb, pa = pb, ra = rb, rra = rrb
 * Has de utilizar el stack b como si fuera el temporal?
 * No usar atoi por si letras intercaladas.
 * Necesitas una util que cuente el tamano de los arrays
 * */

int main(int argc, char *argv[]){
	t_list **a;
	t_list **b;
	int i;

	if (argc < 2)
		return(1);
	checker(argc, argv);
	a = ft_lstnew(NULL);
	b = ft_lstnew(NULL);
	i = 1;
	while (i <= argc)
	{
		ft_lstadd_front(a, ft_atoi(*argv[i]));
	}
}

int	arraylen(int *a)
{
}

int	check(int argc, char **argv)
{
	
}
//Instrucciones
int	*sa(int *a, int *b){}
int	*sb(int *a, int *b){}
int	*ss(int *a, int *b){}
int	*pa(int *a, int *b){}
int	*pb(int *a, int *b){}
int	*ra(int *a, int *b){}
int	*rb(int *a, int *b){}
int	*rr(int *a, int *b){}
int	*rra(int *a, int *b){}
int	*rrb(int *a, int *b){}
int	*rrr(int *a, int *b){}
