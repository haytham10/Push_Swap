/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:20:16 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/06 23:39:14 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_link(t_list **lst, int n)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *lst;
	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = n;
		new->next = NULL;
		if (*lst)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
		{
			*lst = new;
			return ;
		}
	}
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp)
			free(tmp);
	}
	lst = NULL;
}

int	free_all(t_list *lst, t_info *info)
{
	free_lst(lst);
	free(info);
	ft_putendl_fd("Error", 2);
	return (0);
}
