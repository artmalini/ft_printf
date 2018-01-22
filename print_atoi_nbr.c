/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_atoi_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:37:48 by amakhiny          #+#    #+#             */
/*   Updated: 2018/01/22 12:37:52 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	hex_free(t_bone *elem)
{
	if (elem->hex)
	{
		free(elem->hex);
		elem->hex = NULL;
	}	
}

int		print_atoi_nbr(va_list arg, t_bone *elem)
{
	char		*str;
	intmax_t	bigmin;
	uintmax_t	bighigh;
	int 		len;

	len = 0;
	str = NULL;
	if (elem->type && ft_strchr("dDi", elem->type))
	{
		bigmin = intmax_cast(va_arg(arg, intmax_t), elem);
		if (bigmin < 0)
		{
			bighigh = -bigmin;
			elem->flag = '-';
		}
		else
			bighigh = bigmin;
	}
	else
		bighigh = uintmax_cast(va_arg(arg, uintmax_t), elem);
	if (bighigh == 0 && (elem->type && ft_strchr("oO", elem->type)))
		hex_free(elem);
	if ((bighigh == 0 && elem->type && (!ft_strchr("poO", elem->type) || (elem->hex && ft_strchr("oO", elem->type) && elem->precis))) || (elem->hex && ft_strchr("oO", elem->type) && elem->precis > 0))
		hex_free(elem);
	if ((bighigh == 0 && elem->precis == 0 && elem->width == 0) && (elem->type && !ft_strchr("poO", elem->type)))
		return (len);
	else
	{
		str = prf_itoa_base(elem, bighigh);
		len = ft_strlen(str);
		len += print_str_with_flags(str, elem, len);
	}
	return (len);
}
