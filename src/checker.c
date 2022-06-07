/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:41:49 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/04 15:42:16 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_next_line(int fd)
{
	char	str[8000000];
	int		i;
	char	buff[1];
	int		byte;

	byte = read(fd, buff, 1);
	i = 0;
	while (byte > 0)
	{
		str[i++] = buff[0];
		if (buff[0] == '\n')
			break ;
		byte = read(fd, buff, 1);
	}
	str[i] = '\0';
	if (str[0] == '\0')
		return (0);
	return (ft_strdup(str));
}

void	check2(t_list **lst_a, t_list **lst_b, char *str)
{
	if (!ft_strncmp("pa\n", str, 3))
		pa(lst_a, lst_b, 0);
	else if (!ft_strncmp("rrr\n", str, 4))
		rrr(lst_a, lst_b, 0);
	else if (!ft_strncmp("ss\n", str, 3))
		ss(*lst_a, *lst_b, 0);
	else if (!ft_strncmp("rr\n", str, 3))
		rr(lst_a, lst_b, 0);
	else
		ft_putstr_fd("Error\n", 2);
}

void	check(t_list **lst_a, t_list **lst_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!ft_strncmp("rra\n", str, 4))
			rra(lst_a, lst_b, 0);
		else if (!ft_strncmp("ra\n", str, 3))
			ra(lst_a, lst_b, 0);
		else if (!ft_strncmp("sa\n", str, 3))
			sa(*lst_a, *lst_b, 0);
		else if (!ft_strncmp("rrb\n", str, 4))
			rrb(lst_a, lst_b, 0);
		else if (!ft_strncmp("rb\n", str, 3))
			rb(lst_a, lst_b, 0);
		else if (!ft_strncmp("sb\n", str, 3))
			sb(*lst_a, *lst_b, 0);
		else if (!ft_strncmp("pb\n", str, 3))
			pb(lst_a, lst_b, 0);
		else
			check2(lst_a, lst_b, str);
		str = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	lst_a = create_lst(ac, av, &info);
	if (lst_a == NULL)
		return (0);
	lst_b = NULL;
	if (ac < 2)
		return (0);
	if (!ft_isdigit(av[1][0]))
		ft_putendl_fd("Error", 2);
	check(&lst_a, &lst_b);
	if (is_sort(lst_a) && find_size(lst_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
