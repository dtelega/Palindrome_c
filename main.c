#include <stdio.h>
#include <stdlib.h>

int		is_pal(long long int abc)
{
	long long int cba;
	long long int copy;

	cba = 0;
	copy = abc;
	while (abc)
	{
		cba = cba * 10 + abc%10;
		abc /= 10;
	}
	if (copy == cba)
		return (1);
	return (0);
}

int			is_prime(int n)
{
	int	i;
	int	s;

	s = n;
	i = 2;
	while (i < n/2)	
	{
		if (n%i == 0)
			return (0);
		i++;
	}
    return 1;
}

int		main(void)
{
	int				a;
	int				b;
	long long int	res;
	long long int	pal;
	int				*tab;
	int				copy_a;
	int				copy_b;


	tab = (int *)malloc(100001 * sizeof(tab));
	a = 0;
	while (a <= 100000)
	{
		if (is_prime(a))
			tab[a] = 1;
		else
			tab[a] = 0;	
		a++;
	}
	a = 99999;
	res = 0;
	while (a >= 10000)
	{
		if (tab[a])
		{
			b = 99999;
			while (b >= 10000)
			{
				if (tab[b])
				{
					pal = (long long int)a * (long long int)b;
					if (is_pal(pal) && pal > res)
					{
						res = pal;
						copy_a = a;
						copy_b = b;
					}
				}
				b--;
			}
		}
		a--;
	}
	free(tab);
	printf("%d x %d = %lld\n", copy_a,copy_b,res);
	return (0);
}
