/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:05:21 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/06 22:40:47 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_list **lst_a, t_list **lst_b, t_info *info)
{
	int	i;
	int	j;

	while (!is_sort(*lst_a))
	{
		i = 0;
		j = find_pos(find_min(*lst_a), *lst_a);
		if (j == -1)
			return ;
		if (j <= (find_size(*lst_a) / 2))
			while (i++ < j)
				ra(lst_a, lst_b, info->vis);
		else
			while (i++ < (find_size(*lst_a) - j))
				rra(lst_a, lst_b, info->vis);
		if (!is_sort(*lst_a))
			pb(*(&lst_a), *(&lst_b), info->vis);
	}
	while (*lst_b)
		pa(*(&lst_a), *(&lst_b), info->vis);
}

void	push_b(int size, t_list **lst_a, t_list **lst_b, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < 2)
	{
		j = 0;
		if (find_pos(find_min(*lst_a), *lst_a) < size / 2)
			j = 1;
		while ((*lst_a)->content != find_min(*lst_a))
		{
			if (j)
				ra(lst_a, lst_b, info->vis);
			else
				rra(lst_a, lst_b, info->vis);
		}
		pa(lst_a, lst_b, info->vis);
	}
}

void	short_resolve(t_list **lst_a, t_info *info)
{
	int		size;
	t_list	*lst_b;

	lst_b = 0;
	size = find_size(*lst_a);
	if (is_sort(*lst_a))
		return ;
	if (size == 5)
		sort_five(lst_a, &lst_b, info);
	else if (size > 5)
		push_b(size, lst_a, &lst_b, info);
	while (!is_sort(*lst_a))
	{
		if ((*lst_a)->content >= find_max(*lst_a, 0))
			ra(lst_a, &lst_b, info->vis);
		else if ((*lst_a)->content > (*lst_a)->next->content)
			sa(*lst_a, lst_b, info->vis);
		else
			ra(lst_a, &lst_b, info->vis);
	}
	if (size > 3)
	{
		pa(lst_a, &lst_b, info->vis);
		pa(lst_a, &lst_b, info->vis);
	}
}
