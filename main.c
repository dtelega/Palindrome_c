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
		cba = cba * 10 + abc % 10;
		abc /= 10;
	}
	return (copy == cba) ? 1 : 0;
}

int			is_prime(int n)
{
	for (int i = 2; i < n / 2; i++)
		if (n % i == 0)
			return (0);
    return 1;
}

int		main(void)
{
	long long int	res;
	long long int	pal;
	int				*tab;
	int				copy_a;
	int				copy_b;


	tab = (int *)malloc(100001 * sizeof(tab));
	for (int a = 10000; a < 100000; a++)
		is_prime(a) ? (tab[a] = 1) : (tab[a] = 0);
	res = 0;
	for (int a = 99999; a > 9999; a--)
		if (tab[a])
			for (int b = 99999; b > 9999; b--)
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
	free(tab);
	printf("%d x %d = %lld\n", copy_a,copy_b,res);
	return (0);
}
