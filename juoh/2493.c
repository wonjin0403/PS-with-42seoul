#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int num;
	int i, j;
	int init[2][500000];

	scanf("%d", &num);
	i = 0;
	while (i < num)
	{
		scanf("%d", &init[0][i]);
		i++;
	}
	init[0][num] = '\0';
	init[1][num] = '\0';
	while (i > 0)
	{
		i--;
		j = 1;
		while ((init[0][i] > init[0][i - j]) && (i - j >= 0) && (j < num))
			j++;
		if (j > i)
		init[1][i] = 0;
		else
		init[1][i] = i - j + 1 ;
	}

	while (i < num)
	{
		printf("%d",init[1][i]);
		if (i != num)
			printf(" ");
		i++;
	}
	
}