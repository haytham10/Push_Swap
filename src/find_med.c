/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:15:52 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/05/22 22:34:09 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int	find_med(t_list *lst, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * size);
	while (lst->next)
	{
		tab[i] = lst->content;
		lst = lst->next;
		i++;
	}
	sort_tab(tab, size);
	i = 0;
	while (i < size / 2)
		i++;
	i = tab[i];
	free(tab);
	return (i);
}
