/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:00:08 by epascual          #+#    #+#             */
/*   Updated: 2025/03/04 18:27:19 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_H
# define PSW_H

# include "libft.h"

//checks
int		checkorder(t_list *ord);
int		checkargs(int argc, char **argv);
int		norep(char **argv, int argc);
int		checknum(int argc, char **argv);
void	ft_printlist(t_list *a);
//Instrucciones
void	push(t_list *x, t_list *y);
void	pa(t_list *x, t_list *y);
void	pb(t_list *x, t_list *y);
void	reverse_rotate(t_list **x);
void	rra(t_list **x);
void	rrb(t_list **x);
void	rrr(t_list **x, t_list **y);
void	rotate(t_list **x);
void	ra(t_list **x);
void	rb(t_list **x);
void	swap(t_list **x);
void	sa(t_list **x);
void	sb(t_list **x);
void	ss(t_list **x, t_list **y);
//Algoritmos
void	algorithm(t_list *a, t_list *b);
#endif
