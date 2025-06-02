/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:15:38 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/02 18:17:04 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

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

int	main(int argc, char *argv[])
{
	t_stacks	s;
	int			*nums;

	if (argc < 2)
		return (0);
	if (!checknum(argc, argv) || !norep(argv, argc))
		return (ft_printf("Error\n"), 1);
	nums = list_nums(argv + 1, argc - 1);
	if (!nums)
		return (ft_printf("Error\n"), 1);
	s = init_stacks(nums, argc - 1);
	if (!s.a)
	{
		ft_printf("Error\n");
		free(nums);
		free_stacks(&s); // esto faltaba!!!
		return (1);
	}
	selector(&s);/*
	ft_printf("a:");
	ft_printlist(s.a);
	ft_printf("b:");
	ft_printlist(s.b);*/
	free_stacks(&s);
	free(nums);
	return (0);
}
