/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:23:50 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/05/23 18:19:14 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b, int p)
{
	t_list	*tmp;

	if (!(*lst_b))
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
	if (p == 1)
		ft_putendl_fd("pa", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute pa:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}

void	pb(t_list **lst_a, t_list **lst_b, int p)
{
	t_list	*tmp;

	if (!(*lst_a))
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
	if (p == 1)
		ft_putendl_fd("pb", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute pb:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}
