/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:28:02 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/05/26 18:39:31 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **lst_a, t_list **lst_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*lst_a) || !(*lst_a)->next)
		return ;
	tmp = *lst_a;
	cp = (*lst_a)->next;
	while ((*lst_a)->next)
		*lst_a = (*lst_a)->next;
	(*lst_a)->next = tmp;
	tmp->next = NULL;
	*lst_a = cp;
	if (p == 1)
		ft_putendl_fd("ra", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute ra:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}

void	rb(t_list **lst_a, t_list **lst_b, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*lst_b) || !(*lst_b)->next)
		return ;
	tmp = *lst_b;
	cp = (*lst_b)->next;
	while ((*lst_b)->next)
		*lst_b = (*lst_b)->next;
	(*lst_b)->next = tmp;
	tmp->next = NULL;
	*lst_b = cp;
	if (p == 1)
		ft_putendl_fd("rb", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute rb:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}

void	rr(t_list **lst_a, t_list **lst_b, int p)
{
	ra(lst_a, lst_b, 0);
	rb(lst_a, lst_b, 0);
	if (p == 1)
		ft_putendl_fd("rr", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute rr:\n\n", 1);
		visualizer(*lst_a, *lst_b);
	}
}
