/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:48:23 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/07 02:18:38 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_algo(t_list **lst_a, t_info *info)
{
	if (find_size(*lst_a) > 8)
	{
		if (!(resolve(lst_a, info)))
			return (0);
	}
	else
		short_resolve(lst_a, info);
	if (info->vis == 2)
	{
		ft_printf("Sort stack : \n\n");
		visualizer(*lst_a, 0);
		ft_printf("End of Visualization\n");
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_info	*info;

	if (ac < 2 || (ac < 3 && !ft_strncmp(av[1], "-v", 2)))
		return (0);
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->vis = 1;
	lst_a = create_lst(ac, av, &info);
	if (!lst_a)
	{
		free(info);
		return (write (2, "Error\n", 6));
	}
	if (info->vis == 2)
	{
		ft_putstr_fd("Starting Visualization... \n\nStart Stack : \n\n", 1);
		visualizer(lst_a, 0);
	}
	find_algo(&lst_a, info);
	free_lst(lst_a);
	free(info);
	return (0);
}
