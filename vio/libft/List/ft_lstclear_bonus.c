/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:48:50 by epascual          #+#    #+#             */
/*   Updated: 2025/06/01 23:01:42 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"
/*
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if (lst)
	{
		while (*lst)
		{
			t = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = t;
		}
	}
}
*/
#include <stdio.h> // <--- Añade esta línea

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

//	printf("[ft_lstclear] Iniciando limpieza para la lista %p (cabeza actual: %p)\n", (void *)lst, (void *)*lst);
	if (lst)
	{
		while (*lst)
		{
//			printf("[ft_lstclear] Procesando nodo actual %p (siguiente: %p)\n", (void *)*lst, (void *)(*lst)->next);
			t = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = t;
		}
//		printf("[ft_lstclear] Limpieza de lista finalizada. La cabeza es ahora %p\n", (void *)*lst);
	}
//	else
//	{
//		printf("[ft_lstclear] Llamada con puntero a lista NULL.\n");
//	}
}
