/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:15:38 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/07 16:59:40 by avelandr         ###   ########.fr       */
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

static int	ft_wordcount(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		else if (j == 1 && *s == c)
			j = 0;
		s++;
	}
	return (i);
}

static void	errata(int *nums, t_stacks *s, int h)
{
	if (h > 1)
		free_stacks(s);
	if (h > 0)
		free(nums);
	ft_printf("Error\n");
	exit(1);
}

static void	ft_free_pointstring(char **tab)
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

static void	handle_arguments(int argc, char *argv[], t_parsed_args *data)
{
	data->is_split_allocated = 0;
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
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	s;
	int			*nums;
	char		**str;
	int			wcnt;

	if (argc < 2)
		return (0);
	handle_arguments(argc, argv, &nums, &str, &wcnt);
	if (!nums)
		errata(NULL, NULL, 0);
	s = init_stacks(nums, wcnt);
	if (!s.a)
		errata(nums, &s, 2);
	if (!checknum(wcnt, str) || !norep(str, wcnt))
		errata(nums, &s, 2);
	selector(&s);
	if (argc == 2)
		ft_free_pointstring(str);
	free_stacks(&s);
	free(nums);
	return (0);
}
