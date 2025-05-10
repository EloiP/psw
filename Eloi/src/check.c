/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:38:55 by epascual          #+#    #+#             */
/*   Updated: 2025/03/04 18:35:43 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/psw.h"

//Comprueba el orden
int	checkorder(t_list *ord)
{
	int	i;

	if (!ord)
		return (1);
	i = 1;
	while (ord->next)
	{
		if ((*(int *) (ord->content) < ((*(int *)(ord->next->content)))))
			i += 1;
		else
		{
			i = 0;
			break ;
		}
		ord = ord->next;
	}
	return (i);
}

int	norep(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i <= argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checknum(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (j == 0 && (argv[i][j] != '-' || argv[i][j] != '+'))
				j++;
			if (argv[i][j] && !ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//Comprueba los argumentos
int	checkargs(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!argv)
		return (0);
	return (1);
}
