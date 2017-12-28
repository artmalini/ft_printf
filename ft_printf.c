//#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <float.h>
#include <stdint.h>

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#include <locale.h>
#include <wchar.h>
#include <string.h>

typedef struct 		s_bone
{
	char 			*mod_l;
	char 			type;
	char 			*hex;
	char 			padding;
	int 			base;
	int 			prefix;
	int 			left;
	int 			flag;
	int 			width;
	int 			precis;
	int 			xx;
}					t_bone;


char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
		if (*s++ == 0)
			return (0);
	return ((char*)s);
}
/*
			p->left = 1;
			p->padding = ' ';

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

char		*ft_strrev(char *str)
{
	char	*p1;
	char	*p2;

	if (!str || !*str)
		return (str);
	p1 = str;
	p2 = str + ft_strlen(str) - 1;
	while (p2 > p1)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
		p1 += 1;
		p2 -= 1;
	}
	return (str);
}*/

void	*ft_memalloc(size_t size)
{
	char	*v;
	size_t	i;

	v = (char*)malloc(sizeof(v) * size);
	if (v)
	{
		i = 0;
		while (i < size)
			v[i++] = 0;
	}
	return (v);
}

char	*ft_strcpy(char *dst, const char *src)
{
	char *d;

	d = dst;
	while ((*d++ = *src++) != 0)
		;
	return (dst);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*mas;

	mas = dst;
	while (*src != '\0' && len > 0)
	{
		*mas++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*mas++ = '\0';
		--len;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	if (s)
		while (*s++)
			n++;
	return (n);
}

char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(&s1[ft_strlen(s1)], s2);
	return (s1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2 && s1++ && s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strdup(const char *s1)
{
	char	*mas;

	if (!(mas = (char *)malloc(sizeof(*mas) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(mas, s1);
	return (mas);
}





static char		*ft_strndup(const char *s1, size_t len)
{
	char	*str;

	if (s1)
	{
		str = malloc(sizeof(*str) * (len + 1));
		if (str)
			str = ft_strncpy(str, s1, len);
	}
	else
		str = NULL;
	return (str);
}


static int 		prf_putchar(char c)
{
	int 	len;

	len = 0;
	if (c)
	{
		write(1, &c, 1);
		return (1);
	}
	return (0);
}

static int 		prf_nbr_putchar(char c, int nbr)
{
	int 	len;

	len = 0;
	while (nbr-- > 0)
	{
		write(1, &c, 1);
		len++;
	}
	return (len);
}

static int 		prf_putstr(char *str)
{
	int 	len;

	len = 0;
	if (str)
	{
		while (str[len] != '\0')
			len++;
		write(1, str, len);
	}
	return (len);
}

void 	print_str_ln(char *str, int nbr)
{
	if (*str && nbr)
		write(1, str, nbr);
}




//https://ru.wikipedia.org/wiki/UTF-8
static char	*ft_wctos(wchar_t c)
{
	char	*s;
	char	*e;

	s = ft_memalloc(sizeof(*s) * 5);
	if ((e = s) && c <= 0x7F)//127
		*e++ = c;
	else if (c <= 0x7FF)//2047
	{
		*e++ = (c >> 6) | 0xC0;//0xC0 192
		*e++ = (c & 0x3F) | 0x80;//0x3F 63 0x80 128
	}
	else if (c <= 0xFFFF)//65535
	{
		*e++ = (c >> 12) | 0xE0;//0xE0 224
		*e++ = ((c >> 6) & 0x3F) | 0x80;
		*e++ = (c & 0x3F) | 0x80;
	}
	else if (c <= 0x10FFFF)//1114111
	{
		*e++ = (c >> 18) | 0xF0;//0xF0 240
		*e++ = ((c >> 12) & 0x3F) | 0x80;
		*e++ = ((c >> 6) & 0x3F) | 0x80;
		*e++ = (c & 0x3F) | 0x80;//63  128
	}
	//*e++ = '\0';
	return (s);
}

/*
** Converts each wide character in w to UTF-8 string and concatenates it to the
** return string
*/

static char	*ft_wtoc_strndup(wchar_t *w, size_t n)
{
	char	*s;
	char	*t;
	int		len;

//printf("%d\n", 1);
	if (w && (s = ft_memalloc((n + 1))))
	{
		//printf("%d\n", 2);
		len = n;
		while (*w)
		{
			t = ft_wctos(*w++);
			//printf("ft_wtoc_strndup t %s len n %zu ft_strlen(t) %zu\n", t, n, ft_strlen(t));
			len -= ft_strlen(t);
			//printf("ft_wtoc_strndup len %d\n", len);
			if (len < 0)
				break ;
			s = ft_strcat(s, t);
			if (t)
				free(t);
		}
	}
	else
		s = NULL;
	return (s);
}

/*
** Finds the num of bits of w, then calls ft_wtoc_strndup on that size
*/

static char	*ft_wtoc_strdup(wchar_t *w)
{
	wchar_t	*t;
	size_t	len;

	len = 0;
	t = w;
	if (t)
		while (*t++)
			len += sizeof(wchar_t);
		//printf("ft_wtoc_strdup %zu\n", len);
	return (ft_wtoc_strndup(w, len));
}

int		str_print(va_list arg, t_bone *elem)
{
	char *c;
	char	*s;
	int len;

	len = 0;

		if (elem->mod_l != NULL && !ft_strcmp(elem->mod_l, "l"))
		{
			s = ft_wtoc_strdup(va_arg(arg, wchar_t*));
			len = ft_strlen(s);
			print_str_ln(s, len);
			//printf("XDDDDDDDDDD %s len %d\n", s, len);
		}
		else
		{
			c = va_arg(arg, char *);
			while (*c != '\0')
			{
				write(1, &(*c), 1);
				len++;
				c++;
			}
		}
	free(s);
	return (len);
}

static intmax_t		cast_signed_size_t(intmax_t num)
{
	if (sizeof(size_t) == sizeof(short))
		return ((short)num);
	else if (sizeof(size_t) == sizeof(int))
		return ((int)num);
	else if (sizeof(size_t) == sizeof(long))
		return ((long long)num);
	else if (sizeof(size_t) == sizeof(long long))
		return ((long long)num);
	else
		return (num);
}

static intmax_t		intmax_cast(uintmax_t nbr, t_bone *elem)
{
	if (elem->mod_l != NULL)
	{
		if (!ft_strcmp(elem->mod_l, "hh"))
			return ((char)nbr);
		else if (!ft_strcmp(elem->mod_l, "h"))
			return ((short)nbr);
		else if (!ft_strcmp(elem->mod_l, "l"))
			return ((long)nbr);
		else if (!ft_strcmp(elem->mod_l, "ll"))
			return ((long long)nbr);
		else if (!ft_strcmp(elem->mod_l, "j"))
			return (nbr);
		else if (!ft_strcmp(elem->mod_l, "z"))
			return (cast_signed_size_t(nbr));/////////////235 ^^^^^^
	}
	return ((int)nbr);
}

static uintmax_t		uintmax_cast(uintmax_t nbr, t_bone *elem)
{
	if (elem->mod_l != NULL)
	{
		if (!ft_strcmp(elem->mod_l, "hh"))
			return ((unsigned char)nbr);
		else if (!ft_strcmp(elem->mod_l, "h"))
			return ((unsigned short)nbr);
		else if (!ft_strcmp(elem->mod_l, "l"))
			return ((unsigned long)nbr);
		else if (!ft_strcmp(elem->mod_l, "ll"))
			return ((unsigned long long)nbr);
		else if (!ft_strcmp(elem->mod_l, "j"))
			return (nbr);
		else if (!ft_strcmp(elem->mod_l, "z"))
			return ((size_t)nbr);
	}
	else if (elem->type == 'p')
		return (nbr);
	return ((unsigned int)nbr);
}

char 	*itoa_base(t_bone *elem, uintmax_t bighigh)
{
	uintmax_t 	big;
	char 	*itoa;
	char 	*str;
	int 	len;
	int 	i;
	//printf("itoa_base\n");

	big = bighigh;
	str = "0123456789abcdef0123456789ABCDEF";
	//len = 1 + elem->prefix;
	//printf("elem->hex %s\n", elem->hex);
	str += 16 * elem->xx;
	//printf("str %s\n", str);
	len = 1;	
	i = 0;
	while (big /= elem->base)
		len++;	
	//printf("elem %zu", (len > elem->precis) ? len : elem->precis);
	len = (len > elem->precis) ? len : elem->precis;
	if (!(itoa = (char *)malloc(sizeof(itoa) * (len + 1))))
		return (NULL);	
	*(itoa + len) = '\0';
	while (i < len || bighigh != 0)
	{
		*(itoa + --len) = str[bighigh % elem->base];
		bighigh /= elem->base;
	}
	//if (elem->prefix)
	//	*(itoa + len) = '-';
	return (itoa);
}




int 	print_atoi_flags(char *str, t_bone *elem, int str_len)
{
	int 	len;

	len = 0;
	if (elem->padding == '0')
	{
		//printf("elem->padding == '0'\n");
		len = (elem->flag ? prf_putchar(elem->flag) : 0);
		len += prf_putstr(elem->hex);
	}
	if (!elem->left)
	{
		//printf("!elem->left\n");
		//printf("len %d\n", len);
		if (elem->flag)
			str_len++;
		len += prf_nbr_putchar(elem->padding, elem->width - str_len);
		//printf("str_len %d\n", str_len);
	}
	if (elem->padding == ' ')
	{
		//printf("elem->padding == ' '\n");
		len += (elem->flag ? prf_putchar(elem->flag) : 0);
		len += prf_putstr(elem->hex);
	}
	print_str_ln(str, ft_strlen(str)); ////print numbers
	if (elem->left)
	{
		//printf("elem->left\n");
		//printf("len %d\n", len);

		if (elem->flag)
			str_len++;
		len += prf_nbr_putchar(elem->padding, elem->width - str_len);
		//printf("str_len %d\n", str_len);
	}
	//printf("elem->left %d elem->width %d elem->flag %d\n", elem->left, elem->width, elem->flag);
	free(str);
	return (len);
}

int		print_atoi_nbr(va_list arg, t_bone *elem)
{
	char 		*str;
	intmax_t  	bigmin;
	uintmax_t	bighigh;
	int 	len;

	len = 1;
	str = NULL;
	if (ft_strchr("dDi", elem->type))
	{
		bigmin = intmax_cast(va_arg(arg, intmax_t), elem);
		if (bigmin < 0)
		{
			bighigh = -bigmin;
			//elem->prefix = 1;
			elem->flag = '-';
			//print this minus
		}
		else
			bighigh = bigmin;
	}
	else
		bighigh = uintmax_cast(va_arg(arg, uintmax_t), elem); //yep
	str = itoa_base(elem, bighigh);
	len = ft_strlen(str);// + (elem->flag != 0 ? 1 : 0);	//count str length to output

	len += print_atoi_flags(str, elem, len);									//print flags
	//print_str_ln(str, ft_strlen(str));												//print numbers
	//free(str);
	return (len);
}










int 	print_char(va_list arg, t_bone *elem)
{
	int 		len;
	char 		*str;

	len = 0;
	str = NULL;
	//printf("print_char %s\n", elem->mod_l);
	if (elem->mod_l != NULL && !ft_strcmp(elem->mod_l, "l"))
	{
		//printf("!ft_strcmp(elem->mod_l\n");
		str = ft_wctos((wchar_t)va_arg(arg, wint_t));
	}
	else
	{
		//printf("str %s\n", str); 
		str = ft_memalloc(sizeof(*str) * 2);
		*str = (unsigned char)va_arg(arg, int);
	}
	len = prf_putstr(str);
	free(str);
	return (len);
}

int 	print_str_char(va_list arg, t_bone *elem)
{
	int 		len;
	char 		*str;

	len = 0;
	str = NULL;
	//printf("print_char %s\n", elem->mod_l);
	if (elem->mod_l != NULL && !ft_strcmp(elem->mod_l, "l"))
	{
		if (elem->precis >= 0)
			str = ft_wtoc_strndup(va_arg(arg, wchar_t*), elem->precis);
		else
			str = ft_wtoc_strdup(va_arg(arg, wchar_t*));
	}
	else
	{
		if (elem->precis >= 0)
			str = ft_strndup(va_arg(arg, char*), elem->precis);
		else
			str = ft_strdup(va_arg(arg, char*));
	}
	//printf("str %s\n", str);
	len = prf_putstr(str);
	free(str);
	return (len);
}

int 	parse_arg(va_list arg, t_bone *elem)
{
	int len;
	char 	*str;

	len = 0;
	str = NULL;	
	if (ft_strchr("cC", elem->type))
	{
		//len = str_print(arg, elem);
		len = print_char(arg, elem);
	}
	else if (ft_strchr("sS", elem->type))
	{
		len += print_str_char(arg, elem);
	}
	else if (ft_strchr("pdDioOuUxX", elem->type))
	{		
		len += print_atoi_nbr(arg, elem);
	}
	else if ((str = ft_memalloc(2)))
	{
		*str = elem->type;
		len = prf_putstr(str);
		free(str);
	}
	return (len);
}

void	fillflag(const char **f, t_bone *elem)
{
	while (**f == '+' || **f == ' '|| **f == '-' || **f == '0' || **f == '#')
	{
		if (**f == '+')
			elem->flag = '+';
		else if (**f == ' ')
			elem->flag = (elem->flag == 0 ? ' ' : elem->flag);
		else if (**f == '-')
		{
			elem->left = 1;
			elem->padding = ' ';
		}
		else if (**f == '0')
			elem->padding = (elem->left == 0 ? '0' : elem->padding);
		else if (**f == '#')
			elem->hex = "#";		
		(*f)++;
	}
	//printf("elem->left %d\n", elem->left);
}

void	filllength(const char **format, va_list arg, t_bone *elem)
{
	char 	*str;
	if (ft_strchr("hljzqL", **format))
	{
		//printf("filllength %c\n", **format);
		(*format)++;//to the next symbol
		if (elem->mod_l)
			free(elem->mod_l);

		//elem->mod_l = NULL;
		if (**format == 'h' || **format == 'l')
		{
			if (**format == 'h')
				elem->mod_l = ft_strdup("hh");
			else
				elem->mod_l = ft_strdup("ll");
			//printf("elem->mod_l %s\n", elem->mod_l);
			(*format)++;
		}
		else
		{
			//elem->mod_l = (**format == 'h') ? ft_strdup("h") : NULL;
			//elem->mod_l = ((*format - 1)[0] == 'l') ? ft_strdup("l") : NULL;
			//elem->mod_l = (**format == 'j') ? ft_strdup("j") : NULL;
			//elem->mod_l = (**format == 'z') ? ft_strdup("z") : NULL;
			//elem->mod_l = (**format == 'q') ? ft_strdup("q") : NULL;
			//elem->mod_l = (**format == 'L') ? ft_strdup("L") : NULL;

			str = ft_memalloc(2);// (char *)(*format - 1)[0];
			*str = (char)(*format - 1)[0];
			//printf("st %s\n", str);
			elem->mod_l = ft_strdup(str);
			free(str);
		}
		//elem->mod_l = "l";
		//printf("filllength %c\n", (*format - 1)[0]);
	}
}

void 	fillwidth(const char **format, va_list arg, t_bone *elem)
{
	//printf("fillwidth %c\n", **format);
	if (**format == '*')
	{
		if ((elem->width = va_arg(arg, int)) < 0)
		{
			elem->width = elem->width * -1;
			elem->left = 1;
			elem->padding = ' ';
		}
		(*format)++;
	}
	else if (**format >= '1' && **format <= '9')
	{
		while (**format >= '0' && **format <= '9')
		{
			elem->width = elem->width * 10 + **format - '0';
			(*format)++;
		}
	}
}

void 	fillprecis(const char **format, va_list arg, t_bone *elem)
{
	//printf("fillprecis %c\n", **format);
	if (**format == '.')
	{
		elem->precis = 0;
		//printf("fillprecis %zu\n", elem->precis);
		(*format)++;
		if (**format == '*')
		{
			elem->precis = va_arg(arg, int);
			if (elem->precis < 0)
				elem->precis = -1;
			(*format)++;
		}
		else
		{
			while (**format >= '0' && **format <= '9')
			{
				elem->precis = elem->precis * 10 + **format - '0';
				(*format)++;
			}			
		}
	}
	//printf("fillprecis %zu\n", elem->precis);
}

void	filltype(const char **format, t_bone *elem)
{
	//printf("filltype %c\n", **format);
	if (**format && ft_strchr("sSpdDioOuUxXcCbfFeEgGaA", **format))
	{		
		elem->xx = (ft_strchr("XEGA", **format)) ? 1 : 0;
		elem->base = (ft_strchr("oO", **format) ? 8 : elem->base);
		elem->base = (ft_strchr("pxX", **format) ? 16 : elem->base);
		if (ft_strchr("DOUCS", **format))
		{
			if (elem->mod_l)
				free(elem->mod_l);
			elem->mod_l = ft_strdup("l");
		}
	}	
	elem->type = **format;
	//elem->flag = (!ft_strchr("dDifFfFeEgGaA", **format) ? 0 : elem->flag);
	elem->padding = (ft_strchr("pdDioOuUxXb", **format)) ? ' ' : elem->padding;
}

void			fillhex(const char **format, t_bone *p)
{
	if (p->hex || ft_strchr("paA", **format))//#
	{
		if (ft_strchr("oO", **format))
			p->hex = "0";
		else if (ft_strchr("pxa", **format))
			p->hex = "0x";
		else if (ft_strchr("XA", **format))
			p->hex = "0X";
		else if (**format == 'b')
			p->hex = "0b";
		else
		{
			p->hex = NULL;
			return ;
		}
		//p->flag = 0;
	}
}

void	fillmas(t_bone *elem)
{
	elem->mod_l = NULL;
	elem->type = 0;
	elem->hex = NULL;
	elem->padding = ' ';
	elem->left = 0;
	elem->flag = 0;
	elem->base = 10;
	elem->width = 0;
	elem->precis = -1;
	elem->prefix = 0;
	elem->xx = 0;
}

void	build_flags(const char **format, va_list arg, t_bone *elem)
{
	fillmas(elem);
	fillflag(format, elem);
	fillwidth(format, arg, elem);
	fillprecis(format, arg, elem);
	filllength(format, arg, elem);
	filltype(format, elem);

	fillhex(format, elem);
}

int 	ft_printf(const char *format, ...)
{
	int 	len;
	int 	tick;
	const char	*e;
	va_list arg;
	t_bone		*elem;

	va_start(arg,format);
	tick = 0;
	elem = malloc(sizeof(*elem));
	while (*format)
	{
		if (*format == '%')
		{
			e = format + 1;
			//printf("e %s\n", e);
			//if(!(len = parse_arg(&format, arg)))
			//	break ;
			build_flags(&e, arg, elem);
			//printf("elem->mod_l %s\n", elem->mod_l);
			len = parse_arg(arg, elem);
			if (elem->mod_l)
				free(elem->mod_l);
			tick += len;
			format = e;
		}
		else
		{
			write(1, &(*format), 1);
			tick++;
		}
		//free(elem->mod_l);
		format += *format ? 1 : 0;
	}
	va_end(arg);
	free(elem);
	//printf("tick %d\n", tick);
	return (tick);
}
