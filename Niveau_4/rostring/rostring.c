/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:36:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/23 14:03:44 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	return (!*s ? 0 : 1 + ft_strlen(++s));
}

void	ft_putchar(int c)
{
	(void)write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	(void)write(1, s, ft_strlen(s));
}

int		ft_space(int c)
{
	return (c == ' ' || c == '\t');
}

void	ft_skipspace(char **s)
{
	while (**s && (**s == ' ' || **s == '\t'))
		(*s)++;
}

void	rostring(char *s)
{
	char	*first;

	ft_skipspace(&s);
	first = s;
	while (*s && !ft_space(*s))
		s++;
	if (ft_space(*s))
	{
		*s = '\0';
		s++;
	}
	ft_skipspace(&s);
	while (*s)
	{
		while (*s && !ft_space(*s))
			ft_putchar(*s++);
		ft_putchar(' ');
		ft_skipspace(&s);
	}
	ft_putstr(first);
}

int	main(int ac, char **av)
{
	if (ac >= 2)
		rostring(av[1]);
	ft_putchar('\n');
	return (0);
}
