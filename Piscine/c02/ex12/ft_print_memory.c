/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:36:41 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/15 15:38:02 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(unsigned char *addr)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[*addr >> 4], 1);
	write(1, &hex[*addr & 0x0F], 1);
}

void	print_address(void *a)
{
	unsigned char	c;
	int				i;

	c = (char)(uintptr_t)a;
	i = 8;
	while (i)
		print_hex(&c + i--);
	write(1, ": ", 2);
}

void	print_memory_hex(unsigned char *a, unsigned int size)
{
	int	i;

	i = 0;
	while (1)
	{
		if (size)
		{
			print_hex(a++);
			size--;
		}
		else
			write(1, "  ", 2);
		if (i++ % 2)
			write(1, " ", 1);
		if (i == 16)
			break ;
	}
}

void	print_memory_ascii(unsigned char *a, unsigned int size)
{
	int	i;

	i = 0;
	while (size--)
	{
		if (*a < ' ' || '~' < *a)
			write(1, ".", 1);
		else
			write(1, a, 1);
		a++;
		if (++i == 16)
			break ;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				last;
	unsigned char	*a;

	a = (unsigned char *)addr;
	last = 0;
	while (1)
	{
		if (size < 16)
			last = 1;
		print_address(a);
		print_memory_hex(a, size);
		print_memory_ascii(a, size);
		write(1, "\n", 1);
		if (last)
			break ;
		size -= 16;
		a += 16;
	}
	return (addr);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	*a;
// 	char	b[] = "my name is @@@";
// 	a = "hello world!";
// 	ft_print_memory(ft_print_memory, 450);
// 	write(1, "\n", 1);
// 	ft_print_memory(b, 30);
// 	// printf("%p", &a);
// 	return (0);
// }
