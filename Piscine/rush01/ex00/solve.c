int	check_up(int map[4][4], int j);
int	check_down(int map[4][4], int j);
int	check_left(int map[4][4], int j);
int	check_right(int map[4][4], int j);

int	check_select(int i, int map[4][4], int j)
{
	int	count;

	count = 0;
	if (i == 0)
		count = check_up(map, j);
	else if (i == 1)
		count = check_down(map, j);
	else if (i == 2)
		count = check_left(map, j);
	else if (i == 3)
		count = check_right(map, j);
	return (count);
}
// どの方向からチェックするかは引数iで操作する
// 引数jはその方向の中で何番目の列or行をチェックするかを指示している

int	check_constraints(int map[4][4], int *constraints)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			count = check_select(i, map, j);
			if (constraints[i * 4 + j] != count)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
// check_selectが返す現在のmapの状態から計算される制約の数字と
// 出題時に与えられている制約の数字が一致しているかどうかを確認し、一致していないものを見つけた瞬間に0を返す

int	check_line(int map[4][4], int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map[row][i] == value || map[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}
// その数字が縦方向と横方向で数字の被りがないかどうかをチェックする関数
// どこか一致しているところが一つでもあったら0を返す

int	solve(int map[4][4], int constraints[16], int pos)
{
	int	x;
	int	y;
	int	value;

	x = pos / 4;
	y = pos % 4;
	value = 1;
	if (pos == 4 * 4)
		return (check_constraints(map, constraints));
	while (value <= 4)
	{
		if (check_line(map, x, y, value))
		{
			map[x][y] = value;
			if (solve(map, constraints, pos + 1))
				return (1);
			map[x][y] = 0;
		}
		value++;
	}
	return (0);
}
// 引数posは、現在のmapのポジションを表している
// mapのポジションは、x軸、y軸を持っているが、2つの変数で管理するのは面倒なので、
// pos = (x * 4) + y の値でmapのポジションを管理する
// solve関数の初めに引数posを、x軸、y軸のポジションに変換する
// x = pos / 4
// y = pos % 4
// 再帰の終了条件として、posが16（4 x 4）に等しい場合、すべてのセルが埋まっているため、解の検証を行う
// そこで、check_constraints関数を呼び出して制約が満たされているかを確認し、結果を返す。
// もし、制約が満たされておらず、check_constraints関数でエラーが返ってきたら、
// 次の数字の組み合わせを試すはずだったけど、このコードでは再帰できていない。
// そのため、最初に作成したmapしか、制約条件をチェックできない
// valueは試行する値、1から4まで順番に、check_line関数を用いて、
// 現在の行と列に同じ数字がないか試して行き、mapを埋めて行く
// 最適な解が見つからない場合、whileを抜けたら、return (0)を返す