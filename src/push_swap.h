/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:48:20 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/06 23:45:37 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define MIN_INT -2147483648

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	int	pivot;
	int	size_b;
	int	size_a;
	int	flags;
	int	vis;
}	t_info;

typedef struct s_data
{
	int	max_a;
	int	max_b;
	int	flags_a;
	int	flags_b;
	int	pos_a;
	int	pos_b;
}	t_data;

t_list	*create_lst(int ac, char **av, t_info **info);
void	visualizer(t_list *lst_a, t_list *lst_b);
void	init_max(t_list *lst, int *max, int *min);
int		find_max(t_list *lst, int skip);
int		find_min(t_list *lst);
int		find_size(t_list *lst);
int		resolve(t_list **lst_a, t_info *info);
int		find_med(t_list *lst, int size);
int		find_pos(int n, t_list *lst);
void	sort_tab(int *tab, int n);
int		is_sort(t_list *lst_a);
void	sa(t_list *lst_a, t_list *lst_b, int p);
void	sb(t_list *lst_a, t_list *lst_b, int p);
void	ss(t_list *lst_a, t_list *lst_b, int p);
void	pa(t_list **lst_a, t_list **lst_b, int p);
void	pb(t_list **lst_a, t_list **lst_b, int p);
void	ra(t_list **lst_a, t_list **lst_b, int p);
void	rb(t_list **lst_a, t_list **lst_b, int p);
void	rr(t_list **lst_a, t_list **lst_b, int p);
void	rra(t_list **lst_a, t_list **lst_b, int p);
void	rrb(t_list **lst_a, t_list **lst_b, int p);
void	rrr(t_list **lst_a, t_list **lst_b, int p);
void	push_a(t_list **lst_a, t_list **lst_b, t_info *info, t_data *data);
void	push_b(int size, t_list **lst_a, t_list **lst_b, t_info *info);
void	short_resolve(t_list **lst_a, t_info *info);
int		free_all(t_list *lst, t_info *info);
void	free_lst(t_list *lst);
void	add_link(t_list **lst, int n);
int		get_a(t_data *data, t_list **lst_b, int s);
void	sort_five(t_list **lst_a, t_list **lst_b, t_info *info);
char	*get_next_line(int fd);
void	check2(t_list **lst_a, t_list **lst_b, char *str);
void	check(t_list **lst_a, t_list **lst_b);

#endif