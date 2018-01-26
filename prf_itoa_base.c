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

void	hex_free(t_bone *elem)
{
	if (elem->hex)
	{
		free(elem->hex);
		elem->hex = NULL;
		//printf("elem->hex %s\n", elem->hex);		
	}
}

int		find_biglen(t_bone *elem, uintmax_t bighigh, int len)
{
	while (bighigh /= elem->base)
		len++;
	//printf("len %d\n", len);
	return (len);
}

int		check_val(t_bone *elem, int tmpbig, uintmax_t big)
{
	if ((ft_strchr("oO", elem->type) && elem->hex && big == 0 && elem->pls == 1 && elem->precis == 0 && elem->mod_l != -1))
	{
		//printf("g0\n");
		hex_free(elem);
		return (1);
	}
	if (ft_strchr("oO", elem->type) && elem->hex && big == 0)
	{
		//printf("g1\n");
		if (elem->precis > 0)
		{
			hex_free(elem);
			return (1);
		}
		//hex_free(elem);
		return (0);
	}
	if (ft_strchr("oO", elem->type) && elem->hex && big == 0 && elem->precis == 0)
	{
		//printf("g2\n");
		//hex_free(elem);
		return (0);
	}
	if ((ft_strchr("oO", elem->type) && elem->hex && big > 0 && elem->precis > 0))
	{
		//printf("g3\n");
		//if (elem->precisz == -1 && elem->left == 0 || elem->minus = 1)
		if ((elem->minus == 1 || (elem->width == 0 && elem->hex)) && elem->hash == '-')
		{
			//printf("g3\n");
			if (elem->minus == 1 && ft_strchr("oO", elem->type) && elem->mod_l != 0)
				return (1);
			hex_free(elem);
		}
		//if (elem->minus == 1 || (elem->width != 0 && elem->hex && elem->mod_l == 0))
		//	hex_free(elem);
		if (((elem->width > 0 || elem->precis > 0) && elem->hash != '-'))//27
		{
			//printf("here big %ju\n", big);
			if (elem->precis <= find_biglen(elem, big, 1))//24   31
				return (1);
			//if (elem->mod_l == 0)
			//	return (1);
			//if (elem->precis > find_biglen(elem, big, 1) && elem->mod_l == 0)
			//	return (1);
			hex_free(elem);
		}
		//if (((elem->minus == -1 && elem->width > 0 && elem->precis > 0 && elem->mod_l == -1) && elem->hash != '-'))
		return (1);
	}

/////////|
	if (ft_strchr("xX", elem->type) && elem->hex && big == 0)
	{
		//printf("4\n");
		if (elem->mod_l <= 0 || elem->width > 0)
		{
			hex_free(elem);
			if (elem->precis == 0)
				return (0);
			return (1);
		}
		if (elem->mod_l > 0 && elem->precis == 0)//9||%#.0llx|
		{
			hex_free(elem);
			return (0);
		}
		if (elem->mod_l > 0 || elem->precis > 0)
		{
			hex_free(elem);
			return (1);
		}

		return (1);
	}
	if (ft_strchr("xX", elem->type) && elem->hex)
	{
		//printf("5\n");
		if ((big == 0 || elem->mod_l <= 1) && elem->precis <= 0 && big == 0)
		{
			//printf("yep\n");
			hex_free(elem);
			return (0);
		}
		return (1);
	}



	if (ft_strchr("xX", elem->type) && elem->hex && big == 0 && elem->precis == 0 && elem->mod_l != -1)
	{
		//printf("6\n");
		//if (elem->mod_l == 0)
		//	hex_free(elem);	
		return (0);
	}
	/*if ((ft_strchr("oO", elem->type) && big > 0 && elem->hex && elem->precis > 0))
	{
		//printf("4\n");;
		//hex_free(elem);
		return (1);
	}*/	
	if ((elem->precis != 0 || tmpbig > 1) || ((elem->pls == 1 && ft_strchr("oO", elem->type) && elem->hex)) ||
		(elem->type && ft_strchr("fFeEaA", elem->type)))
	{
		//printf("7\n");
		//if (elem->precis > 0 && ft_strchr("xX", elem->type))
		//	hex_free(elem);		
		return (1);
	}
	//printf("xx 0\n");
	return (0);
}

char	*prf_itoa_base(t_bone *elem, uintmax_t bighigh)
{
	uintmax_t	big;
	int			tmpbig;
	char		*itoa;
	char		*str;
	int			len;
	int			i;

	str = "0123456789abcdef0123456789ABCDEF";
	str += 16 * elem->xx;
	len = 1;
	i = 0;
	len = find_biglen(elem, bighigh, len);
	tmpbig = len;
	itoa = NULL;
	big = bighigh;
	len = (len > elem->precis) ? len : elem->precis;
		//if (!(itoa = (char *)malloc(sizeof(itoa) * (len + 1))))
		//	return (NULL);
		//*(itoa + len) = 0;
	if (!(itoa = ft_memalloc(len + 1)))
		return (NULL);
	//printf("elem->flag %c\n", elem->flag);
	//printf("*itoa fir %s len %d bighigh %ju elem->hex %s elem->precis %d elem->minus %d elem->width %d elem->flag %d\n", itoa, len, bighigh, elem->hex, elem->precis, elem->minus, elem->width, elem->flag);
	while (i < len && check_val(elem, tmpbig, big))
	{
		//printf("str[bighigh lem->base] %c\n", str[bighigh % elem->base]);
		*(itoa + --len) = str[bighigh % elem->base];
		bighigh /= elem->base;
	}
	//printf("* eeitoa %s *\n", itoa);
	return (itoa);
}
