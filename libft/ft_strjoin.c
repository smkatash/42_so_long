/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:56:11 by ktashbae          #+#    #+#             */
/*   Updated: 2022/04/25 12:30:43 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_path(char const *s1, char c, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[n])
		str[i++] = s1[n++];
	str[i++] = c;
	n = 0;
	while (s2[n])
		str[i++] = s2[n++];
	str[i] = '\0';
	return (str);
}
