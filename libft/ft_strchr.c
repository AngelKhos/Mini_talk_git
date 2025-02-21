/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 07:22:04 by authomas          #+#    #+#             */
/*   Updated: 2024/11/16 09:02:43 by authomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == ((char)c))
			return (str);
		str++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}

/*int	main()
{
	char str[] = "je suis un test :D";
	printf("ft_strchr = '%s'",ft_strchr(str, '\0'));
}*/
