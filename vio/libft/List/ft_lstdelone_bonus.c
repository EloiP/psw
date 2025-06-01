/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:48:34 by epascual          #+#    #+#             */
/*   Updated: 2025/06/01 23:00:51 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

/*
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del && lst->content)
			del(lst->content);
		free(lst);
	}
}
*/

#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
//		printf("[ft_lstdelone] Intentando liberar nodo %p\n", (void *)lst);
		if (del && lst->content)
		{
//			printf("[ft_lstdelone] Liberando contenido %p (valor: %d)\n", (void *)lst->content, *(int *)lst->content); // Asume que content es int*
			del(lst->content);
		}
//		else
//		{
//			printf("[ft_lstdelone] Contenido o función 'del' no válidos para nodo %p\n", (void *)lst);
//		}
//		printf("[ft_lstdelone] Nodo %p liberado.\n", (void *)lst);
                free(lst);

	}
//	else
//	{
//		printf("[ft_lstdelone] Llamada con lst NULL.\n");
//	}
}
