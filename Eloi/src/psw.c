/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:02 by epascual          #+#    #+#             */
/*   Updated: 2025/04/30 14:22:30 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/psw.h"

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
	int ix = checkorder(a);
	if (ix)
		ft_printf("Ordenado\n");
	else
		ft_printf("No ordenado\n");
	if (norep(argv, argc))
		ft_printf("No repetidos\n");
	else
		ft_printf("Repetidos\n");
	if (checknum(argc, argv) == 0)
		ft_printf("No nums\n");
	else
		ft_printf("All nums\n");
	ft_printf("Imprime a:\n");
	ft_printlist(a);
	//algorithm(a, b);
	return (0);
}
