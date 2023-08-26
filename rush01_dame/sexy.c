void	set_num(int **dic, int max);
void	set_left_right(int **dic, int pattern_count, int size);
void sort_pattern(int **dic, int pattern_count);

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	max = 3;
	int **dic = malloc(sizeof(int*) * 6); // maxの階乗個の順列がある
	for (int i = 0; i < 6; i++) {
		dic[i] = malloc(sizeof(int) * (max + 2)); // 配列サイズをmax + 2に変更
	}

	set_num(dic, max);
	set_left_right(dic, 6, max);
	sort_pattern(dic, 6);

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < max + 2; j++) { // インデックスをmax + 2まで繰り返すように変更
			printf("%d ", dic[i][j]);
		}
		printf("\n");
		free(dic[i]); // メモリを解放します
	}
	free(dic); // メモリを解放します
	return 0;
}