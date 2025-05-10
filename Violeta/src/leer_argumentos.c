/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_argumentos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:25:34 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/10 11:01:12 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
	Devuelve una lista con todos los argumentos separados por espacios.
	Se usará para leer los números del stack en forma de strings.
*/
char	**leer_argumentos(char const *str)
{
	if (!str)
		return (NULL);
	return ft_split(str, ' ');
}

/*
	Cuenta cuántos argumentos hay, separando por espacios.
*/
static size_t	contar_args(char const *str)
{
	size_t	num_args;
	size_t	aux;

	num_args = 1;
	aux = 0;
	while (str[aux])
	{
		if (str[aux] == ' ')
			num_args++;
		aux++;
	}
	return (num_args);
}

/*
	Convierte la lista de strings en enteros usando ft_atoi,
	validando que se pasan al menos N argumentos y preasignando memoria.
*/
int	*list_nums(char const *str)
{
	char	**aux;
	int		*nums;
	int		i, count;

	if (!str)
		return (NULL);

	count = contar_args(str);
	if (count < 1)
		return (NULL);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (NULL);
	aux = leer_argumentos(str);
	if (!aux)
	{
		free(nums);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(aux[i]);
		i++;
	}
	liberar_array(aux);
	return (nums);
}

void	liberar_array(char **array)
{
	int	i;

	if (!array)
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/*
Inicializa una estructura t_stacks. Reserva memoria para dos stacks
(stack_a y stack_b)
*/

t_stacks	init_stacks(int *nums, int size)
{
	t_stacks	s;
	t_list		*a;
	t_list		*new_node;
	int			i;

	a = NULL;
	i = 0;
	while (i < size)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			while (a)
			{
				t_list *tmp = a;
				a = a->next;
				free(tmp);
			}
			free(nums);
			s.a = NULL;
			s.b = NULL;
			return (s);
		}
		new_node->content = nums[i];
		new_node->next = NULL;
		if (!a)
			a = new_node;
		else
		{
			t_list *last = a;
			while (last->next)
				last = last->next;
			last->next = new_node;
		}
		i++;
	}
	s.a = a;
	s.b = NULL;
	return (s);
}

