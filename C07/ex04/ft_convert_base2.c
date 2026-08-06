/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:10:46 by zoualmam          #+#    #+#             */
/*   Updated: 2026/08/06 21:14:36 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char *base)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
		i++;
	if (i < 2)
		return (0);
	while (base[j])
	{
		k = j + 1;
		if (base[j] == 32 || (base[j] >= 9 && base[j] <= 13)
			|| base[j] == 43 || base[j] == 45)
			return (0);
		while (base[k])
		{
			if (base[j] == base[k])
				return (0);
			k++;
		}
		j++;
	}
	return (i);
}

int	ft_skip(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			return (i);
	}
	return (i);
}

int	ft_index(char s, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == s)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	ind;
	int	nb;

	j = 1;
	nb = 0;
	i = ft_skip(str);
	if (ft_check(base) == 0)
		return (0);
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			j = -j;
		i++;
	}
	while (str[i])
	{
		ind = ft_index(str[i], base);
		if (ind == -1)
			break ;
		nb = nb * ft_check(base) + ind;
		i++;
	}
	return (nb * j);
}
