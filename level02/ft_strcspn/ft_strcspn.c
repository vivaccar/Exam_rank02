/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:36:03 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/27 16:56:41 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include <stdio.h>

size_t	checking(char c, const char *reject)
{
	int	i = 0;

	while (reject[i])
	{
		if (reject[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i = 0;
	
	while (s[i])
	{
		if (checking(s[i], reject) == 1)
			return (i);
		i++;
	}
	return (i);
}

/* int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%zu", ft_strcspn(argv[1], argv[2]));
	}
} */