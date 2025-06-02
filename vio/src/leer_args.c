/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:25:34 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/02 21:38:22 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
   Inicializa una estructura t_stacks. Reserva memoria para dos stacks
   (stack_a y stack_b)

   En C, (void) no convierte un valor a puntero, simplemente indica
   que algo no devuelve nada. El contenido de un nodo (void *content)
   necesita un puntero válido, no un valor directo.
 */

t_list	*new_stack_node(int num)
{
	t_list	*node;
	int		*value;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	value = malloc(sizeof(int));
	if (!value)
	{
		free(node);
		return (NULL);
	}
	*value = num;
	node->content = value;
	node->next = NULL;
	return (node);
}

t_stacks	init_stacks(int *nums, int size)
{
	t_stacks	s;
	t_list		*node;
	int			i;

	s.a = NULL;
	s.b = NULL;
	i = 0;
	while (i < size)
	{
		node = new_stack_node(nums[i]);
		if (!node)
		{
			free_stacks(&s);
			s.a = NULL;
			s.b = NULL;
			return (s);
		}
		ft_lstadd_back(&s.a, node);
		i++;
	}
	return (s);
}

void	free_stacks(t_stacks *s)
{
	if (s->a)
		ft_lstclear(&(s->a), &free);
	if (s->b)
		ft_lstclear(&(s->b), &free);
}

/*
   Reserva memoria para el array y parsea argv con atoi
 */
int	*list_nums(char **argv, int count)
{
	int	*nums;
	int	i;

	if (!argv || count < 1)
		return (NULL);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (NULL);
	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(argv[i]);
		i++;
	}
	return (nums);
}
