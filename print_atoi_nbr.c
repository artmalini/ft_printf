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

/*void	hex_free(t_bone *elem)
{
	if (elem->hex)
	{
		free(elem->hex);
		elem->hex = NULL;
		//printf("elem->hex %s\n", elem->hex);		
	}
}

void	check_for_hex(t_bone *elem, uintmax_t bighigh)
{
	if (bighigh == 0 && (!elem->hex && elem->type && ft_strchr("oO", elem->type)))
		hex_free(elem);
	if ((bighigh == 0 && elem->type && (!ft_strchr("poO", elem->type) ||
		(!elem->hex && ft_strchr("oO", elem->type) && elem->precis))) ||
		(!elem->hex && ft_strchr("oO", elem->type) && elem->precis > 0))
		hex_free(elem);
	if (elem->hex && ft_strchr("oO", elem->type) && elem->mod_l != -1)
		hex_free(elem);
}*/

int		parse_atoi_arg(t_bone *elem, uintmax_t bighigh, int len)
{
	char	*str;

	str = NULL;
	str = prf_itoa_base(elem, bighigh);
	len = ft_strlen(str);
	//printf("len %d\n", len);
	len += print_str_with_flags(str, elem, len);
	return (len);
}

int		print_atoi_nbr(va_list arg, t_bone *elem)
{
	uintmax_t	bighigh;
	intmax_t	bigmin;
	int			len;

	len = 0;
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
	if (bighigh > 4294000000 && ft_strchr("oO", elem->type))
		elem->hash = '-';
	//printf("1 elem->hex %s\n", elem->hex);
	//check_for_hex(elem, bighigh);
	//printf("bighigh %ju\n", bighigh);
	//printf("elem->hex %s elem->type %d elem->flag %d elem->mod_l %d\n", elem->hex, elem->type, elem->flag, elem->mod_l);
	if ((bighigh == 0 && elem->precis == 0 && elem->width == 0 && elem->mod_l == -1) &&
			(elem->type && !ft_strchr("poO", elem->type)))// || (bighigh == 0 && elem->precis == 0 && !ft_strchr("dD", elem->type)))
		//((bighigh == 0 && (elem->type && ft_strchr("oO", elem->type)))))
	{
		//printf("zero\n");
		//printf("elem->type %d elem->flag %d\n", elem->type, elem->flag);
		if (elem->flag != 0 || ft_strchr("oO", elem->type))
			len += parse_atoi_arg(elem, bighigh, len);
		return (len);
	}
	else
		len += parse_atoi_arg(elem, bighigh, len);
	return (len);
}
