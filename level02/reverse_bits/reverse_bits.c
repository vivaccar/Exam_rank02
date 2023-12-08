/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:13:53 by vivaccar          #+#    #+#             */
/*   Updated: 2023/12/05 20:40:16 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int				i = 8;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

unsigned char	reverse_bits2(unsigned char octet)
{
	unsigned char	rev = 0;
	int				i = 8;

	while (i > 0)
	{
		rev = rev << 1;
		rev = rev | (octet & 1);
		octet = octet >> 1;
		i--;
	}
	return (rev);
}

int	main(void)
{
	unsigned char r = reverse_bits2(1);
	printf("%u\n", r);
	r = reverse_bits(1);
	printf("%u", r);
}