/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:11:46 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/23 14:11:46 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count = 1;
		return (count);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			count++;
		}
		while (n != 0)
		{
			count++;
			n /= 10;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		length;
	char	*result;
	long	number;
	int		i;

	length = num_length(n);
	i = length - 1;
	number = n;
	result = malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	if (number == 0)
		result[0] = '0';
	else if (number < 0)
	{
		result[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		result[i--] = number % 10 + '0';
		number /= 10;
	}
	return (result);
}

/*int	main(void)
{
	int numbers[] = {123, -456, 0, 2147483647, -2147483648};
	char *result;

	for (int i = 0; i < 5; i++)
	{
		result = ft_itoa(numbers[i]);
		printf("Integer: %d -> String: %s\n", numbers[i], result);
		free(result);
	}

	return (0);
}
*/