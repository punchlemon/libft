/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:24:57 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/27 11:36:23 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	array_len(int *list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	add(int **result, int *list2)
{
	int	total_len;
	int	*list1;
	int	*temp;
	int	i;
	int	list1_end;

	list1 = *result;
	if (list1 != NULL && list2 != NULL)
	{
		total_len = array_len(list1) + array_len(list2);
		temp = (int *)malloc(sizeof(int) * (total_len + 1));
		if (temp != NULL)
		{
			i = -1;
			while (++i < (array_len(list1)))
				temp[i] = list1[i];
			list1_end = i;
			i = -1;
			while (++i < (array_len(list2)))
				temp[list1_end + i] = list2[i];
			temp[total_len] = 0;
			free(list1);
			free(list2);
		}
	}
	*result = temp;
}

int	*ft_mal(int i)
{
	int	*result;

	result = (int *)malloc(sizeof(int) * 2);
	if (result != NULL)
	{
		result[0] = i;
		result[1] = 0;
	}
	return (result);
}

int	insert_num(int *list, int num)
{
	return (0);
}

int	*under_num(int num)
{
	int	nums[3];
	int	temp[4];
	int	i;
	int	*result;

	i = 0;
	nums[0] = num % 10;
	nums[1] = (num / 10) % 10;
	nums[2] = num / 100;
	result = ft_mal(0);
	if (nums[2] != 0)
	{
		add(&result, ft_mal(nums[2]));
		add(&result, ft_mal(100));
	}
	if (nums[1] != 0 && nums[1] != 1)
	{
		add(&result, ft_mal(nums[1] * 10));
		if (nums[0] != 0)
			add(&result, ft_mal(nums[0]));
	}
	else if (nums[1] == 1)
		add(&result, ft_mal(10 + nums[0]));
}

int	div_thou(int num)
{
	int	*mae;
	int	*ato;

	if (num > 1000)
		div_thou(num / 1000);
	return (0);
}

int	*split_num(int num)
{
	int	*result;

	result = NULL;
	if (num == 0)
	{
		result = (int *)malloc(sizeof(int) * 1);
		if (result != NULL)
			result[0] = 0;
	}
	else
	{
	}
	return (NULL);
}

#include <stdio.h>
#include <unistd.h>
int	main(){
	int *a;
	int *b;
	int j;

	a = (int *)malloc(sizeof(int) * 4);
	for (int i = 0; i < 3; i++)
		a[i] = i + 1;
	a[3] = 0;
	b = (int *)malloc(sizeof(int) * 4);
	for (int i = 0; i < 3; i++)
		b[i] = i + 3;
	b[3] = 0;
	j = 0;
	while (b[j])
	{
		printf("%d ", b[j]);
		j++;
	}
	add(&a, b);
	j = 0;
	while (a[j])
	{
		printf("%d ", a[j]);
		j++;
	}
}
