/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivaccar <vivaccar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:38:28 by vivaccar          #+#    #+#             */
/*   Updated: 2023/11/27 15:34:09 by vivaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_words(char *str)
{
	int	i = 0;
	int	c = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			c++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (c);
}

char	**ft_split(char	*str)
{
	int		cw;
	char	**result;
	int		i = 0;
	int		j = 0;
	int		k = 0;

	cw = ft_words(str);
	result = (char **)malloc((sizeof(char *)) * (cw + 1));
	while (str[i])
	{
		while ((str[i]) && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while ((str[i]) && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			result[k] = (char *)malloc(sizeof(char) * (i - j + 1));
			ft_strncpy(result[k], &str[j], i - j);
			k++;
		}
	}
	result[k] = NULL;
	return(result);
}

int	main(int argc, char *argv[])
{
	char	**result;
	int		i = 0;
	
	if (argc == 2)
	{
		result = ft_split(argv[1]);
		while (result[i])
		{
			printf("%s", result[i]);
			printf("\n");
			i++;
		}
	}
}