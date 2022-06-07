/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:10:12 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/04 15:25:20 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print(t_list *lst, int max, int min)
{
	if (lst && lst->content == max)
		ft_printf("%d", lst->content);
	else if (lst && lst->content == min)
		ft_printf("%d", lst->content);
	else if (lst)
		ft_printf("%d ", lst->content);
}

void	init_max(t_list *lst, int *max, int *min)
{
	*max = find_max(lst, -2147483648);
	*min = find_min(lst);
}

static void	a_if(t_list *lst_a)
{
	if (lst_a && lst_a->content / 10)
		ft_putstr_fd("\t\t", 1);
	else
		ft_putstr_fd("\t\t\t", 1);
}

void	visualizer(t_list *lst_a, t_list *lst_b)
{
	int	i;
	int	max_a;
	int	max_b;
	int	min_a;
	int	min_b;

	i = 0;
	if (lst_a)
		init_max(lst_a, &max_a, &min_a);
	if (lst_b)
		init_max(lst_b, &max_b, &min_b);
	while (lst_a || lst_b)
	{
		ft_printf("Position %d -> ", i++);
		print(lst_a, max_a, min_a);
		a_if(lst_a);
		print(lst_b, max_b, min_b);
		ft_putchar_fd('\n', 1);
		if (lst_a)
			lst_a = lst_a->next;
		if (lst_b)
			lst_b = lst_b->next;
	}
	ft_putstr_fd("\n\n", 1);
}
