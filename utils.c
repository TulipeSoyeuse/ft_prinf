/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:14:09 by rdupeux           #+#    #+#             */
/*   Updated: 2023/11/13 11:09:26 by rdupeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_hexa(unsigned long long nb, char *base)
{
	static int	count = 0;

	if (nb > 16)
	{
		putnbr_hexa(nb / ft_strlen(base), base);
		putnbr_hexa(nb % ft_strlen(base), base);
	}
	else
	{
		write(1, &base[nb], 1);
		count++;
	}
	return (count);
}

static char	*reverse(char *tmp, int end)
{
	char	*res;
	int		i;

	res = ft_calloc(end + 2, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (end > -1)
		res[i++] = tmp[end--];
	return (res);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	temp[11];
	char	*res;
	int		i;

	i = 0;
	if (n == 0)
	{
		res = ft_calloc(2, 1);
		res[0] = '0';
		return (res);
	}
	while (n)
	{
		temp[i++] = 48 + (n % 10);
		n /= 10;
	}
	return (reverse(temp, i - 1));
}
