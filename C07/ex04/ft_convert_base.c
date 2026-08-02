/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 11:07:53 by idouiri           #+#    #+#             */
/*   Updated: 2026/07/26 18:41:02 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);
int	is_valid_base(char *base);

void	ft_getnbr_base(char *buffer, int len, int nbr, char *base)
{
	unsigned int	base_len;
	long			unbr;

	base_len = ft_strlen(base);
	buffer[--len] = '\0';
	unbr = nbr;
	if (nbr < 0)
	{
		buffer[0] = '-';
		unbr *= -1;
	}
	if (unbr == 0)
		buffer[--len] = base[0];
	while (unbr > 0)
	{
		buffer[--len] = base[unbr % base_len];
		unbr /= base_len;
	}
}

int	get_nbr_len_base(long nbr, int base_len)
{
	int	len;

	if (nbr < base_len)
		return (1);
	len = 1;
	return (len + get_nbr_len_base(nbr / base_len, base_len));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec_nbr;
	int		output_len;
	long	abs_dec_nbr;
	char	*output;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	dec_nbr = ft_atoi_base(nbr, base_from);
	abs_dec_nbr = dec_nbr;
	if (dec_nbr < 0)
		abs_dec_nbr *= -1;
	output_len = get_nbr_len_base(abs_dec_nbr, ft_strlen(base_to));
	if (dec_nbr < 0)
		output_len++;
	output_len++;
	output = malloc(output_len);
	if (output == NULL)
		return (NULL);
	ft_getnbr_base(output, output_len, dec_nbr, base_to);
	return (output);
}
