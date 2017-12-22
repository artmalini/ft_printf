//#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

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
}					t_bone;


char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
		if (*s++ == 0)
			return (0);
	return ((char*)s);
}
/*
artmalini@gmail.com tokar06

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

	v = (char*)malloc(sizeof(*v) * size);
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
	*e++ = '\0';
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

	if (w && (s = ft_memalloc(sizeof(*s) * (n + 1))))
	{
		len = n;
		while (*w)
		{
			t = ft_wctos(*w++);
			printf("ft_wtoc_strndup t %s len n %zu ft_strlen(t) %zu\n", t, n, ft_strlen(t));
			len -= ft_strlen(t);
			printf("ft_wtoc_strndup len %d\n", len);
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
		printf("ft_wtoc_strdup %zu\n", len);
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
	return (len);
}

//char 	itoa_base(va_list arg, t_bone *elem, uintmax_t bighigh)

int		hex_print(va_list arg, t_bone *elem)
{
	char 		*str;
	intmax_t  	bigmin;
	uintmax_t	bighigh;
	int 	len;

	len = 1;
	if (ft_strchr("dDi", elem->type))
	{
		bigmin = intmax_cast(va_arg(arg, intmax_t), elem);
		if (bigmin < 0)
		{
			bighigh = -bigmin;
			//print this minus
		}
		else
			bighigh = bigmin;
	}
	//bighigh = uintmax_cast(va_arg(arg, uintmax_t), elem);; //yep
	//str = itoa_base(arg, elem, bighigh);
	return (len);
}

int 	parse_arg(va_list arg, t_bone *elem)
{
	int len;

	len = 0;
	
	if (ft_strchr("csS", elem->type))
	{
		len = str_print(arg, elem);
	}
	else if (ft_strchr("pdDioOuUxX", elem->type))
	{
		len += hex_print(arg, elem);
	}	

	//}

	//printf("format %s", *format);
	//write(1, &c, 1);
	//if (arg == 's')
	//{
		//printf("%s", "ok");
	//}
	return (len);
}

void	fillmas(t_bone *elem)
{
	elem->mod_l = NULL;
	elem->type = 0;
	elem->hex = 0;
}

void	filllength(const char **format, va_list arg, t_bone *elem)
{
	//*format++;
	if (**format == 'l')
	{
		(*format)++;//to the next symbol
		if (elem->mod_l)
			elem->mod_l = NULL;
		//elem->mod_l = ft_strdup("l");
		elem->mod_l = "l";
	}
}

void	filltype(const char **format, t_bone *elem)
{
	printf("filltype %c\n", **format);
	if (**format && ft_strchr("sSpdDioOuUxXcCbfFeEgGaA", **format))
	{
		elem->type = **format;
	}
}

void			fillhex(const char **format, t_bone *p)
{
	if (p->hex || ft_strchr("paA", **format))
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
		//p->sign = 0;
	}
}
void	build_flags(const char **format, va_list arg, t_bone *elem)
{
	fillmas(elem);
	filllength(format, arg, elem);
	filltype(format, elem);
	fillhex(format, elem);

	//parse_arg(format, arg, elem);
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
	elem = (t_bone *)malloc(sizeof(elem));
	while (*format)
	{
		if (*format == '%')
		{
			e = format + 1;
			printf("e %s\n", e);
			//if(!(len = parse_arg(&format, arg)))
			//	break ;
			build_flags(&e, arg, elem);
			printf("elem->mod_l %s\n", elem->mod_l);
			len = parse_arg(arg, elem);
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
	va_end(arg);
	free(elem);
	printf("tick %d\n", tick);
	return (tick);
}

int	main(void)
{
	//setlocale(LC_ALL,""); //для юникода 我是一只猫
	//0x7fffffff  == 2147483647
	char *st;
	st = "Blackbirds";
	//printf("or:%1$.*2$f\n", 0.2, 42);

	//printf("%s\n", ft_strrev(st));
	//printf("{%s}", 0);
	//printf("\n");
	//ft_printf("yo %s yo %s", "xD", "What's up!");	
	//ft_printf("%c", 0);
	//printf("\n");

	printf("hell%% %-9u,,,,,,, %s %s", 4242, "MYBRO", "Welcome");
	printf("\n");

	printf("%c%c", '4', '2');
	printf("\n");

	printf("%ls", L"我是一只猫。"); //18 symb
	printf("\n");

		ft_printf("%ls", L"我是一只猫。");
	printf("\n");
			ft_printf("%ls", L"ѠѢ");
	printf("\n");

	ft_printf("yoyo %c %c", "s", "!");
	printf("\n");
	ft_printf("yoyo %s %s", "What's", "UP!");

	printf("\n");
	printf("%%");
	printf("\n");

	printf("aa%%bb");
	printf("\n");

	printf("%%%%%%%%%%");
	printf("\n");

	printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	printf("\n");

	//printf("[{red|ss|f-yellow}%20s{eoc}]{cyan|f-pink}%15d{eoc}\n", "Salut!", 42);
	printf("										s	string\n");
	printf("%9s", "abc");
	printf("\n");

	//printf("{%s}", 0);
	//printf("\n");


	printf("111%s", "222");
	printf("\n");
		ft_printf("111%s", "222");
	printf("\n");

	printf("%s333", "222");
	printf("\n");
		ft_printf("%s333", "222");
	printf("\n");

	printf("111%s333", "222");
	printf("\n");
		ft_printf("111%s333", "222");
	printf("\n");

	printf("111%s333%s555", "222", "444");
	printf("\n");
		ft_printf("111%s333%s555", "222", "444");
	printf("\n");

	printf("111%s333%s555%saaa%sccc","222", "444", "666", "bbb");
	printf("\n");
		ft_printf("111%s333%s555%saaa%sccc","222", "444", "666", "bbb");
	printf("\n");

	printf("111%s333%s555", "222", "444");
	printf("\n");
		ft_printf("111%s333%s555", "222", "444");
	printf("\n");

	printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\n");
		ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\n");


	printf("%ls, %ls", L"暖炉", L"لحم خنزير");
	printf("\n");
		ft_printf("%ls, %ls", L"暖炉", L"لحم خنزير");
	printf("\n");	
	//printf("% Zoooo");
	//printf("\n");
	//	ft_printf("% Zoooo");
	//printf("\n");


	printf("										d	dec\n");

	printf("% d % d", 42, -42);
	printf("\n");

	printf("%+d %+d", 42, -42);
	printf("\n");

	printf("%05d   %05d", 5, 12345);
	printf("\n");

	printf("%*d", 1, 42);
	printf("\n");

	printf("%2$*1$d", 1, 42);
	printf("\n");

	printf("%d", 42);
	printf("\n");

	printf("%d", -42);
	printf("\n");

	printf("before %d after", 42);
	printf("\n");

	printf("%d%d%d%d%d", 1, -2, 3, -4, 5);
	printf("\n");

	printf("a%db%dc%dd", 1, -2, 3);
	printf("\n");

	printf("%d", INT_MAX);
	printf("\n");

	printf("%d", INT_MIN);
	printf("\n");

	printf("										p	mem\n");

	int i;
	printf("%p", &i);
	printf("\n");

	unsigned long l;
	printf("%p", &l);
	printf("\n");

		ft_printf("%p", &l);
	printf("\n");

	char *str;
	printf("%p", &str);
	printf("\n");


	printf(" 								FLAGS\n");

	printf("{%+d}", 42);
	printf("\n");

	printf("%+d", -42);
	printf("\n");


	printf("%.3%");
	printf("\n");

	//printf("%O", 42);													
}