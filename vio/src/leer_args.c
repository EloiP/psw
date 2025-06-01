/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leer_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelandr <avelandr@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 01:25:34 by avelandr          #+#    #+#             */
/*   Updated: 2025/06/01 23:00:04 by avelandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/psw.h"

/*
   Inicializa una estructura t_stacks. Reserva memoria para dos stacks
   (stack_a y stack_b)

   En C, (void) no convierte un valor a puntero, simplemente indica
   que algo no devuelve nada. El contenido de un nodo (void *content)
   necesita un puntero válido, no un valor directo.
 */
/*
   t_list	*new_stack_node(int n)
   {
   t_list	*new_node;
   int		*value;
// Los nodos no se liberan nunca, se ha de llamar free_stacks EN EL MAIN (por qué lo quitamos??? hay leaks indirectos desde init_stacks
new_node = malloc(sizeof(t_list));
if (!new_node)
return (NULL);
value = malloc(sizeof(int));
if (!value)
{
free(new_node);
return (NULL);
}
 *value = n;
 new_node->content = value;
 new_node->next = NULL;
 return (new_node);
 }
 */

t_list	*new_stack_node(int num)
{
	t_list	*node;
	int		*value;	// el "4/8 byte allocation leaked" es esto
				// Segun el sanitizer, esta linea está mal como direct leak (no se libera nunca)
	node = malloc(sizeof(t_list)); // esta es la de 16
	if (!node)
		return (NULL);
	value = malloc(sizeof(int));	// aquí se crea un indirect leak
	if (!value)
	{
		free(node);
		return (NULL);
	}
	*value = num;
	node->content = value;
	node->next = NULL;
	return (node);
}

/*
   t_stacks	init_stacks(int *nums, int size)
   {
   t_stacks	s;
   t_list		*node;
   int			i;

   s.a = NULL;
   s.b = NULL;
   i = 0;
   while (i < size)
   {
   node = new_stack_node(nums[i]);
   if (!node)
   return (s);
   ft_lstadd_back(&s.a, node);
   i++;
   }
   return (s);
   }
 */
t_stacks	init_stacks(int *nums, int size)
{
	t_stacks	s;
	t_list		*node;
	int			i;

	s.a = NULL;
	s.b = NULL;
	i = 0;
	while (i < size)
	{
		node = new_stack_node(nums[i]); // dice q si este falla, los anteriores podrían no ser limpiados (PERO ESTÁ AQUÍ??)
		if (!node)
		{
			free_stacks(&s);
			s.a = NULL;
			s.b = NULL;
			return (s);
		}
		ft_lstadd_back(&s.a, node);
		i++;
	}
	return (s);
}

// entonces este es innecesario?
/*
   void	liberar_array(char **array)
   {
   int	i;

   if (!array)
   return ;
   i = 0;
   while (array[i])
   {
   free(array[i]);
   i++;
   }
   free(array);
   }
 */
/*
   void	free_stacks(t_stacks *s)
   {
   t_list	*tmp;

   while (s->a)
   {
   tmp = s->a->next;
   free(s->a->content); // esto loq libera el int*value en newstacknode:p
   free(s->a); // libera el puto nodo
   s->a = tmp;
   }
   while (s->b)
   {
   tmp = s->b->next;
   free(s->b->content);
   free(s->b);
   s->b = tmp;
   }
   }
 */

// #include <stdio.h> // <--- Añade esta línea

void	free_stacks(t_stacks *s)
{
//	printf("[free_stacks] Llamada para stacks: 'a' (cabeza: %p), 'b' (cabeza: %p)\n", (void *)s->a, (void *)s->b);
	if (s->a)
	{
//		printf("[free_stacks] Llamando ft_lstclear para pila 'a'.\n");
		ft_lstclear(&(s->a), &free);
	}
//	else
//	{
//		printf("[free_stacks] Pila 'a' ya es NULL, no hay nada que liberar.\n");
//	}

	if (s->b)
	{
//		printf("[free_stacks] Llamando ft_lstclear para pila 'b'.\n");
		ft_lstclear(&(s->b), &free);
	}
//	else
//	{
//		printf("[free_stacks] Pila 'b' ya es NULL, no hay nada que liberar.\n");
//	}
//	printf("[free_stacks] Saliendo de free_stacks.\n");
}
/*
   Reserva memoria para el array y parsea argv con atoi
 */
int	*list_nums(char **argv, int count)
{
	int	*nums;
	int	i;

	if (!argv || count < 1)
		return (NULL);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (NULL);
	i = 0;
	while (i < count)
	{
		nums[i] = ft_atoi(argv[i]);
		i++;
	}
	return (nums);
}
