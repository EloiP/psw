/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:02 by epascual          #+#    #+#             */
/*   Updated: 2025/02/28 14:57:08 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*Parece ser que sa = sb, pa = pb, ra = rb, rra = rrb
 * Has de utilizar el stack b como si fuera el temporal?
 * No usar atoi por si letras intercaladas.
 * Necesitas una util que cuente el tamano de los arrays
 * */
int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	int		i;
	int		*c;

	if (!checkargs(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	i = 1;
	a = NULL;
	b = ft_lstnew(NULL);
	if (!b)
		return (1);
	while (i < argc)
	{
		c = malloc(sizeof(long));
		*c = ft_atoi(argv[i]);
		tmp = ft_lstnew(c);
		ft_lstadd_back(&a, tmp);
		i++;
	}
	ft_printf("Imprime a:\n");
	ft_printlist(a);
	int ix = checkorder(a);
	if (ix)
		ft_printf("Ordenado");
	else
		ft_printf("No ordenado");
	//algorithm(a, b);
	return (0);
}
