/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 09:54:46 by ktashbae          #+#    #+#             */
/*   Updated: 2022/05/16 16:10:32 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_update_line(char *str)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = ft_strlen(str);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_join_lines(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*holder;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	holder = (char *)malloc(sizeof(char) * (len1 + len2));
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		holder[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\n' && s2[i] != '\0')
	{
		holder[len1] = s2[i];
		i++;
		len1++;
	}
	holder[len1] = '\0';
	free(s1);
	free(s2);
	return (holder);
}

void	check_input_type(char ch, char const *type, t_render *game)
{
	int	i;
	int	match;

	i = 0;
	match = 0;
	while (type[i] != '\0')
	{
		if (type[i] == ch)
			match++;
		i++;
	}
	if (match <= 0)
		ft_perror("Undefined character!\n", game);
}
