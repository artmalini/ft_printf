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
/*char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
		if (*s++ == 0)
			return (0);
	return ((char*)s);
}*/
/*size_t		ft_strlen(const char *str)
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

int 	parse_arg(const char **format, va_list arg)
{
	//int len;
	char *c;
	//int 	i;

	//len = 1;
	//i = 0;
	//printf("**format %c\n", **format);
	if (**format && ft_strchr("sSpdDioOuUxXcCbfFeEgGaA", **format))
	{
		c = va_arg(arg, char *);
		while (*c != '\0')
		{
			write(1, &(*c), 1);
			c++;
		}
	}
	//printf("format %s", *format);
	//write(1, &c, 1);
	//if (arg == 's')
	//{
		//printf("%s", "ok");
	//}
	return (1);
}

int 	ft_printf(const char *format, ...)
{
	int 	len;
	int 	tick;
	const char	*e;
	va_list arg;

	va_start(arg,format);
	tick = 0;
	while (*format)
	{
		if (*format == '%')
		{
			e = format + 1;
			//if(!(len = parse_arg(&format, arg)))
			//	break ;
			len = parse_arg(&e, arg);
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
	return (tick);
}

/*int	main(void)
{
	setlocale(LC_ALL,""); //для юникода 我是一只猫
	//0x7fffffff  == 2147483647
	char *st;
	st = "Blackbirds";
	//printf("%s\n", ft_strrev(st));
	//printf("{%s}", 0);
	//printf("\n");
	//ft_printf("yo %s yo %s", "xD", "What's up!");

	printf("hell%% %-9u,,,,,,, %s %s", 4242, "MYBRO", "Welcome");
	printf("\n");

	printf("%S", L"我是一只猫。");
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

	printf("%s333", "222");
	printf("\n");

	printf("111%s333", "222");
	printf("\n");

	printf("111%s333%s555", "222", "444");
	printf("\n");

	printf("111%s333%s555%saaa%sccc","222", "444", "666", "bbb");
	printf("\n");

	printf("111%s333%s555", "222", "444");
	printf("\n");

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
}*/