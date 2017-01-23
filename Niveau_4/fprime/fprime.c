/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:17:23 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/17 13:28:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int i;
	int num;

	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num == 1)
		{
			printf("1");
			return (0);
		}
		while (1)
		{
			i = 2;
			while (i <= num)
			{
				if (num % i == 0)
				{
					printf("%d", i);
					num /= i;
					break ;
				}
				i++;
			}
			if (num == 1)
				break ;
			else
				printf("*");
		}
	}
	printf("\n");
	return (0);
}
