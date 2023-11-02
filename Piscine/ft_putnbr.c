#include <unistd.h>

int	 abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	rc(int nbr)
{
	char	c;

	if (0 < abs(nbr / 10))
		rc(nbr / 10);
	c = abs(nbr % 10) + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
		write(1, "-", 1);
	rc(nbr);
	write(1, "\n", 1);
}

int main() {
	ft_putnbr(-2147483648);
	ft_putnbr(2147483647);
	ft_putnbr(42);
	ft_putnbr(0);
}