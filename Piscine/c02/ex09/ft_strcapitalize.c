/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:13:38 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/14 18:06:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_is_word(char c)
{
	int	ret;

	ret = ('0' <= c && c <= '9');
	ret += (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
	return (ret);
}

void	strupcase(char *str)
{
	if ('a' <= *str && *str <= 'z')
		*str = *str - 'a' + 'A';
}

void	strlowcase(char *str)
{
	if ('A' <= *str && *str <= 'Z')
		*str = *str - 'A' + 'a';
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;
	int		wf_b;
	int		wf_n;

	ret = str;
	wf_b = 0;
	while (*str)
	{
		wf_n = str_is_word(*str);
		if (wf_n)
			strlowcase(str);
		if (!wf_b)
			strupcase(str);
		wf_b = wf_n;
		str++;
	}
	return (ret);
}
// #include <unistd.h>
// int main(void)
// {
// 	char str[] = "heLlo wor42lD";
// 	ft_strcapitalize(str);
// 	write(1, str, 13);
// 	return 0;
// }
