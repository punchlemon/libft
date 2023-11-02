#include <unistd.h>

int	check_line(int map[4][4], int row, int col, int value);
int	solve(int map[4][4], int constraints[16], int pos);

void	print_map(int map[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = map[i][j] + '0';
			write(1, &c, 1);
			if (j != 4 - 1)
				write(1, " ", 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}
// mapを出力する

void	initialize_map(int map[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}
// mapを初期化, すべてのメモリに0を代入
// これが抜けてしまったため、mapにもともと入っているゴミデータと比較し、
// Errorを吐くようになっていた。

int	initialize_constraints(char *arg, int constraints[16])
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (arg[i * 2] < '1' || arg[i * 2] > '4'
			|| (i < 15 && arg[i * 2 + 1] != ' '))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		constraints[i] = arg[i * 2] - '0';
		i++;
	}
	return (0);
}
// 制約条件は、コマンドライン引数から、char型の配列として渡される
// それをint型の配列に格納する
// もし、1~4の数字でない||数字と数字の間にスペースが入っていない場合、エラーを吐く

int	main(int argc, char **argv)
{
	int	map[4][4];
	int	constraints[16];

	initialize_map(map);
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (initialize_constraints(argv[1], constraints))
		return (1);
	if (solve(map, constraints, 0))
		print_map(map);
	else
		write(1, "Error\n", 6);
	return (0);
}
// 解を保存する二次元配列mapと、制約条件を保存する配列constraintsを宣言
// mapを初期化
// コマンドライン引数が2つ（実行ファイルを除いて1つ）以外の場合、エラーを吐き、プログラムを終了
// initialize_constraints関数で、constraintsを初期化、エラーが返ってきた場合、プログラムを終了
// solve関数で、        
// solve関数が正常終了した場合、print_map関数で、解を出力
// solve関数が異常終了した場合、エラーを吐く
// プログラムを終了