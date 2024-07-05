/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:29:40 by kagoh             #+#    #+#             */
/*   Updated: 2024/05/23 18:12:57 by kagoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

/*int main(void)
{
    // Test case 1: Normal string
    const char *str1 = "Hello, World!";
    size_t len1_std = strlen(str1);
    size_t len1_custom = ft_strlen(str1);
    printf("Test case 1:\nExpected: %zu\nGot: %zu\nResult: %s\n\n",
           len1_std, len1_custom, (len1_std == len1_custom) ? "Pass" : "Fail");

    // Test case 2: Empty string
    const char *str2 = "";
    size_t len2_std = strlen(str2);
    size_t len2_custom = ft_strlen(str2);
    printf("Test case 2:\nExpected: %zu\nGot: %zu\nResult: %s\n\n",
           len2_std, len2_custom, (len2_std == len2_custom) ? "Pass" : "Fail");

    // Test case 3: String with spaces
    const char *str3 = "OpenAI GPT-4";
    size_t len3_std = strlen(str3);
    size_t len3_custom = ft_strlen(str3);
    printf("Test case 3:\nExpected: %zu\nGot: %zu\nResult: %s\n\n",
           len3_std, len3_custom, (len3_std == len3_custom) ? "Pass" : "Fail");

    // Test case 4: String with special characters
    const char *str4 = "Hello\nWorld!";
    size_t len4_std = strlen(str4);
    size_t len4_custom = ft_strlen(str4);
    printf("Test case 4:\nExpected: %zu\nGot: %zu\nResult: %s\n\n",
           len4_std, len4_custom, (len4_std == len4_custom) ? "Pass" : "Fail");

    // Test case 5: String with only special characters
    const char *str5 = "@#$%^&*()!";
    size_t len5_std = strlen(str5);
    size_t len5_custom = ft_strlen(str5);
    printf("Test case 5:\nExpected: %zu\nGot: %zu\nResult: %s\n\n",
           len5_std, len5_custom, (len5_std == len5_custom) ? "Pass" : "Fail");

    return 0;
}
*/