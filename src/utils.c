/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:38:02 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/05/23 17:43:17 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(int n, t_list *lst)
{
	int	pos;

	pos = 0;
	while (lst->content != n)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

int	is_sort(t_list *lst_a)
{
	while (lst_a->next)
	{
		if (lst_a->content > lst_a->next->content)
			return (0);
		lst_a = lst_a->next;
	}
	return (1);
}

int	find_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_max(t_list *lst, int skip)
{
	int	max;

	max = -2147483648;
	while (lst->next)
	{
		if (lst->content > max && lst->content != skip)
			max = lst->content;
		lst = lst->next;
	}
	if (lst->content > max && lst->content != skip)
		max = lst->content;
	return (max);
}

int	find_min(t_list *lst)
{
	int	min;

	min = 2147483647;
	while (lst->next)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	if (lst->content < min)
		min = lst->content;
	return (min);
}
