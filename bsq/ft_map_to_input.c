/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_to_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:31:37 by retanaka          #+#    #+#             */
/*   Updated: 2023/08/30 23:09:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_map_to_kouzou(char **strs, t_input *kouzou)
{
	int		first_line_len;
	int		i;
	char	**temp;

	first_line_len = ft_strlen(strs[0]);
	kouzou->ful = strs[0][first_line_len - 1];
	kouzou->obs = strs[0][first_line_len - 2];
	kouzou->emp = strs[0][first_line_len - 3];
	kouzou->row = ft_strlen(strs[1]);
	i = 0;
	while (strs[i])
		i++;
	kouzou->col = i;
	temp = (char **)malloc(sizeof(char *) * (kouzou->col + 1));
	if (temp == NULL)
		return (1);
	i = -1;
	while (++i < kouzou->col)
		temp[i] = ft_strdup_sp(strs[i]);
	kouzou->map = temp;
	return (0);
}
