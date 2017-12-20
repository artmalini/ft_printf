#include "ft_printf.h"


char	*ft_strncpy(char *dst, const char *src, size_t len)
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

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
		if (*s++ == 0)
			return (0);
	return ((char*)s);
}

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

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;

	s = b;
	while (len--)
		*s++ = (unsigned char)c;
	return (b);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2 && s1++ && s2++)
		;
	return ((unsigned char)*s1 - (unsigned char)*s2);
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

char	*ft_strdup(const char *s1)
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

char	*ft_strcat(char *s1, const char *s2)
{
	ft_strcpy(&s1[ft_strlen(s1)], s2);
	return (s1);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char *str;

	if (!s1 || !s2)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (str)
	{
		*str = 0;
		str = ft_strcat(ft_strcat(str, (char*)s1), (char*)s2);
		free(s1);
		free(s2);
	}
	return (str);
}

void	ft_strrev(char *s)
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
}

char	*ft_strndup(const char *s1, size_t len)
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

char	*ft_strucase(char *s)
{
	char *str;

	str = s;
	if (s)
	{
		while (*s)
		{
			if (*s >= 'a' && *s <= 'z')
				*s -= 32;
			s++;
		}
	}
	return (str);
}

char	*ft_chrrepl_trailing(char *s, char c, char r)
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
			while (*(--s) == c)
				*s = r;
		*str = a;
	}
	return (str);
}

unsigned short	ft_uintmax_len(uintmax_t num, unsigned short base)
{
	unsigned int	i;

	i = 0;
	while (num != 0 || i == 0)
	{
		i++;
		num = num / base;
	}
	return (i);
}







int	ft_putchar_fd(char c, int fd)  //мой void
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnstr_fd(int fd, char *s, int n) //нету
{
	int len;

	len = 0;
	if (s && n)
	{
		len = ft_strlen(s);
		if (n < len)
			len = n;
		write(fd, s, len);
	}
	return (len);
}

int	ft_putnchar_fd(int fd, char c, int n) //нету
{
	int count;

	count = 0;
	while (n-- > 0)
	{
		write(fd, &c, 1);
		count++;
	}
	return (count);
}

int	ft_putstr_fd(char const *s, int fd) //мой void
{
	int len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
		write(fd, s, len);
	}
	return (len);
}

/*const char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
		if (*s++ == 0)
			return (0);
	return ((char*)s);
}*/











long double	ft_ld_integerpower(long double nb, long double power)
{
	long double i;
	long double num;

	num = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = 1;
	while (i++ < power)
		num *= nb;
	return (num);
}



long double	ft_uld_get_mantissa(long double ld, short base)
{
	long double	u;
	uintmax_t	d;

	u = 1;
	while (u < ld / ft_ld_integerpower(base, 8))
		u *= ft_ld_integerpower(base, 8);
	while (ld >= 1)
	{
		d = (uintmax_t)(ld / u);
		ld -= d * u;
		u /= ft_ld_integerpower(base, 8);
	}
	return (ld);
}


int	ft_fdprintf(int fd, const char *format, ...)
{
	va_list a_list;
	size_t	count;

	va_start(a_list, format);
	count = ft_vfdprintf(fd, format, a_list);
	va_end(a_list);
	return (count);
}


static char	*ft_wctos(wchar_t c)
{
	char	*s;
	char	*e;

	s = ft_memalloc(sizeof(*s) * 5);
	if ((e = s) && c <= 0x7F)
		*e++ = c;
	else if (c <= 0x7FF)
	{
		*e++ = (c >> 6) + 0xC0;
		*e++ = (c & 0x3F) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		*e++ = (c >> 12) + 0xE0;
		*e++ = ((c >> 6) & 0x3F) + 0x80;
		*e++ = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		*e++ = (c >> 18) + 0xF0;
		*e++ = ((c >> 12) & 0x3F) + 0x80;
		*e++ = ((c >> 6) & 0x3F) + 0x80;
		*e++ = (c & 0x3F) + 0x80;
	}
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
			len -= ft_strlen(t);
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
	return (ft_wtoc_strndup(w, len));
}

/*
** Handles %cC
*/

char		*ft_printf_ctos(t_placehold *p, va_list a_list)
{
	char	*s;

	if (p->length != NULL && !ft_strcmp(p->length, "l") && MB_CUR_MAX > 1)
		s = ft_wctos((wchar_t)va_arg(a_list, wint_t));
	else
	{
		s = ft_memalloc(sizeof(*s) * 2);
		*s = (unsigned char)va_arg(a_list, int);
	}
	return (s);
}

/*
** Handles %sS
*/

char		*ft_printf_str(t_placehold *p, size_t n, va_list a_list)
{
	char	*s;

	if (p->length != NULL && !ft_strcmp(p->length, "l"))
	{
		if (p->prec >= 0)
			s = ft_wtoc_strndup(va_arg(a_list, wchar_t*), n);
		else
			s = ft_wtoc_strdup(va_arg(a_list, wchar_t*));
	}
	else
	{
		if (p->prec >= 0)
			s = ft_strndup(va_arg(a_list, char*), n);
		else
			s = ft_strdup(va_arg(a_list, char*));
	}
	if (!s && p->prec != 0)
		s = ft_strdup("(null)");
	else if (!s)
		s = ft_memalloc(sizeof(*s));
	return (s);
}

static long double	ft_uld_badround(long double ld, int precision, short base)
{
	long double	m;
	long double	c;
	int			i;

	if ((i = precision) != -1)
	{
		m = ft_uld_get_mantissa(ld, base);
		c = ld - m;
		while (i-- > 0)
			m *= base;
		if (ft_uld_get_mantissa(m, base) >= .5)
			m = m - ft_uld_get_mantissa(m, base) + 1.1;
		else
			m = m - ft_uld_get_mantissa(m, base) + .1;
		while (++i < precision)
			m /= base;
		return (c + m);
	}
	return (ld);
}

static char			*ft_uld_mantissatoa(long double ld, int precision,
						short base)
{
	int		i;
	char	*s;

	s = ft_memalloc(sizeof(*s));
	while (precision > 0 || (precision < 0 && ld))
	{
		if (precision)
			precision--;
		i = ld * base;
		s = ft_strjoin_free(s, ft_uitoa_base(i, base, 0, 1));
		ld *= base;
		ld -= i;
	}
	return (s);
}

static char			*ft_uld_itoa(long double ld, int sigfig, int precision,
						short base)
{
	long double	u;
	uintmax_t	d;
	char		*s;

	u = 1;
	while (u < ld / base)
		u *= base;
	s = ft_memalloc(sizeof(*s));
	while (sigfig && (u >= 1 || !ft_strlen(s)))
	{
		d = (uintmax_t)(ld / u);
		s = ft_strjoin_free(s, ft_uitoa_base(d, base, 0, 1));
		if (!(*s == '0' && ft_strlen(s) == 1))
			sigfig--;
		ld -= d * u;
		u /= base;
	}
	if (sigfig && (precision > 0 || precision == -1) && ld)
	{
		precision = sigfig > 0 ? sigfig : precision;
		s = ft_strjoin_free(s, ft_strdup("."));
		s = ft_strjoin_free(s, ft_uld_mantissatoa(ld, precision, base));
	}
	return (s);
}

static char			*ft_printf_ftoa_handler(t_placehold *p, long double ld)
{
	long double	d;
	char		*s;
	short		c;

	if (ft_strchr("fF", p->type))
		s = ft_uld_itoa(ft_uld_badround(ld, p->prec, p->base), p->sigfig,
			p->prec, p->base);
	else if ((d = 1))
	{
		c = 0;
		if (ld >= 1)
			while (ld / d >= p->exp_base && ++c)
				d *= p->exp_base;
		else
			while (ld && ld / d < 1 && ++c)
				d /= p->exp_base;
		s = ft_uld_itoa(ft_uld_badround(ld / d, p->prec, p->base), p->sigfig,
			p->prec, p->base);
		s = ft_strjoin_free(s, ft_strdup(ft_memset(ft_memalloc(2), p->exp_char,
			1)));
		s = ft_strjoin_free(s, (ld >= 1 || ld == 0) ? ft_strdup("+") :
			ft_strdup("-"));
		s = ft_strjoin_free(s, ft_uitoa_base(c, 10, 0, p->exp_len));
	}
	return (s = p->uppercase ? ft_strucase(s) : s);
}

char				*ft_printf_ftoa(t_placehold *p, va_list a_list)
{
	long double	ld;
	char		*s;

	ld = 0;
	if (p->length && !ft_strcmp(p->length, "L"))
		ld = va_arg(a_list, long double);
	else
		ld += va_arg(a_list, double);
	p->sign = (ld < 0 ? '-' : p->sign);
	ld = (ld < 0 ? -ld : ld);
	p->prec = (p->prec == -1 && !ft_strchr("aA", p->type) ? 6 : p->prec);
	if (ft_strchr("gG", p->type))
	{
		p->prec = (p->prec == 0 ? 1 : p->prec);
		p->sigfig = p->prec;
		if ((ld && ld < .00001) || ft_ld_integerpower(p->base, p->prec) <= ld)
			p->type -= 2;
		else
			p->type -= 1;
		s = ft_printf_ftoa_handler(p, ld);
		s = ft_chrrepl_trailing(ft_chrrepl_trailing(s, '0', 0), '.', 0);
	}
	else
		s = ft_printf_ftoa_handler(p, ld);
	return (s);
}


char				*ft_uitoa_base(uintmax_t value, unsigned short base,
						unsigned short uppercase, int digits)
{
	char	*ret;
	char	*dig;
	int		i;

	dig = "0123456789abcdef0123456789ABCDEF";
	dig += 16 * uppercase;
	if ((ret = malloc(sizeof(*ret) * (MAX(ft_uintmax_len(value, base), digits)
		+ 1))))
	{
		i = 0;
		while (value != 0 || (i == 0 && digits != 0) || i < digits)
		{
			ret[i++] = dig[value % base];
			value /= base;
		}
		ret[i] = 0;
		ft_strrev(ret);
	}
	return (ret);
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

static intmax_t		cast_intmax(intmax_t num, t_placehold *p)
{
	if (p->length != NULL)
	{
		if (!ft_strcmp(p->length, "hh"))
			return ((char)num);
		else if (!ft_strcmp(p->length, "h"))
			return ((short)num);
		else if (!ft_strcmp(p->length, "l"))
			return ((long)num);
		else if (!ft_strcmp(p->length, "ll"))
			return ((long long)num);
		else if (!ft_strcmp(p->length, "j"))
			return (num);
		else if (!ft_strcmp(p->length, "z"))
			return (cast_signed_size_t(num));
	}
	return ((int)num);
}

static uintmax_t	cast_uintmax(uintmax_t num, t_placehold *p)
{
	if (p->length != NULL)
	{
		if (!ft_strcmp(p->length, "hh"))
			return ((unsigned char)num);
		else if (!ft_strcmp(p->length, "h"))
			return ((unsigned short)num);
		else if (!ft_strcmp(p->length, "l"))
			return ((unsigned long)num);
		else if (!ft_strcmp(p->length, "ll"))
			return ((unsigned long long)num);
		else if (!ft_strcmp(p->length, "j"))
			return (num);
		else if (!ft_strcmp(p->length, "z"))
			return ((size_t)num);
	}
	else if (p->type == 'p')
		return (num);
	return ((unsigned int)num);
}

/*
** Handles %dDioOuUxXbp. Casts it appropriately, stores its sign in p,
** then returns the unsigned number as string.
*/

char				*ft_printf_itoa_base(t_placehold *p, va_list a_list)
{
	intmax_t	sint;
	uintmax_t	uint;

	if (p->signed_num == 1)
	{
		sint = cast_intmax(va_arg(a_list, intmax_t), p);
		if (sint < 0)
		{
			p->sign = '-';
			uint = -sint;
		}
		else
			uint = sint;
	}
	else
		uint = cast_uintmax(va_arg(a_list, uintmax_t), p);
	if ((uint == 0 && (!ft_strchr("poO", p->type) || (p->hash &&
		ft_strchr("oO", p->type) && p->prec))) || (p->hash &&
		ft_strchr("oO", p->type) && p->prec > 0))
		p->hash = NULL;
	else if (uint > 0)
		p->prec = MAX(ft_uintmax_len(uint, p->base), p->prec);
	return (ft_uitoa_base(uint, p->base, p->uppercase, p->prec));
}


static size_t	ft_puteval(int fd, t_placehold *p, char *str, size_t slen)
{
	size_t	count;

	printf("ft_puteval strt\n");
	count = 0;
	if (p->padding == '0')
	{		
		count += (p->sign ? ft_putchar_fd(p->sign, fd) : 0);
		count += ft_putstr_fd(p->hash, fd);
	}
	if (!p->leftalign)
	{		
		count += ft_putnchar_fd(fd, p->padding, p->width - slen);
		printf("758 ft_puteval !p->leftalign %d count %zu\n", p->leftalign, count);
	}
	if (p->padding == ' ')
	{
		count += (p->sign ? ft_putchar_fd(p->sign, fd) : 0);
		count += ft_putstr_fd(p->hash, fd);
	}
	count += ft_putnstr_fd(fd, str, ft_strlen(str));
	count += (p->type && (ft_strchr("cC", p->type) && ft_strlen(str) == 0) ?
		ft_putchar_fd(*str, fd) : 0);
	if (p->leftalign)
		count += ft_putnchar_fd(fd, p->padding, p->width - slen);
	if (p->length)
		free(p->length);
	printf("773 ft_puteval end count %zu\n", count);
	return (count);
}


size_t			print_eval(int fd, t_placehold *p, va_list a_list, size_t cnt)
{
	char	*str;
	size_t	slen;
	size_t	count;

	str = NULL;
	if (p->type && ft_strchr("dDioOuUxXbp", p->type))
		str = ft_printf_itoa_base(p, a_list);
	else if (p->type && ft_strchr("fFeEgGaA", p->type))
		str = ft_printf_ftoa(p, a_list);
	else if (p->type && ft_strchr("cC", p->type))
		str = ft_printf_ctos(p, a_list);
	else if (p->type && ft_strchr("sS", p->type))
	{
		str = ft_printf_str(p, p->prec, a_list);
		printf("792 print_eval p->prec %d\n", p->prec);
	}
	else if (p->type && p->type == 'n')
		*va_arg(a_list, int*) = cnt;
	else if ((str = ft_memalloc(sizeof(*str) * 2)))
		*str = p->type;
	if (p->type == 'n')
		return (0);
	slen = (ft_strchr("cC", p->type) && ft_strlen(str) == 0 ? 1 :
		ft_strlen(str)) + ft_strlen(p->hash) + (p->sign != 0 ? 1 : 0);
	count = ft_puteval(fd, p, str, slen);
	if (str)
		free(str);
	return (count);
}



void			set_hash(t_placehold *p, const char *e)
{
	if (p->hash || ft_strchr("paA", *e))
	{
		if (ft_strchr("oO", *e))
			p->hash = "0";
		else if (ft_strchr("pxa", *e))
			p->hash = "0x";
		else if (ft_strchr("XA", *e))
			p->hash = "0X";
		else if (*e == 'b')
			p->hash = "0b";
		else
		{
			p->hash = NULL;
			return ;
		}
		p->sign = 0;
	}
}

void	set_flag_field(t_placehold *p, const char **e)
{
	while (1)
	{
		if (**e == '+')
			p->sign = '+';
		else if (**e == ' ')
			p->sign = (p->sign == 0 ? ' ' : p->sign);
		else if (**e == '-')
		{
			p->leftalign = 1;
			p->padding = ' ';
		}
		else if (**e == '0')
			p->padding = (p->leftalign == 0 ? '0' : p->padding);
		else if (**e == '#')
			p->hash = "#";
		else
			break ;
		(*e)++;
	}
}

void	set_width_field(t_placehold *p, const char **e, va_list a_list)
{
	if (**e == '*')
	{
		if ((p->width = va_arg(a_list, int)) < 0)
		{
			p->width = p->width * -1;
			p->leftalign = 1;
			p->padding = ' ';
		}
		(*e)++;
	}
	else if (**e >= '1' && **e <= '9')
	{
		while (**e >= '0' && **e <= '9')
		{
			p->width = p->width * 10 + **e - '0';
			(*e)++;
		}
	}
}

void	set_precision_field(t_placehold *p, const char **e, va_list a_list)
{
	if (**e == '.')
	{
		p->prec = 0;
		(*e)++;
		if (**e == '*')
		{
			p->prec = va_arg(a_list, int);
			if (p->prec < 0)
				p->prec = -1;
			(*e)++;
		}
		else
		{
			while (**e >= '0' && **e <= '9')
			{
				p->prec = p->prec * 10 + **e - '0';
				(*e)++;
			}
		}
	}
}

void	set_length_field(t_placehold *p, const char **e)
{
	//printf("**e %c\n", **e);
	if (**e && ft_strchr("hljzqL", **e))
	{
		(*e)++;
		//printf("905 set_length_field %c\n", **e);
		if (**e == 'h' || **e == 'l')
			p->length = ft_strndup((*e)++ - 1, 2);
		else
			p->length = ft_strndup(*e - 1, 1);
	}
}



void	set_type_field(t_placehold *p, const char *e)
{
	if (*e && ft_strchr("sSpdDioOuUxXcCbfFeEgGaA", *e))
	{
		p->uppercase = (ft_strchr("XEGA", *e) ? 1 : p->uppercase);
		p->base = (*e == 'b' ? 2 : p->base);
		p->base = (ft_strchr("oO", *e) ? 8 : p->base);
		p->base = (ft_strchr("pxXaA", *e) ? 16 : p->base);
		p->exp_base = (ft_strchr("aA", *e) ? 2 : p->exp_base);
		p->exp_len = (ft_strchr("aA", *e) ? 1 : p->exp_len);
		p->exp_char = (ft_strchr("aA", *e) ? *e + 15 : p->exp_char);
		p->exp_char = (ft_strchr("eEgG", *e) ? 'e' : p->exp_char);
		if (ft_strchr("DOUCS", *e))
		{
			if (p->length)
				free(p->length);
			p->length = ft_strdup("l");
		}
		p->signed_num = (ft_strchr("dDi", *e) ? 1 : p->signed_num);
		set_hash(p, e);
	}
	else
		p->prec = 1;
	p->sign = (!ft_strchr("dDifFfFeEgGaA", *e) ? 0 : p->sign);
	p->padding = (ft_strchr("pdDioOuUxXb", *e) && p->prec >= 0 &&
		p->leftalign == 0) ? ' ' : p->padding;
	p->type = *e;
	//printf("945 set_type_field p->type %c\n", p->type); //p->type s
}

static void		init_placehold(t_placehold *p)
{
	p->leftalign = 0;
	p->sign = 0;
	p->padding = ' ';
	p->hash = NULL;
	p->width = 0;
	p->prec = -1;
	p->length = NULL;
	p->type = 0;
	p->base = 10;
	p->signed_num = 0;
	p->uppercase = 0;
	p->sigfig = -1;
	p->exp_base = 10;
	p->exp_char = 0;
	p->exp_len = 2;
}

void			eval_fields(t_placehold *p, const char **e, va_list a_list)
{
	init_placehold(p);
	set_flag_field(p, e);
	set_width_field(p, e, a_list);
	set_precision_field(p, e, a_list);
	set_length_field(p, e);
	set_type_field(p, *e);
}

int	ft_vfdprintf(int fd, const char *format, va_list a_list)
{
    t_placehold	*p;
    const char	*e;
    size_t		count;
    
    count = 0;
    if (format)
    {
        p = malloc(sizeof(*p));
        e = format;
        while (*format)
        {
            if (*format == '%')
            {
                e = format + 1;
                //printf("!!e!! %s\n", e); //вернет все что после %

                eval_fields(p, &e, a_list);
                count += print_eval(fd, p, a_list, count);
                format = e;
            }
            else
                count += ft_putchar_fd(*(format), fd); //ft_putchar_fd возвращает int а мой не вернет он с void
            format += *format ? 1 : 0;
        }
        free(p);
    }
   // printf("count %zu\n", count); Возвр количество символов
    return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list a_list;
	size_t	count;

	va_start(a_list, format);
	count = ft_vfdprintf(1, format, a_list);
	va_end(a_list);
	return (count);
}


/*int	main(void)
{
	//0x7fffffff  == 2147483647
	char *st;
	st = "Blackbirds";
	//printf("%s\n", ft_strrev(st));
	//printf("{%s}", 0);
	//printf("\n");
	//ft_printf("yo %s yo %s", "xD", "What's up!");

	printf("hell%% %-9u,,,,,,, %s %s", 4242, "MYBRO", "Welcome");
	printf("\n\n");
	ft_printf("hell%% %-9u,,,,,,, %s %s", 4242, "MYBRO", "Welcome");
	printf("\n");

	//printf("%S", L"我是一只猫。");
	//printf("\n");
	//ft_printf("Blackbird %d %d", 1, 11);
	//printf("\n");
	//printf("%%");
	//printf("\n");

	//printf("aa%%bb");
	//printf("\n");

	//printf("%%%%%%%%%%");
	//printf("\n");

	printf(".%%.%%.%%.%%.%%.%%.%%.%%.");
	printf("\n");
}*/
