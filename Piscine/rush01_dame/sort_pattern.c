void	p_swap(int **a, int **b)
{
	int	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int **arr, int low, int high)
{
	int	*pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j][0] < pivot[0]
			|| (arr[j][0] == pivot[0] && arr[j][1] < pivot[1]))
		{
			i++;
			p_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	p_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int **arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

void	sort_pattern(int **dic, int pattern_count)
{
	quick_sort(dic, 0, pattern_count - 1);
}
