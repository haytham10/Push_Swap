/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:13:02 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/05/26 18:37:47 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **lst_a, t_list **lst_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*lst_a) || !((*lst_a)->next))
		return ;
	tmp = *lst_a;
	cp = *lst_a;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *lst_a;
	*lst_a = tmp;
	if (p == 1)
		ft_putendl_fd("rra", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute rra:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}

void	rrb(t_list **lst_a, t_list **lst_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*lst_b) || !(*lst_b)->next)
		return ;
	tmp = *lst_b;
	cp = *lst_b;
	if (!(*lst_b))
		return ;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *lst_b;
	*lst_b = tmp;
	if (p == 1)
		ft_putendl_fd("rrb", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute rrb:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}

void	rrr(t_list **lst_a, t_list **lst_b, int p)
{
	rra(lst_a, lst_b, 0);
	rrb(lst_b, lst_b, 0);
	if (p == 1)
		ft_putendl_fd("rrr", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute rrr:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}
