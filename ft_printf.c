/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:57:19 by amakhiny          #+#    #+#             */
/*   Updated: 2018/01/19 18:57:39 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	struct_init(t_bone *elem)
{
	g_eflag = 0;
	elem->mod_l = -1;
	elem->type = -1;
	elem->hex = NULL;
	elem->padding = ' ';
	elem->left = 0;
	elem->flag = 0;
	elem->base = 10;
	elem->width = 0;
	elem->minus = -1;
	elem->precis = -1;
	elem->precisz = -1;
	elem->prefix = 0;
	elem->hash = 0;
	elem->pls = 0;
	elem->xx = 0;
}

void	build_flags(const char **format, va_list arg, t_bone *elem)
{
	struct_init(elem);
	fill_flag(format, elem);
	fill_width(format, arg, elem);
	fill_precis(format, arg, elem);
	fill_length(format, elem);
	fill_type(format, elem);
	fill_hex(format, elem);
}

int		parse_str_printf(const char *format, va_list arg, t_bone *elem, int len)
{
	int			tick;
	const char	*e;

	tick = 0;
	while (*format)
	{
		if (*format == '%')
		{
			e = format + 1;
			build_flags(&e, arg, elem);
			len = parse_arg(arg, elem, tick);
			if (elem->hex)
				free(elem->hex);
			if (elem->type == 'n')
				tick = len;
			 else
				tick += len;
			format = e;
		}
		else
		{
			write(1, &(*format), 1);
			tick++;
		}
		format += *format ? 1 : 0;
	}
	return (tick);
}

int		ft_printf(const char *format, ...)
{
	int			len;
	va_list		arg;
	t_bone		*elem;

	len = 0;
	elem = (t_bone *)malloc(sizeof(t_bone));
	va_start(arg, format);
	len = parse_str_printf(format, arg, elem, len);
	free(elem);
	va_end(arg);
	return (len);
}
