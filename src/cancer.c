/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmokhtar <hmokhtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:59:43 by hmokhtar          #+#    #+#             */
/*   Updated: 2022/06/03 20:00:02 by hmokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_a(t_data *data, t_list **lst_b, int s)
{
	if (s == 1)
		return (data->pos_a = find_pos(data->max_b, *lst_b));
	else
		return (data->pos_b = find_pos(data->max_a, *lst_b));
}
