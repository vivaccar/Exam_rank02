/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:34:30 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/27 16:09:56 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	n_len(int n)
{
	int	s = 0;
	
	if (n < 0)
		s++;
	while (n)
	{
		n = n / 10;
		s++;
	}
	return(s);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		size;
	
	
	if (nbr == -2147483648)
		return ("-2147483648\0");
	size = n_len(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (nbr == 0)
	{
		str[0] = '0';
		return(str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[--size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return(str);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int n = atoi(argv[1]);
		char *str = ft_itoa(n);
		printf("%s", str);
	}
}