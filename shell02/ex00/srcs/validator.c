/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:45:23 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 15:10:58 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	*trim_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	return (&str[i]);
}
