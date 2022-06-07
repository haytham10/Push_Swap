/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:27:38 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/05/23 18:25:18 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *lst_a, t_list *lst_b, int p)
{
	if (!lst_a)
		return ;
	if (lst_a->next)
	{
		ft_swap(&lst_a->content, &lst_a->next->content);
		if (p == 1)
			ft_putendl_fd("sa", 1);
		if (p == 2)
		{
			ft_putstr_fd("Execute sa:\n\n", 1);
			visualizer(lst_a, lst_b);
		}
	}
}

void	sb(t_list *lst_a, t_list *lst_b, int p)
{
	if (!lst_b)
		return ;
	if (lst_b->next)
	{
		ft_swap(&lst_b->content, &lst_b->next->content);
		if (p == 1)
			ft_putendl_fd("sb", 1);
		if (p == 2)
		{
			ft_putstr_fd("Execute sb:\n\n", 1);
			visualizer(lst_a, lst_b);
		}
	}
}

void	ss(t_list *lst_a, t_list *lst_b, int p)
{
	sa(lst_a, lst_b, 0);
	sb(lst_a, lst_b, 0);
	if (p == 1)
		ft_putendl_fd("ss", 1);
	if (p == 2)
	{
		ft_putstr_fd("Execute ss:\n\n", 1);
		visualizer(lst_a, lst_b);
	}
}
