/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:04:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/23 17:37:19 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_space(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		ft_count(char *s)
{
	int	sep;
	int	count;

	sep = 0;
	count = 0;
	while (*s != '\0')
	{
		if (sep == 1 && ft_space(*s))
			sep = 0;
		if (sep == 0 && !ft_space(*s))
		{
			sep = 1;
			count++;
		}
		s++;
	}
	return (count);
}

int		ft_strlen_sep(char *s)
{
	int i;

	i = 0;
	while (s[i] && !ft_space(s[i]))
		i++;
	return (i);
}

char	*ft_strsub(char *s, int start, int len)
{
	char	*tab;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(tab = (char *)malloc(sizeof(*tab) * (len + 1))))
		return (NULL);
	while (s[start] != '\0' && len--)
	{
		tab[i] = s[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		i;
	int		words;
	int		len;

	if (!str)
		return (NULL);
	i = 0;
	words = ft_count(str);
	if (!(tab = (char**)malloc(sizeof(*str) * words + 1)))
		return (NULL);
	while (words--)
	{
		while (*str && ft_space(*str))
			str++;
		len = ft_strlen_sep(str);
		tab[i] = ft_strsub(str, 0, len);
		if (tab[i] == '\0')
			return (NULL);
		str += ft_strlen_sep(str);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
