/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 08:52:00 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/23 14:50:28 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		tempo;
	t_list	*parcour;

	parcour = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			tempo = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tempo;
			lst = parcour;
		}
		else
			lst = lst->next;
	}
	lst = parcour;
	return (lst);
}

