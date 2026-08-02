/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 18:21:15 by idouiri           #+#    #+#             */
/*   Updated: 2026/07/26 18:38:40 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int	is_valid_base(char *base)
{
	int	history[256];
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (i < 256)
	{
		history[i] = 0;
		i++;
	}
	while (*base)
	{
		if (*base == '+' || *base == '-'
			|| *base <= ' ' || *base == 127)
			return (0);
		if (history[(unsigned char)(*base)] == 1)
			return (0);
		history[(unsigned char)(*base)] = 1;
		base++;
	}
	return (1);
}

int	ft_find_char(char needle, char *haystack)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (needle == haystack[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	base_len = ft_strlen(base);
	if (!is_valid_base(base) || base_len < 2)
		return (0);
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && ft_find_char(*str, base) != -1)
	{
		res = res * base_len + ft_find_char(*str, base);
		str++;
	}
	return ((int)(res * sign));
}
