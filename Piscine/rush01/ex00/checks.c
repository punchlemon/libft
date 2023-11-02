int	check_up(int map[4][4], int j)
{
	int	k;
	int	max;
	int	count;

	k = 0;
	max = 0;
	count = 0;
	while (k < 4)
	{
		if (map[k][j] > max)
		{
			max = map[k][j];
			count++;
		}
		k++;
	}
	return (count);
}

int	check_down(int map[4][4], int j)
{
	int	k;
	int	max;
	int	count;

	k = 4 - 1;
	max = 0;
	count = 0;
	while (k >= 0)
	{
		if (map[k][j] > max)
		{
			max = map[k][j];
			count++;
		}
		k--;
	}
	return (count);
}

int	check_left(int map[4][4], int j)
{
	int	k;
	int	max;
	int	count;

	k = 0;
	max = 0;
	count = 0;
	while (k < 4)
	{
		if (map[j][k] > max)
		{
			max = map[j][k];
			count++;
		}
		k++;
	}
	return (count);
}

int	check_right(int map[4][4], int j)
{
	int	k;
	int	max;
	int	count;

	k = 4 - 1;
	max = 0;
	count = 0;
	while (k >= 0)
	{
		if (map[j][k] > max)
		{
			max = map[j][k];
			count++;
		}
		k--;
	}
	return (count);
}
// 引数として4x4の値が入ったmapを受け取り、チェックする
// up, down, left, rightで方向を変えている
// まず、maxに0を代入して自分が見る列or行の値と比較していく
// もし列or行の値の方が大きかったらmaxの値を更新する
// 値が更新された回数はcountで保存し、この関数は最終的にその方向から見えるブロックの数を返す
// 返された値は得られた制約と比較されるために使われる
