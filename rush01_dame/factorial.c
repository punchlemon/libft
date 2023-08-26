int	factorial(int size)
{
	if (size == 1)
		return (1);
	return (size * factorial(size - 1));
}