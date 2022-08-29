/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:52:31 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/04 08:17:11 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_letter_count(int i, char const *s, char c)
{
	int	p;
	int	let;
	int	size;

	p = 0;
	size = 0;
	while (size <= i && s[p])
	{
		let = 0;
		while (s[p] == c && s[p])
			p++;
		while (s[p] != c && s[p])
		{
			let++;
			p++;
		}
		size++;
	}
	return (let);
}

int	ft_word_count(char const *s, char c)
{
	int	i;
	int	word_len;

	i = 0;
	word_len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_len++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word_len);
}

char	**ft_free(char **arr, size_t p)
{
	size_t	i;

	i = 0;
	while (i < p)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	return (NULL);
}

char	**ft_ptrcpy(int i, char c, char *s, char **arr_p)
{
	int	j;
	int	ptr;

	ptr = 0;
	while (s[i] == c && s[i])
			i++;
	while (s[i])
	{
		j = 0;
		arr_p[ptr] = malloc(sizeof(char) * (ft_letter_count(ptr, s, c) + 1));
		if (!arr_p[ptr])
			return (ft_free(arr_p, ptr));
		while (s[i] != c && s[i])
			arr_p[ptr][j++] = s[i++];
		while (s[i] == c && s[i])
			i++;
		arr_p[ptr][j] = '\0';
		ptr++;
	}
	arr_p[ptr] = 0;
	return (arr_p);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	arr_p = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!arr_p)
		return (NULL);
	arr_p = ft_ptrcpy(i, c, (char *)s, arr_p);
	return (arr_p);
}
