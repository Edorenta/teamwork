int		is_space(const char c)
{
	return ((c < 14 && c > 7) || c == 32);
}

int		is_digit(const char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int		slen(char *s)
{
	return (*s ? slen(++s) + 1 : 0);
}

long	labs(long n)
{
	return (n > 0 ? n : -n);
}

int		active_bits(char c)
{
	int bits;

	bits = 0;
	while(c > 0)
	{
	    if ((c & 1) == 1) 
	        bits++;
	    c >>= 1;
	}
	return (bits);
}