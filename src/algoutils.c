/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:50:16 by epascual          #+#    #+#             */
/*   Updated: 2025/03/05 20:16:40 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

int	maxlst(t_list *lst)
{
	int ret;

	ret = -2147483648;
	while (lst)
	{
		if (*(int *)lst->content > ret)
			ret = (*(int *)lst->content);
		lst = lst->next;
	}
	return (ret);
}

int	minlst(t_list *lst)
{
	int ret;

	ret = 2147483647;
	while (lst)
	{
		if (*(int *)lst->content < ret)
			ret = (*(int *)lst->content);
		lst = lst->next;
	}
	return (ret);
}

int	minthanlst(t_list *lst, int min)
{
	int ret;

	ret = -2147483648;
	while (lst)
	{
		if (*(int *)lst->content > ret && *(int *)lst->content < min)
			ret = (*(int *)lst->content);
		lst = lst->next;
	}
	return (ret);
}

int	maxthanlst(t_list *lst, int max)
{
	int ret;

	ret = 2147483647;
	while (lst)
	{
		if (*(int *)lst->content < ret && *(int *)lst->content > max)
			ret = (*(int *)lst->content);
		lst = lst->next;
	}
	return (ret);
}

t_list	**lstnum(t_list *lst, int num)
{
	t_list	**ret;

	ret = NULL;
	while(lst)
	{
		if (*(int *)lst->content == num)
			ret = &lst;
		lst = lst->next;
	}
	return (ret);
}
