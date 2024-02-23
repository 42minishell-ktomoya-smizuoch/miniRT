/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:31:31 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/03 12:10:37 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	bytes = count * size;
	if (bytes / size != count)
		return (NULL);
	ptr = malloc(bytes);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, bytes);
	return (ptr);
}

/* int main()
{
    int count = 5;
    int *arr;

    arr = (int*)ft_calloc(count, sizeof(int));
    if (arr == NULL) {
        printf("ft_calloc failed to allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
} */