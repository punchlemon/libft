#include <stdlib.h>

void	make_dic_index(int ***dic_index, int **dic, int size)
{
	int	left;
	int	right;
	int	i;
	int	j;

	*dic_index = (int **)malloc(sizeof(int *) * size * size);
	if (*dic_index == NULL)
		exit(1);
	left = 1;
	i = 0;
	j = 0;
	while (left <= size)
	{
		right = 1;
		while (right <= size)
		{
			while (dic[j][0] == left && dic[j][1] == right)
				j++;
			if (dic[j][0] == left && dic[j][1] == right)
				(*dic_index)[i] = dic[j];
			else
				(*dic_index)[i] = (void *)0;
			i++;
			right++;
		}
		left++;
	}
}
