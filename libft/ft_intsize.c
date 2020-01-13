/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:47:38 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/05 05:12:43 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_intsize(long long nb, int base)
{
	int len;

	len = 1;
	if (nb < 0)
		nb *= -1;
	while (nb >= base)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}
