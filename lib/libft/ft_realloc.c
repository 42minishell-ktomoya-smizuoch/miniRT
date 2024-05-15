/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:00:07 by smizuoch          #+#    #+#             */
/*   Updated: 2024/05/15 13:28:53 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

// int	main()
// {
// 	int*	ptr;
// 	int	i;
// 	ptr = (int*)malloc(sizeof(int) * 5);
// 	if (ptr == NULL)
// 		return (1);
// 	for (i = 0; i < 5; i++)
// 		ptr[i] = i;
// 	ptr = (int*)ft_realloc(ptr, sizeof(int) * 10);
// 	if (ptr == NULL)
// 		return (1);
// 	for (i = 5; i < 10; i++)
// 		ptr[i] = i;
// 	for (i = 0; i < 10; i++)
// 		printf("%d\n", ptr[i]);
// 	free(ptr);
// 	printf ("---\n");
// 	ptr = (int*)malloc(sizeof(int) * 5);
// 	if (ptr == NULL)
// 		return (1);
// 	for (i = 0; i < 5; i++)
// 		ptr[i] = i;
// 	ptr = (int*)realloc(ptr, sizeof(int) * 10);
// 	if (ptr == NULL)
// 		return (1);
// 	for (i = 5; i < 10; i++)
// 		ptr[i] = i;
// 	for (i = 0; i < 10; i++)
// 		printf("%d\n", ptr[i]);
// 	free(ptr);
// }

//The problem occurs when the size 
// of the data to be copied is larger than new_size.
