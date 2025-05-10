/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validaciones.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:10:49 by avelandr          #+#    #+#             */
/*   Updated: 2025/05/10 11:05:03 by epascual42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"
/*
	Devuelve 0 si encuentra duplicados, 1 si todo es válido
*/
int	is_valid(int *nums, int size)
{
	int	i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (nums[i] == nums[j])
				return (0);
		}
	}
	return (1);
}
