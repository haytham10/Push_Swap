/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:52:35 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/07 02:16:09 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker(char *str, int i)
{
	int	j;

	j = ft_strlen(str);
	if (str[j - 1] == '+' || str[j - 1] == '-')
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	if (((!ft_isdigit(str[i]) && (str[i] != '-' && str[i] != '+'))
			|| (str[i] == '-' && (!ft_isdigit(str[i + 1]))) || ((str[i] == '-'
					|| str[i] == '+') && (str[i + 1] == '+'
					|| str[i + 1] == '-'))))
		return (0);
	return (1);
}

static int	check_arg(char *str, int i)
{
	int	len;

	while (str[i])
	{
		len = 0;
		if (checker(str, i) == 0)
			return (0);
		while (ft_isdigit(str[i]))
		{
			len++;
			if (len == 10 && ((str[i] > '7' || ft_isdigit(str[i + 1]))
					&& str[i - len] != '-'))
				return (0);
			if (len == 10 && ((str[i] > '8' || ft_isdigit(str[i + 1]))
					&& str[i - len] == '-'))
				return (0);
			i++;
		}
		if (((str[i] == ' ' || ((str[i] == '-') && ft_isdigit(str[i + 1]))
					|| ((str[i] == '+') && ft_isdigit(str[i + 1])))
				&& str[i + 1]))
			i++;
	}
	return (1);
}

static int	check_dup(t_list *lst)
{
	int		n;
	t_list	*tmp;

	n = lst->content;
	tmp = lst;
	while (lst->next)
	{
		lst = lst->next;
		if (lst->content == n)
			return (0);
	}
	if (tmp->next)
		if (!(check_dup(tmp->next)))
			return (0);
	return (1);
}

static t_list	*fill_lst(t_info *info, t_list *lst, int ac, char **av)
{
	int	i;
	int	j;

	if (info->vis == 2)
		i = 2;
	else
		i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			add_link(&lst, ft_atoi(&av[i][j]));
			while (ft_isdigit(av[i][j]) || av[i][j] == '-'
					|| av[i][j] == '+' || (av[i][j - 1] == '-'
					&& av[i][j] == 'v'))
				j++;
			if (av[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (lst);
}

t_list	*create_lst(int ac, char **av, t_info **info)
{
	t_list	*lst;
	int		i;

	i = 1;
	lst = NULL;
	if (av[i][0] == '-' && av[i][1] == 'v')
	{
		(*info)->vis = 2;
		i++;
	}
	while (i < ac)
	{
		if (!(check_arg(av[i], 0)) || !av[1][0])
			return (0);
		i++;
	}
	lst = fill_lst(*info, lst, ac, av);
	if (!(check_dup(lst)))
	{
		free_lst(lst);
		return (NULL);
	}
	return (lst);
}
