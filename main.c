#include <stdio.h>

int			is_palindrom(long long int abc)
{
	long long int	cba;
	long long int	n;

	cba = 0;
	n = abc;
	while (n)
	{
		cba = cba * 10 + n % 10;
		n /= 10;
	}
	if (abc == cba)
		return (1);
	return (0);
}

int			is_prime(int n)
{
	int	i;

	i = 2;
	while (i < n/2)
	{
		if (n%i == 0)
			return (0);
		i++;
	}
    return 1;
}

int		len(int	nb)
{
	int	len;

	len = 1;
	while (nb /= 10)
		len++;
	return (len);
}

int		main(void)
{
	long long int	res;
	long long int	a;
	long long int	b;

	res = 9999999999;

	while (res)
	{
		if (is_palindrom(res))
		{
			a = 99999;
			while (a >= 10000)
			{
				if (is_prime(a))
				{
					b = res / a;
					if (is_prime(b) && len(b) == 5)
					{
						printf("Result: %lld\n%lld * %lld\n", res, a, b);
						return (1);
					}
				}
				a--;
			}
		}
		res--;
	}
	return (0);
}