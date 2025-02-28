/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:16:15 by epascual          #+#    #+#             */
/*   Updated: 2025/02/27 16:12:18 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

void	printlist(t_list *a)
{
	while (a->next != NULL)
	{
		ft_printf("%p", a->content);
		tmp = a->next;
	}
}