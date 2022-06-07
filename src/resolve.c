/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:44:03 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/04 15:18:17 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max(t_list **lst_a, t_list **lst_b, int m, t_info *info)
{
	int	f;

	f = 0;
	if ((*lst_b)->content < m)
	{
		while ((*lst_b)->content != m)
		{
			if ((*lst_b)->content == m)
			{
				sb(*lst_a, *lst_b, info->vis);
				pa(lst_a, lst_b, info->vis);
				f = 1;
				break ;
			}
			if (info->flags == 1)
				rb(lst_a, lst_b, info->vis);
			else
				rrb(lst_a, lst_b, info->vis);
		}
	}
	if (!f)
		pa(lst_a, lst_b, info->vis);
}

static void	init_data(t_list *lst_b, t_data *data)
{
	data->flags_a = 0;
	data->flags_b = 0;
	data->max_b = find_max(lst_b, MIN_INT);
	data->max_a = find_max(lst_b, data->max_b);
}

void	push_a(t_list **lst_a, t_list **lst_b, t_info *info, t_data *data)
{
	while (info->size_b)
	{
		init_data(*lst_b, data);
		if ((get_a(data, lst_b, 1)) < info->size_b / 2)
			data->flags_a = 1;
		if (data->max_a != MIN_INT
			&& (get_a(data, lst_b, 0)) < info->size_b / 2)
			data->flags_b = 1;
		info->flags = data->flags_a;
		if (data->max_a != MIN_INT && data->flags_a == data->flags_b
			&& ((data->pos_a > data->pos_b && data->flags_a)
				|| (data->pos_a < data->pos_b && !data->flags_a)))
		{
			push_max(lst_a, lst_b, data->max_a, info);
			push_max(lst_a, lst_b, data->max_b, info);
			sa(*lst_a, *lst_b, info->vis);
			info->size_b--;
		}
		else
			push_max(lst_a, lst_b, data->max_b, info);
		info->size_b--;
	}
}

static void	opti_rotat(int tmp, t_list **lst_a, t_list **lst_b,
						t_info **info)
{
	while (tmp && (*info)->size_a > 2)
	{
		if ((*lst_a)->content <= (*info)->pivot)
		{
			pb(lst_a, lst_b, (*info)->vis);
			if ((*lst_b)->content < find_med(*lst_b, (*info)->size_b)
				&& (*info)->size_b > 1)
			{
				if ((*lst_a)->content > (*info)->pivot)
					rr(lst_a, lst_b, (*info)->vis);
				else
					rb(lst_a, lst_b, (*info)->vis);
			}
			(*info)->size_b++;
			(*info)->size_a--;
		}
		else
			ra(lst_a, lst_b, (*info)->vis);
		tmp--;
	}
}

int	resolve(t_list **lst_a, t_info *info)
{
	int		tmp;
	t_data	*data;
	t_list	*lst_b;

	lst_b = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (is_sort(*lst_a))
		return (1);
	info->size_a = find_size(*lst_a);
	info->size_b = 0;
	while (info->size_a > 2)
	{
		info->pivot = find_med(*lst_a, info->size_a);
		tmp = info->size_a;
		opti_rotat(tmp, lst_a, &lst_b, &info);
	}
	pb(lst_a, &lst_b, info->vis);
	pb(lst_a, &lst_b, info->vis);
	info->size_b += 2;
	push_a(lst_a, &lst_b, info, data);
	free(data);
	return (1);
}
