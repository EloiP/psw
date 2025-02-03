/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:39:02 by epascual          #+#    #+#             */
/*   Updated: 2025/02/03 13:04:35 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psw.h"
#include "../include/libft.h"

/*Parece ser que sa = sb, pa = pb, ra = rb, rra = rrb
 * Has de utilizar el stack b como si fuera el temporal?
 * No usar atoi por si letras intercaladas.
 * Necesitas una util que cuente el tamano de los arrays
 * */
int	main(int argc, char *argv[])
{
	t_list	**a;
	t_list	**b;
	t_list	*tmp;
	int		i;

	if (!checkargs(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	a = &ft_lstnew(ft_atoi(argv[1]));
	b = &ft_lstnew(NULL);
	i = 2;
	while (i <= argc)
	{
		tmp = ft_lstnew(ft_atoi(*argv[i]));
		ft_lstadd_back(a, tmp);
	}
	//algorithm(a, b);
	return (0);
}
