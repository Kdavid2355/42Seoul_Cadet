/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beomjuki <beomjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:19:52 by beomjuki          #+#    #+#             */
/*   Updated: 2023/03/31 17:03:50 by beomjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **ans)
{
	size_t	i;

	i = 0;
	while (ans[i])
	{
		free(ans[i]);
		i++;
	}
	free(ans);
	return (NULL);
}

static char	*ft_makeword(char *s, char c)
{
	size_t	len;
	char	*word;
	char	*str;
	size_t	i;

	i = 0;
	len = 0;
	str = s;
	while (str[i] != c && str[i] != '\0' )
	{
		len++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_word(char *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ans = (char **)malloc(sizeof(char *) * (count_word((char *)s, c) + 1));
	if (!ans)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			ans[j] = ft_makeword((char *)&s[i], c);
			if (!ans[j])
				return (ft_malloc_error(ans));
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	ans[j] = NULL;
	return (ans);
}
