/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual42 <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:02:35 by epascual42        #+#    #+#             */
/*   Updated: 2025/05/10 11:03:04 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
    - index_stack(stacks->a);                   // primero convertimos los valores a índices
    - radix_sort(&stacks->a, &stacks->b);       // luego aplicamos radix sort 
*/
void	radix_sort(t_list **a, t_list **b)
{
	int		max_bits;
	int		size;
	int		i, j;
	t_list	*node;

	size = ft_lstsize(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			node = *a;
			if (((node->content >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

/*
    - Reservar memoria para un array de tamaño size.
    - Recorrer la lista a desde el principio.
    - En cada nodo, copiar *(int *)content al array.
    - Devolver el array resultante.
*/
static int	*list_to_array(t_list *a, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = *(int *)a->content;
		a = a->next;
	}
	return (arr);
}

/*
    - Usar bubble sort para recorrer el array dos veces:
    - Si arr[i] > arr[j], intercambiarlos.
    - Repetir hasta que todos los elementos estén ordenados.
*/
static void	sort_array(int *arr, int size)
{
	int	i, j, tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*
    - Recorrer el array desde i = 0 hasta size.
    - Si arr[i] == val, devolver i (la posición).
    - Si no se encuentra, devolver -1 (aunque no debería pasar).
*/
static int	get_index(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

/*
    - Obtener el tamaño del stack con ft_lstsize(a).
    - Copiar los valores a un array (list_to_array).
    - Ordenar ese array (sort_array).
    - Recorrer la lista a:
    - Para cada nodo, buscar su valor original en el array ordenado.
    - Reemplazar el valor del nodo por el índice encontrado (get_index).
    - Liberar el array.
*/
void	index_stack(t_list *a)
{
	int		*arr;
	int		size;
	t_list	*tmp;

	size = ft_lstsize(a);	// funcion del bonus
	arr = list_to_array(a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	tmp = a;
	while (tmp)
	{
		int *num = tmp->content;
		int idx = get_index(arr, size, *num);
		*num = idx;
		tmp = tmp->next;
	}
	free(arr);
}
