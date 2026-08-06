/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:11:10 by zoualmam          #+#    #+#             */
/*   Updated: 2026/08/06 21:14:15 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_check(char *base);

int	check_len(long nb, char *base_to)
{
	int	i;
	int	base;

	i = 0;
	base = ft_check(base_to);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char	*ft_fill(char *s, char *base_to)
{
	s[0] = base_to[0];
	s[1] = '\0';
	return (s);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long		nb;
	int			len_nb;
	char		*st;

	nb = ft_atoi_base(nbr, base_from);
	len_nb = check_len(nb, base_to);
	if (ft_check(base_to) == 0 || ft_check(base_from) == 0)
		return (NULL);
	st = malloc((len_nb + 1) * sizeof(char));
	if (st == NULL)
		return (NULL);
	if (nb == 0)
		return (ft_fill(st, base_to));
	if (nb < 0)
	{
		nb = -nb;
		st[0] = '-';
	}
	st[len_nb--] = '\0';
	while (nb != 0)
	{
		st[len_nb--] = base_to[nb % ft_check(base_to)];
		nb = nb / ft_check(base_to);
	}
	return (st);
}
