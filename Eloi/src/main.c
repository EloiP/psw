/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:49:50 by epascual          #+#    #+#             */
/*   Updated: 2025/06/09 09:51:34 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "psw.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
   - Verifica si hay suficientes argumentos (argc < 2).
   Si no, termina el programa.
   - Comprueba que los argumentos sean números válidos (checknum) y que no
   haya duplicados (norep).
   Si falla, imprime "Error" y termina.
   - Calcula el tamaño de la lista (size = argc - 1).
   - Convierte los argumentos en una lista de números enteros (list_nums).
   Si falla, imprime "Error" y termina.
   - Inicializa las pilas (init_stacks) con los números y su tamaño.
   Si falla, imprime "Error", libera la memoria de los números y termina.
   - Llama a selector, que probablemente contiene la lógica principal.
   - Libera la memoria de la lista de números y las pilas antes de salir.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void	ft_free_pointstring(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_parsed_args	*handle_arguments(int argc, char *argv[])
{
	t_parsed_args	*data;

	data = ft_calloc(sizeof(t_parsed_args), 1);
	if (argc == 2)
	{
		data->str = ft_split(argv[1], ' ');
		data->wcnt = ft_wordcount(argv[1], ' ');
		data->nums = list_nums(data->str, data->wcnt);
		data->is_split_allocated = 1;
	}
	else
	{
		data->str = argv;
		data->wcnt = argc - 1;
		data->nums = list_nums(data->str + 1, data->wcnt);
		data->is_split_allocated = 0;
	}
	return (data);
}

int	main(int argc, char *argv[])
{
	t_stacks		s;
	t_parsed_args	*data;

	if (argc < 2)
		return (0);
	data = handle_arguments(argc, argv);
	if (!(data->nums))
		errata(NULL, NULL, 0);
	s = init_stacks((data->nums), data->wcnt);
	if (!s.a)
		errata(data->nums, &s, 2);
	if (!checknum(data->wcnt, data->str) || !norep(data->str, data->wcnt))
		errata(data->nums, &s, 2);
	selector(&s);
	if (argc == 2)
		ft_free_pointstring(data->str);
	free_stacks(&s);
	free(data->nums);
	free(data);
	return (0);
}
