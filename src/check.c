/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:38:55 by epascual          #+#    #+#             */
/*   Updated: 2025/02/03 11:56:05 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkorder(t_list **ord)
{
	int	i;

	if (!ord || !*ord)
		return (1);
	i = 1;
	while ((*ord)->next)
	{
		if ((*ord)->content < (*ord)->next->content)
			i = 1;
		else
		{
			i = 0;
			break ;
		}
		ord = &((*ord)->next);
	}
	return (i);
}
