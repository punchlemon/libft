int	*add(int *list1, int *list2)
{
	int	list1_len;
	int	list2_len;
	int	total_len
	int	*result;
	int	i;

	list1_len = sizeof(list1) / sizeof(int);
	list2_len = sizeof(list2) / sizeof(int);
	total_len = list1_len + list2_len;
	result = (int *)malloc(sizeof(int) * (total_len));
	if (result != NULL)
	{
		i = 0;
		while (i < list1_len)
		{
			result[i] = list1[i];
			i++;
		}
		while (i < total_len)
		{
			result[i] = list2[i];
			i++;
		}
		free(list1);
		free(list2);
	}
	return (result);
}

int	*add_one(int *list, int num)
{
	int	list_size;
	int	*result;
	int	i;

	if (list == NULL)
		list_size = 0;
	list_size = sizeof(list) / sizeof(int);
	result = (int *)malloc(sizeof(int) * (list_size + 1));
	result[list_size] = num;
	if (result != NULL)
	{
		i = 0;
		while (i < list_size)
		{
			result[i] = list[i];
			i++;
		}
	}
	free(list);
	return (result);
}

int	insert_num(int *list, int num)
{

}

int	check_num_count_under(int num)
{
	int	nums[3];
	int	count;
	int	result[4];

	nums[2] = num % 10;
	nums[1] = (num / 10) % 10
	nums[0] = num / 100;
	count = 0;
	if (nums[0] != 0)
		count += 2;
	if (nums[1] != 0 && nums[1] != 1)
	{
		count++;
		if (nums[2] != 0)
			count++;
	}
	else if (nums[1] == 1)
		count++;
}

int	check_num_count(int i)
{
	if (i > 1000)
		check_num_count(i / 1000);
	
}

int *itonums(int i)
{
	if (i == 0)
		return ({0});
	if (i > 1000)
		itonums(i / 1000);
}