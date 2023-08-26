#include <stdlib.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	make_pattern(int **dic, int *pattern, int current_pos, int end_pos)
{
	int			i;
	static int	index; // 初期値は0

	if (current_pos == end_pos) // 現在の配列を二次元配列にコピーします
	{
		dic[index][0] = 0;
		dic[index][1] = 0;
		i = 0;
		while (i < end_pos)
		{
			dic[index][i + 2] = pattern[i];
			i++;
		}
		(index)++;
		return ;
	}
	i = current_pos;
	while (i < end_pos)
	{
		swap(&pattern[i], &pattern[current_pos]);
		make_pattern(dic, pattern, current_pos + 1, end_pos);
		swap(&pattern[i], &pattern[current_pos]); // 配列を元に戻します
		i++;
	}
}

void	set_num(int **dic, int max)
{
	int	*pattern;
	int	i;

	pattern = (int *)malloc(max * sizeof(int));
	if (pattern == NULL)
		exit(1);
	i = 0;
	while (i < max)
	{
		pattern[i] = i + 1;
		i++;
	}
	make_pattern(dic, pattern, 0, max);
	free(pattern);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	max = 4;
// 	int **dic = malloc(sizeof(int*) * 24); // maxの階乗個の順列がある
// 	for (int i = 0; i < 24; i++) {
// 		dic[i] = malloc(sizeof(int) * (max + 2)); // 配列サイズをmax + 2に変更
// 	}

// 	set_num(dic, max);

// 	for (int i = 0; i < 24; i++) {
// 		for (int j = 0; j < max + 2; j++) { // インデックスをmax + 2まで繰り返すように変更
// 			printf("%d ", dic[i][j]);
// 		}
// 		printf("\n");
// 		free(dic[i]); // メモリを解放します
// 	}
// 	free(dic); // メモリを解放します
// 	return 0;
// }