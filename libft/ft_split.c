/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrenton <sbrenton@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 23:07:04 by sbrenton          #+#    #+#             */
/*   Updated: 2020/11/09 23:07:04 by sbrenton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_protect(char **res, int w)
{
	while (w >= 0)
	{
		free(res[w]);
		w--;
	}
	free(res);
	return (NULL);
}

static int			ft_wrd(char const *s, char c)
{
	int		n;
	int		words;

	n = 0;
	words = 0;
	while (s[n] != '\0')
	{
		while (s[n] != '\0' && s[n] == c)
			n++;
		if (s[n] != '\0')
		{
			words++;
			n++;
			while (s[n] != '\0' && s[n] != c)
				n++;
		}
	}
	return (words);
}

static int			ft_strt(char const *s, char c, int word)
{
	int		n;
	int		words;

	n = 0;
	words = 0;
	while (s[n] != '\0')
	{
		while (s[n] != '\0' && s[n] == c)
			n++;
		if (s[n] != '\0')
		{
			words++;
			if (words == word)
				return (n);
			n++;
			while (s[n] != '\0' && s[n] != c)
				n++;
		}
	}
	return (-1);
}

static int			ft_end(char const *s, char c, int word)
{
	int		n;
	int		words;

	n = 0;
	words = 0;
	while (s[n] != '\0')
	{
		while (s[n] != '\0' && s[n] == c)
			n++;
		if (s[n] != '\0')
		{
			words++;
			n++;
			while (s[n] != '\0' && s[n] != c)
				n++;
			if (words == word)
				return (n);
		}
	}
	return (-1);
}

char				**ft_split(char const *s, char c)
{
	int		n;
	int		w;
	char	**res;
	int		start;
	int		end;

	if (!s || !(res = (char**)malloc(sizeof(char*) * (ft_wrd(s, c) + 1))))
		return (NULL);
	w = -1;
	while (++w < ft_wrd(s, c))
	{
		start = ft_strt(s, c, w + 1);
		end = ft_end(s, c, w + 1);
		if (!(res[w] = (char*)malloc(sizeof(char) * (end - start + 1))))
			return (ft_protect(res, w));
		n = 0;
		while (start + n < end)
		{
			res[w][n] = s[start + n];
			n++;
		}
		res[w][n] = '\0';
	}
	res[w] = NULL;
	return (res);
}
