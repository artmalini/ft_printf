/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:24:11 by amakhiny          #+#    #+#             */
/*   Updated: 2018/01/22 14:24:25 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char 	*prf_itoa_base(t_bone *elem, uintmax_t bighigh)
{
	uintmax_t 	big;
	int			tmpbig;
	char		*itoa;
	char		*str;
	int			len;
	int			i;

	big = 0;
	big = bighigh;
	str = "0123456789abcdef0123456789ABCDEF";
	str += 16 * elem->xx;
	len = 1;	
	i = 0;
	while (big /= elem->base)
		len++;	
	tmpbig = len;
	len = (len > elem->precis) ? len : elem->precis;
	if (!(itoa = (char *)malloc(sizeof(itoa) * (len + 1))))
		return (NULL);
	*(itoa + len) = 0;
	while (i < len && ((elem->precis != 0 || tmpbig > 1) || (elem->type && ft_strchr("fFeEaA", elem->type))))
	{
		*(itoa + --len) = str[bighigh % elem->base];
		bighigh /= elem->base;
	}
	return (itoa);
}
