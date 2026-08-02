/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 10:58:24 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 18:25:53 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	skip_spaces(char **cursor)
{
	while (**cursor == ' ')
		(*cursor)++;
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putstr(char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	fill_with_zeros(char *buffer, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		buffer[i] = '0';
		i++;
	}
	buffer[i] = '\0';
}
