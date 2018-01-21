//#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <float.h>
#include <stdint.h>

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

//#include <locale.h>
#include <wchar.h>
#include <string.h>

typedef struct 		s_bone
{
	//char 			*mod_l;
	int 			mod_l;
	char 			type;
	char 			*hex;
	char 			padding;
	int 			base;
	int 			prefix;
	int 			left;
	int 			flag;
	int 			width;
	int 			precis;
	//int 			g_mode;
	//int 			g_mode_on;
	//int 			a_mode;
	unsigned short 			xx;
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

char	*ft_strnew(size_t size)
{
	char	*mas;

	if (!(mas = ft_memalloc(size + 1)))
		return (NULL);
	return (mas);
}

/*char	*ft_strcpy(char *dst, const char *src)
{
	char *d;

	d = dst;
	while ((*d++ = *src++) != 0)
		;
	return (dst);
}*/
char	*ft_strcpy(char *dst, const char *src)
{
	char	*mas;

	mas = dst;
	while (*src != '\0')
		*mas++ = *src++;
	*mas = '\0';
	return (dst);
}


static char	*ft_strncpy(char *dst, const char *src, size_t len) // Мой с этим не работает
{
	char *d;

	d = dst;
	while (len && *src)
	{
		len--;
		*d++ = *src++;
	}
	if (len == 0)
		len++;
	while (len--)
		*d = 0;
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

/*char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(&s1[ft_strlen(s1)], s2);
	return (s1);
}*/
char	*ft_strcat(char *s1, const char *s2)
{
	char	*mas;
	int		ln;
	int		i;

	mas = s1;
	ln = 0;
	i = 0;
	while (mas[ln] != '\0')
		ln++;
	while (s2[i] != '\0')
	{
		mas[ln] = s2[i];
		i++;
		ln++;
	}
	mas[ln] = '\0';
	return (mas);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2 && s1++ && s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*char	*ft_strdup(const char *s1)			//?? Тоже не работает
{
	char	*mas;

	if (!(mas = (char *)malloc(sizeof(*mas) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(mas, s1);
	return (mas);
}*/


static char		*ft_strdup(const char *s1)			//?? Т
{
	int		len;
	char	*str;

	if (s1)
	{
		len = ft_strlen(s1);
		str = malloc(sizeof(*str) * len + 1);
		if (str)
			str = ft_strcpy(str, s1);
	}
	else
		str = NULL;
	return (str);
}



static char		*ft_strndup(const char *s1, size_t len)
{
	char	*str;
	//printf("ft_strndup len %zu\n", len);
	if (s1)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
			str = ft_strncpy(str, s1, len);
	}
	else
		str = NULL;
	return (str);
}


static int 		prf_putchar(char c)
{
	//int 	len;

	//len = 0;
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
		//printf("prf_nbr_putchar\n");
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
		while (str[len])
			len++;
		write(1, str, len);
	}
	return (len);
}

/*void	print_str_ln(char *str, size_t nbr) 
{
	//printf("print_str_ln\n");
	size_t len;

	len = 0;
	if (str && nbr)
	{
		//printf("write ft_putnstr_fd\n");
		len = ft_strlen(str);
		if (nbr < len)
			len = nbr;
		write(1, str, len);
	}
}*/

void		print_str_ln(char *str, size_t nbr)
{
	if (str && nbr)
		write(1, str, nbr);
}

size_t		ft_char(char *str)
{
	//printf("ft_char\n");
	int 	len;

	len = 0;
	if (str)
	{
		len++;
		write(1, &(*str), 1);
		free(str);		
	}
	return (len);
}
/*void	ft_strrev(char *s)
{
	char *e;
	char t;

	if (!s)
		return ;
	e = s;
	while (*e)
		e++;
	e--;
	while (s < e)
	{
		t = *s;
		*s++ = *e;
		*e-- = t;
	}
}*/








static char		*utf_char_unicode(wchar_t c)
{
	char	*str;
	char	*e;

	str = ft_memalloc(5);
	if ((e = str) && c <= 0x7F)//127
		e[0] = c;
	else if (c <= 0x7FF)//2047
	{
		e[0] = (c >> 6) | 0xC0;//0xC0 192
		e[1] = (c & 0x3F) | 0x80;//0x3F 63 0x80 128
	}
	else if (c <= 0xFFFF)//65535
	{
		e[0] = (c >> 12) | 0xE0;//0xE0 224
		e[1] = ((c >> 6) & 0x3F) | 0x80;
		e[2] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0x10FFFF)//1114111
	{
		e[0] = (c >> 18) | 0xF0;//0xF0 240
		e[1] = ((c >> 12) & 0x3F) | 0x80;
		e[2] = ((c >> 6) & 0x3F) | 0x80;
		e[3] = (c & 0x3F) | 0x80;//63  128
	}
	return (str);
}

/*
** Converts each wide character in w to UTF-8 string and concatenates it to the
** return string
*/

static char		*utf_char_len_concat(wchar_t *symb, size_t len)
{
	char	*str;
	char	*utf_str;
	int		nbr;

//printf("%d\n", 1);
	if (symb && (str = ft_memalloc((len + 1))))
	{
		//printf("%d\n", 2);
		nbr = len;
		while (*symb)
		{
			utf_str = utf_char_unicode(*symb++);
			nbr -= ft_strlen(utf_str);
			//printf("utf_char_len_concat nbr %d\n", nbr);
			if (nbr < 0)
				break ;
			str = ft_strcat(str, utf_str);
			if (utf_str)
				free(utf_str);
		}
	}
	else
		str = NULL;
	return (str);
}

/*
** Finds the num of bits of c, then calls utf_char_len_concat on that size
*/

static char		*utf_char_find_len_concat(wchar_t *c)
{
	wchar_t	*symb;
	size_t	len;
	char 	*str;

	len = 0;
	symb = c;
	if (symb)
		while (*symb++)
			len += sizeof(wchar_t);
		//printf("utf_char_find_len_concat %zu\n", len);
	str = utf_char_len_concat(c, len);
	return (str);
}

intmax_t		cast_signed_size_t(intmax_t num)
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

intmax_t		intmax_cast(uintmax_t nbr, t_bone *elem)
{
	if (elem->mod_l != -1)
	{
		if (elem->mod_l == 0)
			return ((char)nbr);
		else if (elem->mod_l == 1)
			return ((short)nbr);
		else if (elem->mod_l == 2)
			return ((long)nbr);
		else if (elem->mod_l == 3)
			return ((long long)nbr);
		else if (elem->mod_l == 5)
			return (nbr);
		else if (elem->mod_l == 6)
			return (cast_signed_size_t(nbr));
	}	
	return ((int)nbr);
}

uintmax_t		uintmax_cast(uintmax_t nbr, t_bone *elem)
{
	if (elem->mod_l != -1)
	{
		if (elem->mod_l == 0)
			return ((unsigned char)nbr);
		else if (elem->mod_l == 1)
			return ((unsigned short)nbr);
		else if (elem->mod_l == 2)
			return ((unsigned long)nbr);
		else if (elem->mod_l == 3)
			return ((unsigned long long)nbr);
		else if (elem->mod_l == 5)
			return (nbr);
		else if (elem->mod_l == 6)
			return ((size_t)nbr);
	}	
	else if (elem->type == 'p')
		return (nbr);
	return ((unsigned int)nbr);
}


char 	*itoa_base(t_bone *elem, uintmax_t bighigh)
{
	uintmax_t 	big;
	int			tmpbig;
	char		*itoa;
	char		*str;
	int			len;
	int			i;
	//printf("itoa_base\n");
	//printf("bighigh %zu elem->precis %d\n", bighigh, elem->precis);

	big = 0;
	big = bighigh;
	//tmpbig = big;
	str = "0123456789abcdef0123456789ABCDEF";
	//len = 1 + elem->prefix;
	//printf("elem->hex %s\n", elem->hex);
	str += 16 * elem->xx;
	//printf("str %s\n", str);
	len = 1;	
	i = 0;
	while (big /= elem->base)
		len++;	
	tmpbig = len;
	//printf("len %d\n", len);
	//printf("elem %zu", (len > elem->precis) ? len : elem->precis);
	len = (len > elem->precis) ? len : elem->precis;
	//len = (elem->type && ft_strchr("fF", elem->type)) ? 1 : len;
	//printf("len %d\n", len);
	if (!(itoa = (char *)malloc(sizeof(itoa) * (len + 1))))
		return (NULL);
	*(itoa + len) = 0;
	//while (i < len && (elem->precis != 0 || tmpbig > 1))
	while (i < len && ((elem->precis != 0 || tmpbig > 1) || (elem->type && ft_strchr("fFeEaA", elem->type))))
	{
		*(itoa + --len) = str[bighigh % elem->base];
		//i++;
		bighigh /= elem->base;
	}
	//i++;
	// *(itoa + i) = 0;
	//if (elem->prefix)
	//	*(itoa + len) = '-';
	//printf("itoa end %s\n", itoa);
	return (itoa);
}




size_t 		print_str_with_flags(char *str, t_bone *elem, int str_len)
{
	size_t 	len;

	len = 0;
	//printf("STR strlen %zu elem->hex %s elem->flag %d\n", ft_strlen(str), elem->hex, elem->flag);
	str_len = (elem->hex != 0) ? str_len + ft_strlen(elem->hex) : str_len;
	//printf("STR%s elem->padding%d elem->width %d elem->flag %d str_len %d\n", str, elem->padding, elem->width, elem->flag, str_len);
	if (elem->padding == '0')
	{
		//printf("elem->padding == '0'\n");
		len = (elem->flag ? prf_putchar(elem->flag) : 0);
		len += (elem->hex ? prf_putstr(elem->hex) : 0);
	}
	if (!elem->left)
	{
		//printf("!elem->left\n");
		//printf("len %zu\n", len);
		if (elem->flag)
			str_len++;
		len += prf_nbr_putchar(elem->padding, elem->width - str_len);
		//printf("len %zu\n", len);
	}
	if (elem->padding == ' ')
	{
		//printf("p->padding == ' ' str %s elem->width %d\n", str, elem->width);
		//printf("elem->hex %s\n", elem->hex);
		len += elem->flag ? prf_putchar(elem->flag) : 0;
		len += (elem->hex) ? prf_putstr(elem->hex) : 0;

		//len += prf_nbr_putchar(elem->padding, elem->width - str_len);
	}
	//print_str_ln(str, ft_strlen(str)); ////print numbers
	//len += (ft_strchr("cC", elem->type) && ft_strlen(str) == 0) ? ft_char(str) : 0;
	//printf("ft_strlen %zu\n", ft_strlen(str));

	print_str_ln(str, ft_strlen(str));
	//len += (elem->type && ft_strchr("cC", elem->type) && ft_strlen(str) == 0) ? ft_char(str) : 0;
	if (elem->left)
	{
		//printf("elem->left\n");
		//printf("len %zu\n", len);

		if (elem->flag)
			str_len++;
		len += prf_nbr_putchar(elem->padding, elem->width - str_len);
		//printf("str_len %d\n", str_len);
	}
	//printf("elem->left %d elem->width %d elem->flag %d\n", elem->left, elem->width, elem->flag);
	free(str);
	//printf("len %zu\n", len);
	return (len);
}





size_t		print_atoi_nbr(va_list arg, t_bone *elem)
{
	char 		*str;
	intmax_t  	bigmin;
	uintmax_t	bighigh;
	size_t 	len;

	len = 0;
	str = NULL;
	if (elem->type && ft_strchr("dDi", elem->type))
	{
		bigmin = intmax_cast(va_arg(arg, intmax_t), elem);
		if (bigmin < 0)
		{
			//printf("minus\n");
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

	//printf("!!!!!!!!!!!!!!bighigh %zu\n", bighigh);

	if (bighigh == 0 && (elem->type && ft_strchr("oO", elem->type)))
	{
		if (elem->hex)
			free(elem->hex);
		elem->hex = NULL;
	}
	//printf("print_atoi_nbr elem->mod_l %d\n", elem->mod_l);
	//if (bighigh > 0)		
	//printf("elem->precis %d\n", elem->precis);
	if ((bighigh == 0 && elem->type && (!ft_strchr("poO", elem->type) || (elem->hex && ft_strchr("oO", elem->type) && elem->precis))) || (elem->hex && ft_strchr("oO", elem->type) && elem->precis > 0))
	{
		if (elem->hex)
			free(elem->hex);
		elem->hex = NULL;
	}	
	if ((bighigh == 0 && elem->precis == 0 && elem->width == 0) && (elem->type && !ft_strchr("poO", elem->type)))
		return (len);
	else
	{
		//printf("%s, bighigh %ju\n", str, bighigh);
		str = itoa_base(elem, bighigh);
		len = ft_strlen(str);// + (elem->flag != 0 ? 1 : 0);	//count str length to output
		//printf("print_atoi_nbr len %zu\n", len);

		len += print_str_with_flags(str, elem, len);									//print flags
	}
	//else
	//	len += prf_nbr_putchar(elem->padding, elem->width);
	//print_str_ln(str, ft_strlen(str));												//print numbers
	//free(str);
	return (len);
}


char	*str_join_float(char *str1, char *str2)
{
	char 	*str3;

	if (!str1 || !str2)
		return (NULL);
	str3 = (char *)malloc(sizeof(str3) * ((ft_strlen(str1)) + (ft_strlen(str2))) + 1);
	if (!str3)
		return (NULL);
	*str3 = 0;
	str3 = ft_strcat(ft_strcat(str3, str1), str2);
	free(str1);
	free(str2);
	return (str3);
}


long double 	nbr_power(long double elmbase, long double power)
{
	long double i;
	long double num;

	i = 1;
	num = elmbase;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);	
	while (i++ <= power)
	{
		num *= elmbase;
		//printf("num %Lf\n", num);
	}
	return (num);
}

long double 	fix_droby_float(long double elmbase, long double nbr)
{
	long double		u;
	uintmax_t 		i;

	u = 1;
	//printf("fix_droby_float %.20Lf\n", nbr);
	while (u < nbr / nbr_power(elmbase, 7))
	{
		u *= nbr_power(elmbase, 7);
		//printf("!!!round integerpower %Lf\n", u);
		//i = (uintmax_t)(nbr / u);
		//	printf("i %zu u %Lf\n", i, u);
		//nbr -= i * u;
			//printf("nbr %Lf u %Lf\n", nbr, u);
		//u /= nbr_power(elmbase, 8);
	}
	//printf("integerpower u %.20Lf nbr %.20Lf\n", u, nbr);
	while (nbr >= 1)
	{
		i = (uintmax_t)(nbr / u);
			//printf("i %zu u %Lf\n", i, u);
		nbr -= i * u;
			//printf("nbr %Lf u %Lf\n", nbr, u);
		u /= nbr_power(elmbase, 7);
	}
	//printf("fix_droby_float nbr end  u %.20Lf nbr %.20Lf\n", u, nbr);	
	return (nbr);
}

long double 	fix_droby(t_bone *elem, long double nbr)
{
	long double		prefix;
	long double		first;	
	int				i;

	//if ((i = elem->precis) != -1)
	i = elem->precis;
	if (elem->precis != -1)
	{
		first = fix_droby_float(elem->base, nbr);
		prefix = nbr - first;
		//printf(" fix_droby nbr %.20Lf first %.20Lf prefix %.20Lf\n", nbr, first, prefix);
		while (i-- > 0)
		{	
			//printf("first i %d\n", i);		
			first *= elem->base;
			//printf("first %.20Lf\n", first);
		}
		//printf(" fix_droby first %.20Lf\n", first);
		if (fix_droby_float(elem->base, first) < .5)
		{
			//printf("yep < .5 \n");
			first -= fix_droby_float(elem->base, first);
			first += .1;
			//printf("yep first %Lf\n", first);
		}
		else if (fix_droby_float(elem->base, first) >= .5)
		{
			//printf("yep >= .5 first %.20Lf\n", first);
			first -= fix_droby_float(elem->base, first);
			first += 1.1;
			//printf("yep m %Lf\n", m);			
		}
		//printf("i %d\n", i);
		while (++i < elem->precis)
			first /= elem->base;
		//printf("fix_droby prefix %.20Lf first %.20Lf prefix+first %.20Lf\n", prefix, first, prefix + first );
	//printf("fix_droby nbr %.20Lf first %.20Lf nbr+first %.20Lf\n", nbr, first, nbr + first );
		return (prefix + first);
	}
	return (nbr);
}

char 	*build_mantissa(t_bone *elem, long double nbr)
{
	long double 	val;
	//long double 	temp_val;
	uintmax_t 		i;
	int 	tmp;
	//int 	base;
	char 	*str;
	//int 	j;

	//i = j;
	tmp = elem->precis;
	//elem->precis = 0;//itoa base
	val = 1;
	//temp_val = 100000000000000;
	str = ft_memalloc(sizeof(str));
	/*temp_val = fix_droby(elem, nbr);
	printf("temp_val %Lf\n", temp_val);	
	if ((uintmax_t)(nbr / val) == 0)
	{
		while (val >= 1)
		{
			i = (uintmax_t)(nbr / val);
			if (i == 0)
				i = 1;
			//printf("mantissa i %ju\n", i);
			str = str_join_float(str, itoa_base(elem, i));
			nbr -= i * val;			
			val /= elem->base;
		}
		return (str);
	}*/

	elem->precis = 0;//itoa base
		//printf("val %.40Lf\n", temp_val * 10000000000000000);
	while (val < nbr / elem->base)
	{
		val *= elem->base;
		//printf("val %.100Lf\n", val);
	}
	
	//str = ft_memalloc(sizeof(str));
	//printf("val %.40Lf\n", val / 1);

	while (val >= 1)
	{
		//printf("val %Lf nbr %Lf value %ju\n", val, nbr, (uintmax_t)(nbr / val));
		i = (uintmax_t)(nbr / val);
		//printf("mantissa i %ju\n", i);
		str = str_join_float(str, itoa_base(elem, i));
		//if (i != 1)
		//	i = 1;
		nbr -= i * val;			
		val /= elem->base;
	}
	//printf("str %s\n", str);
	elem->precis = tmp;
	if (elem->precis > 0) 
		str = str_join_float(str, ft_strdup("."));
	//printf("uintmax_t %ju\n", UINTMAX_MAX);
	return (str);
}



long double 	build_float(t_bone *elem, long double droby)
{
	long double 	val;
	long double 	nbr;
	uintmax_t 		i;

	val = 1;
	//i = 1;
	//printf("RRRRR %lu\n", (uintmax_t)34634634643.457856856868 / 1);

	//get_width(elem, droby);
	nbr = fix_droby(elem, droby);
	while (nbr >= 1)
	{
		i = (uintmax_t)(nbr / val);
		//printf("i %zu nbr %Lf\n\n", i, nbr);
		//printf("i %zu nbr %.20Lf\n\n", i, nbr);
		if (i == 0)
			return (nbr);
		nbr -= i * val;
		if (i == 0)
			return (i);
		//printf("nbr %.20Lf\n", nbr);

		val /= 1;
	}
	//printf("nbr %Lf\n", nbr);
	return (nbr);
}

char 	*build_float_join_str(t_bone *elem, long double nbr)
{
	int 	i;
	int 	j;
	//int 	base;
	char 	*str;

	j = elem->precis;
	elem->precis = 0;//itoa base
	//if (elem->g_mode == 1) // gG behavior
	//	j = 5;
	str = ft_memalloc(sizeof(str));
	//printf("nbr %Lf\n", nbr);
	while (j > 0 || (j < 0 && nbr))
	{
		//printf("build_float_join_str nbr %.16Lf\n", nbr);
		i = nbr * elem->base;
			//printf("build_float_join_str nbr %.40Lf i %d elem->precis\n", nbr, i);
		//if (j == 1 && nbr >= .55 && !elem->g_mode)
		if (j == 1 && nbr >= .55)
			i++;
		/*if (j == 1 && nbr <= 0.1 && elem->g_mode == 1)
		{
			printf("YEP\n");
			elem->g_mode_on = 1;		
		}*/
		if (i != -2147483648)
		{
			//printf("onr\n");
			str = str_join_float(str, itoa_base(elem, i));
		}
		else
		{
			//printf("yeop\n");
			elem->precis = j;
			return (str_join_float(str, itoa_base(elem, nbr)));	
		}
		nbr *= elem->base;
		nbr -= i;
		j--;
	}
	return (str);
}

/*void		prf_suffix(t_bone *elem, char *str)
{
	if (ft_strchr("aA", elem->type))
	{
		while (*str != '\0')
		{
			if (*str == 'e')
				*str -= 32;
			str++;
		}		
	}
}*/
void		xx_upper(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'p')
			*str -= 32;
		str++;
	}
	//return (str);
}

/*char	*ft_chrrepl_trailing(char *s, char c, char r)
{
	char *str;
	char a;

	str = s;
	if (s && *s)
	{
		a = *s;
		*s = 0;
		s++;
		while (*s)
			s++;
		if (str - s)
		{			
			while (*(--s) == c)
			{
				//printf("ft_chrrepl_trailing str - s %c\n", *s);
				*s = r;
			}
		}
		*str = a;
	}
	//printf("cherepl str %s\n", str);
	return (str);
}
*/
char		*build_float_str(t_bone *elem, long double nbr, char *str)
{
	/*size_t 	len;
	long double nbr;
	char *str;

	len = 0;
	nbr = 0;
	str = ft_memalloc(sizeof(str));	
	if (elem->mod_l && !ft_strcmp(elem->mod_l, "L"))
		nbr = va_arg(arg, long double);
	else
		nbr = va_arg(arg, double);
	elem->flag = (nbr < 0) ? '-' : elem->flag;
	nbr = (nbr < 0) ? -nbr : nbr;
	elem->precis = (elem->precis == -1) ? 6 : elem->precis;*/
	int				tick;
	int				nmbase;
	long double		l;
	long double		tmp_nbr;

	tick = 0;
	l = 1;
	tmp_nbr = nbr;
	nmbase = (ft_strchr("aA", elem->type) ? 2 : elem->base);
	if (elem->type && ft_strchr("fF", elem->type))
	{		
		//if (gG)
		//printf("nbr %Lf\n", nbr);
		str = build_mantissa(elem, nbr);
			//printf("print_float_nb %s\n", str);
		nbr = build_float(elem, nbr);
		//nbr = (elem->precis >= .5) ? nbr + .000001 : nbr;
			//printf("print_float_nb  nbr%Lf\n", nbr);
		str = str_join_float(str, build_float_join_str(elem, nbr));
		//printf("print_float_nb %s\n", str);
		//if (elem->g_mode == 1)
		//	str = ft_chrrepl_trailing(ft_chrrepl_trailing(str, '0', 0), '.', 0);
	}
	else 
	{
	//!!!!!!!!!!!!!!!!!!! gGeEaA		/
		if (nbr >= 1)
		{
			while (nbr / l >= nmbase)
			{
				tick++;
				l *= nmbase;
			}
		}
		else
		{
			while (nbr && nbr / l <  1)
			{
				tick++;
				l /= nmbase;
			}
		}
		//printf("nbr %.20Lf tmp_nbr %.20Lf l %.20Lf tick %d\n", nbr, tmp_nbr, l, tick);
		str = build_mantissa(elem, tmp_nbr / l);
		//printf("print_float_nb mant %s\n", str);
		nbr = build_float(elem, tmp_nbr / l);
		//printf("print_float_nb  nbr%Lf\n", nbr);

		//if (tick == 0 && nmbase == 2)
		//	str = str;
		if (elem->precis == -1 && (tick != 0 && nmbase == 2 && nbr > 0))
			str = str_join_float(str, ft_strdup("."));

		str = str_join_float(str, build_float_join_str(elem, nbr));
		//printf("print_float_nb %s\n", str);
		//if (elem->g_mode == 1)
		//	str = ft_chrrepl_trailing(ft_chrrepl_trailing(str, '0', 0), '.', 0);
		str = str_join_float(str, (nmbase != 2) ? ft_strdup("e") : ft_strdup("p"));
		str = str_join_float(str, ((tmp_nbr >= 1 || tmp_nbr == 0) ? ft_strdup("+") : ft_strdup("-")));
		if (tick < 10 && nmbase != 2)
			str = str_join_float(str,  ft_strdup("0"));
		elem->base = 10;//16 change to 10 on  aA
		str = str_join_float(str, itoa_base(elem, tick));
	//elem->xx  itoa_base(elem, bighigh);
		(elem->xx == 1) ? xx_upper(str) : str;
		
		
	}

		//printf("print_float_nb %s\n", str);

	//len = ft_strlen(str);
	//len += print_str_with_flags(str, elem, len);
	return (str);
}


size_t		print_floate_nbr(va_list arg, t_bone *elem)
{
	size_t			len;
	long double		nbr;
	//long double l;
	//long double tmp_nbr;
	char *str;
	//int  tick;

	len = 0;
	nbr = 0;
	//l = 1;
	//tick = 0;
	str = NULL;
	if (elem->mod_l != -1 && elem->mod_l == 4)		//L
		nbr = va_arg(arg, long double);
	else
		nbr = va_arg(arg, double);
	//printf("elem->mod_l %s\n", elem->mod_l);
	//printf("nbr %Lf\n", nbr);
	elem->flag = (nbr < 0) ? '-' : elem->flag;
	//printf("nbr %.20Lf\n", nbr);
	nbr = (nbr < 0) ? -nbr : nbr;
	//tmp_nbr = nbr;// e
	//printf("nbr %Lf\n", nbr);
	elem->precis = (elem->precis == -1 && !ft_strchr("aA", elem->type)) ? 6 : elem->precis;

	/*if (ft_strchr("gG", elem->type))
	{
		elem->precis = (elem->precis == 0) ? 1 : elem->precis;
		if ((nbr && nbr < .00001) || nbr_power(elem->base, elem->precis) <= nbr)
			elem->type -= 2;
		else
			elem->type -= 1;
		elem->g_mode = 1;		
		str = build_float_str(elem, nbr, str);
		//str = ft_chrrepl_trailing(ft_chrrepl_trailing(str, '0', 0), '.', 0);
	}
	else*/
	if ((str = build_float_str(elem, nbr, str)))
	{
		//printf("Str %s\n", str);
		len = ft_strlen(str);
		len += print_str_with_flags(str, elem, len);
	}

	//printf("Str %s\n", str);
	return (len);
}






char 	*build_char(va_list arg, t_bone *elem)
{
	//int 		len;
	char 		*str;

	//len = 0;
	str = NULL;
	//printf("build_char %s\n", elem->mod_l);
	//printf("arg %d\n", va_arg(arg, wint_t));
	
	if (elem->mod_l != -1 && elem->mod_l == 2 && MB_CUR_MAX > 1)//l
	{
		//printf("!ft_strcmp(elem->mod_l\n");
		str = utf_char_unicode((wchar_t)va_arg(arg, wint_t));
	}
	else
	{
		//printf("str %s\n", str); 
		//str = ft_memalloc(sizeof(*str) * 2);
		//*str = (char)va_arg(arg, int);
		if (!(str = ft_memalloc(2)))
			return (NULL);
		*str = (char)va_arg(arg, int);
	}
	//len = prf_putstr(str);
	//free(str);
	//return (len);
	return (str);
}

char 	*build_str_char(va_list arg, t_bone *elem)
{
	//int 		len;
	char 		*str;
	//size_t 	n;

	//len = 0;
	//str = NULL;
	//printf("elem->mod_l %s\n", elem->mod_l);
	if (elem->mod_l != -1 && elem->mod_l == 2)
	{
		if (elem->precis >= 0)
			str = utf_char_len_concat(va_arg(arg, wchar_t*), (size_t)elem->precis);
		else
			str = utf_char_find_len_concat(va_arg(arg, wchar_t*));
	}
	else
	{
		//printf("n %zu\n", (size_t)elem->precis);
		if (elem->precis >= 0)
			str = ft_strndup(va_arg(arg, char*), (size_t)elem->precis);
		else
			str = ft_strdup(va_arg(arg, char*));
	}
	if (!str && elem->precis != 0)
		str = ft_strdup("(null)");
	else if (!str)
		str = ft_memalloc(sizeof(str));
	return (str);
}

size_t 		parse_arg(va_list arg, t_bone *elem, size_t ln)
{
	size_t 	len;
	size_t 	clen;
	char 	*str;

	len = 0;
	str = NULL;	
	//printf("elem->type %c\n", elem->type);
	//printf("STR%s elem->padding%d elem->width %d elem->flag %d elem->left %d\n", str, elem->padding, elem->width, elem->flag, elem->left);
	if (elem->type && ft_strchr("cC", elem->type))
	{
		//len = build_char(arg, elem);
		if (!(str = build_char(arg, elem)))
			return (0);
		len += ((ft_strlen(str) == 0) ? 0 : ft_strlen(str));
		clen = len;
		if (clen == 0 && !elem->left)
			len += prf_nbr_putchar(elem->padding, elem->width - 1);
		len += ft_strlen(str) > 0 ? print_str_with_flags(str, elem, len) : ft_char(str);
		if (clen == 0 && elem->left == 1)			
			len += prf_nbr_putchar(elem->padding, elem->width - 1);
		//free(str);
		//len += print_str_with_flags(str, elem, len); //`MALLOC error
	}
	else if (elem->type && ft_strchr("sS", elem->type))
	{
		if (!(str = build_str_char(arg, elem)))
			return (0);
		len += ft_strlen(str);
		len += print_str_with_flags(str, elem, len);
		//len += build_str_char(arg, elem);
	}
	else if (elem->type && ft_strchr("pdDioOuUxXb", elem->type) && arg)
	{	
		//printf("elem->type %c\n", elem->type);	
		len += print_atoi_nbr(arg, elem);
	}
	else if (elem->type && ft_strchr("fFeEaAgG", elem->type))
	{	
		//printf("elem->type %c\n", elem->type);	
		len += print_floate_nbr(arg, elem);
	}
	//else if (elem->type && ft_strchr("eE", elem->type))
	//{
	//	len += print_floate_nbr(arg, elem);
	//}
	else if (elem->type == 'n')
	{
		return (*va_arg(arg, int*) = ln);
	}
	/*else if (elem->type == '%')
	{
		//printf("len %zu\n", len);
		//str = ft_memalloc(2);
		// *str = elem->type;
		len += print_str_with_flags(str, elem, 1);
		printf("len %zu\n", len);
		return (len);
	}*/
	else if ((str = ft_memalloc(2)))
	{
		//printf("elem->type %d\n", elem->type);
		*str = elem->type;
		//len += prf_putstr(str);
		//printf("len %zu\n", len);
		len++;
		//len += (elem->type && ft_strchr("cC", elem->type) && ft_strlen(str) == 0 ? 1 :ft_strlen(str)) + ft_strlen(elem->hex) + (elem->flag != 0 ? 1 : 0);print_str_with_flags(str, elem, 1);

		//printf("parse_arg len %zu str %zu\n", len, ft_strlen(str));
		//if (ft_strlen(str) == 0)
		//	len = 0;
		//printf("parse_arg str %d len %zu str %zu\n", *str, len, ft_strlen(str));
		if (elem->type && !ft_strchr("0", elem->type))
			len += print_str_with_flags(str, elem, 1);
		//if (*str == 10 || *str == 0)
		//	len = 0;
		else
		{
			len = 0;
			free(str);
		}

		//printf("parse_arg str %d len %zu str %zu\n", *str, len, ft_strlen(str));
		//printf("parse_arg len %zu str %zu\n", len, ft_strlen(str));		
		
	}
	
	//len += print_str_with_flags(str, elem, len);
	//else
		//len += print_str_with_flags(str, elem, len);
	//if (str)
	//	free(str);
	//printf("parse_arg len %zu\n", len);
	return (len);
}

void	fill_flag(const char **f, t_bone *elem)
{
	//printf("f %d\n", **f);
	while (**f == '+' || **f == ' ' || **f == '-' || **f == '0' || **f == '#')
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
		{
			if (elem->hex)
				free(elem->hex);
			elem->hex = NULL;
			elem->hex = ft_strdup("#");	
		}
		//else
		//	break ;	
		(*f)++;
	}
	//printf("fill_flag elem->hex %s\n", elem->hex);
	//printf("f %d\n", **f);
	//printf("elem->left %d\n", elem->left);
}


void 	fill_width(const char **format, va_list arg, t_bone *elem)
{
	//printf("fill_width %c\n", **format);
	while (**format == '*')
	{
		elem->width = 0;
		if ((elem->width = va_arg(arg, int)) < 0)
		{
			elem->width = elem->width * -1;
			elem->left = 1;
			elem->padding = ' ';
		}
		(*format)++;
	}
	if (**format >= '1' && **format <= '9')
	{
		elem->width = 0;
		while (**format >= '0' && **format <= '9')
		{
			elem->width = elem->width * 10 + **format - '0';
			(*format)++;
		}
	}
	fill_flag(format, elem);
	//printf("fill_width %d\n", **format);
	//printf("elem->width %d\n", elem->width);
}

void 	fill_precis(const char **format, va_list arg, t_bone *elem)
{
	//printf("fill_precis %c\n", **format);
	while (**format == '.')
	{
		elem->precis = 0;
		//printf("fill_precis %zu\n", elem->precis);
		(*format)++;
		if (**format == '*')
		{
			elem->precis = va_arg(arg, int);
			if (elem->precis < 0)
			{
				elem->precis = -1;
			}
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
	//printf("fill_precis %c\n", **format);
	fill_width(format, arg, elem);
	//printf("fill_precis %d\n", **format);
	//printf("fill_precis %zu\n", elem->precis);
}

/*static int 		find_length(t_bone *elem)
{
	int 	i;
	//char 	*str[7] = {"h", "hh", "l", "ll", "L", "j", "z"};
	//int 	str[7] = {0, 1, 2, 3, 4, 5, 6};

	i = 0;
	while (i < 7)
	{
		if (i == elem->mod_l)
			return (i);
		i++;
	}
	return (0);
}*/

static int 		is_present(int i, t_bone *elem)
{
	int 	j;

	j = -1;
	if (elem->mod_l == -1)
		return (1);
	while (++j < 7)
	{
		if (j == elem->mod_l)
		{
			if (i >= elem->mod_l)
				return (1);
		}
	}
	return (0);
}

/*
**				The length modifier
**			hh 	h 	l 	ll 	L 	j 	z
** mask		0	1	2	3	4	5	6
**
*/
void	fill_length(const char **format, t_bone *elem)
{
	//printf("fill_length %c\n", **format);
	//char 	*str;

	if (**format && ft_strchr("hljzqL", **format))
	{
		while (**format && ft_strchr("hljzqL", **format))
		{
			//printf("fill_length %c\n", **format);

			//str = ft_memalloc(2);
			//*str = (char)(*format)[0];
			if ((**format == 'h' && (*format + 1)[0] == 'h' ) && is_present(0, elem))
			{
				elem->mod_l = 0;
				(*format)++;
			}
			if ((**format == 'h' && (*format - 1)[0] != 'h') && is_present(1, elem))
				elem->mod_l = 1;			
			if ((**format == 'l' && (*format - 1)[0] != 'l' ) && is_present(2, elem))
				elem->mod_l = 2;
			if ((**format == 'l' && (*format + 1)[0] == 'l') && is_present(3, elem))
			{
				elem->mod_l = 3;
				(*format)++;
			}
			if (**format == 'L' && is_present(4, elem))
				elem->mod_l = 4;
			if (**format == 'j' && is_present(5, elem))
				elem->mod_l = 5;
			if (**format == 'z' && is_present(6, elem))
				elem->mod_l = 6;
			(*format)++;
		}
		//if (str)
		//	free(str);
		//elem->mod_l = "l";
		//printf("fill_length %c\n", (*format - 1)[0]);
		//printf("f %d\n", **format);
	}
	//printf("fill_length %c elem->mod_l %d\n", **format, elem->mod_l);
	fill_flag(format, elem);
	//printf("fill_length end %c\n", **format);
	//if (**format && ft_strchr("hljzqL", **format))
	//	fill_length(format, elem);
	//printf("fill_length end %c\n", **format);
}

void	fill_type(const char **format, t_bone *elem)
{
	//printf("fill_type %c\n", **format);
	//printf("fill_type elem->type %d\n", **format);
	if (**format && ft_strchr("sSpdDioOuUxXcCbfFeEaA", **format))
	{		
		elem->xx = (ft_strchr("XEA", **format)) ? 1 : 0;
		elem->base = (ft_strchr("b", **format) ? 2 : elem->base);
		elem->base = (ft_strchr("oO", **format) ? 8 : elem->base);
		elem->base = (ft_strchr("pxXaA", **format) ? 16 : elem->base);
		if (**format && ft_strchr("DOUCS", **format))
		{
			//if (elem->mod_l)
			//	free(elem->mod_l);
			//if (elem->mod_l != -1)
			//	elem->mod_l = -1;
			//elem->mod_l = ft_strdup("l");//2 == l
			elem->mod_l = 2;
		}
	}	
	elem->flag = ((**format && !ft_strchr("dDifFfFeEaA", **format)) ? 0 : elem->flag);
	elem->padding = ((**format && ft_strchr("pdDioOuUxXb", **format)) && (elem->precis >= 0)) ? ' ' : elem->padding;
	//if (**format && !ft_strchr("0", **format))
	elem->type = **format;
	//if (**format == 10)
	//	elem->type = '%';
	//printf("fill_type elem->type %d\n", **format);
}

void			fill_hex(const char **format, t_bone *elem)
{
	//printf("fill_hex %d\n", **format);
	if (elem->hex || ft_strchr("paA", **format))//#
	{
		if (elem->hex)
			free(elem->hex);
		elem->hex = NULL;
		if (**format && ft_strchr("oO", **format))
			elem->hex = ft_strdup("0");
		else if (**format && ft_strchr("pxa", **format))
			elem->hex = ft_strdup("0x");
		else if (**format && ft_strchr("XA", **format))
			elem->hex = ft_strdup("0X");
		else if (**format == 'b')
			elem->hex = ft_strdup("0b");
		else
			elem->hex = NULL;
		//{
		//	elem->hex = NULL;
		//	return ;
		//}
		//elem->flag = 0;
	}
	else
		elem->hex = NULL;
}

void	fill_mas(t_bone *elem)
{
	//elem->mod_l = NULL;
	elem->mod_l = -1;
	elem->type = -1;
	elem->hex = NULL;
	elem->padding = ' ';
	elem->left = 0;
	elem->flag = 0;
	elem->base = 10;
	elem->width = 0;
	elem->precis = -1;
	elem->prefix = 0;
	elem->xx = 0;
	//elem->g_mode = 0;
	//elem->g_mode_on = 0;
}

void	build_flags(const char **format, va_list arg, t_bone *elem)
{
	fill_mas(elem);
	fill_flag(format, elem);
	fill_width(format, arg, elem);
	fill_precis(format, arg, elem);
	fill_length(format, elem);
	fill_type(format, elem);

	fill_hex(format, elem);
}

int 	ft_printf(const char *format, ...)
{
	size_t 	len;
	size_t 	tick;
	const char	*e;
	va_list arg;
	t_bone		*elem;

	va_start(arg, format);
	tick = 0;
	elem = (t_bone *)malloc(sizeof(t_bone));
	//e = format;
	while (*format)
	{
		if (*format == '%')
		{
			e = format + 1;
			//printf("ft_printf e %s\n", e);
			//if(!(len = parse_arg(&format, arg)))
			//	break ;
			build_flags(&e, arg, elem);
			//printf("elem->mod_l %s\n", elem->mod_l);
			//
			//	write(1, &(*format), 1);
			len = parse_arg(arg, elem, tick);
			//printf("len %zu elem->type %d format %s\n", len, elem->type, format);

			//if (!ft_strcmp(format, "%"))
			//	write(1, "%", 1);
			if (elem->hex)
				free(elem->hex);
			tick += len;
			format = e;
		}
		else
		{
			//printf("len %zu elem->type %d e %s\n", len, elem->type, format);
			write(1, &(*format), 1);
			tick++;
		}
		//printf("len %zu elem->type %d e %s\n", len, elem->type, format);
		//free(elem->mod_l);
		format += *format ? 1 : 0;
	}	

	free(elem);
	//printf("tick %zu\n", tick);
	va_end(arg);
	return (tick);
}

/*int 		main(void)
{
	int i, j;
	i = 0;
	j = 0;
		ft_printf("rx %#llx\n", 9223372036854775807);
	//printf("x %#llx", 9223372036854775807);

	i =	ft_printf("%#8x\n", 42);
	j = printf("%#8x\n", 42);
	printf("My %d Basic %d\n", i, j);

	i =	ft_printf("%5%\n");
	//j = printf("%5%\n");
	printf("My %d Basic %d\n", i, j);

	i =	ft_printf("%   %", "test");
	//j = printf("%   %", "test");
	printf("My %d Basic %d\n", i, j);

	i =	ft_printf("%#x\n", 0);
	j = printf("%#x\n", 0);
	printf("My %d Basic %d\n", i, j);


	i =	ft_printf("AAAAA@moulitest: %#.x %#.0x\n", 0, 0);
	j = printf("@moulitest: %#.x %#.0x\n", 0, 0);
	printf("My %d Basic %d\n", i, j);


	i =	ft_printf("%x\n", 4294967296);
	//j = printf("%x", 4294967296);

	i =	ft_printf("NBR@moulitest: %.d %.0d", 42, 43);
	//j = printf("@moulitest: %.d %.0d", 42, 43);
	printf("My %d Basic %d\n", i, j);
	printf("My %d Basic %d\n", i, j);


	printf("\nARG\n");
	ft_printf("%");

	printf("\n");
	printf("\nARG\n");
	ft_printf("%%");

	printf("\n\n");
	ft_printf("%lx\n", 4294967296);
	   printf("%lx\n", 4294967296);

	ft_printf("%#llx\n", 9223372036854775807);
	printf("\n");
	   printf("%#lx\n", 9223372036854775807);


	  ft_printf("{%f}{%F}\n", 1.42, 1.42);
	  printf("{%f}{%F}\n", 1.42, 1.42);

	 i = ft_printf("A@moulitest: %.d %.0d\n", 0, 0);
	 j = printf("@moulitest: %.d %.0d\n", 0, 0);
	 printf("My %d Basic %d\n", i, j);

	 i = ft_printf("{%*c}\n", -15, 0);
	 j = printf("{%*c}\n", -15, 0);
	 printf("My %d Basic %d\n", i, j);


	i = ft_printf("% ");
	printf("My %d\n", i);

	ft_printf("%ll#x\n", 9223372036854775807);

	ft_printf("%zhd\n", 4294967296);


	i = ft_printf("%hhd\n", 128);
	printf("My %d\n", i);

	ft_printf("%zhd\n", 4294967296);

	i = ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	printf("My %d\n", i);


		i = ft_printf("% +-#5.4hd\n", -25);
	printf("My %d\n", i);

			i = ft_printf("% +-#5.4tu\n", -25);
	printf("My %d\n", i);

		i =	ft_printf("%e\n", 	-0.9265e-2);
	j = printf("%e\n", 	-0.9265e-2);
	printf("Moi %d Base : %d\n", i, j);

//(printf_, "|%3 %02 %1$d|", 1024, 0.999643287658734658368543L, 42);
	ft_printf("% 0+-#5.4hhu", 	25);
	ft_printf("%zhd\n", 4294967296);

	int z;
	ft_printf("some text %n\n", &z);
	printf("z %d\n", z);

	//ft_printf("%f\n", 1444565.4576242);

	ft_printf("%.20f\n", -14445654446466463464367436437634734774574574574587458450901241252352372355424242.2456756769769792);
	printf("%.20f\n", -14445654446466463464367436437634734774574574574587458450901241252352372355424242.2456756769769792);

	//3.000000	
	ft_printf("%La\n", 3.0L);
	printf("%La\n", 3.0L);

	ft_printf("%a\n", 3.0);
	printf("%a\n", 3.0);

	ft_printf("%.2a\n", 3.0457457);
	printf("%.2a\n", 3.0457457);

	//ft_printf("%.20f\n", -346340.14445654446466463464367436437634734774574574574587458450901241252352372355424242);
	//printf("%.20f\n", -346340.14445654446466463464367436437634734774574574574587458450901241252352372355424242);
	//ft_printf("%.20f\n", 34.457457);
	//printf("%.20f\n", 34.457457);


	ft_printf("{%05.s}\n", 0);

		ft_printf("%La\n", 9.0456L);
	printf("%La\n", 9.0456L);

			ft_printf("%e\n", 9.00);
	printf("%e\n", 9.00);

	ft_printf("dd %d\n", 0);

	ft_printf("dd % ##-**-+-#**-++#5.4hho\n", 456);
	//ft_printf("%b\n", 1);
	//ft_printf("%b\n", 2);
	//ft_printf("%b\n", 3);
	//ft_printf("%b\n", 4);
	//ft_printf("%b\n", 5);
	//ft_printf("%b\n", 6);
	//ft_printf("%b\n", 7);
	//ft_printf("%b\n", 8);
	//ft_printf("%b\n", 9);
	//ft_printf("%#b\n", 128);

	return (0);
}*/

