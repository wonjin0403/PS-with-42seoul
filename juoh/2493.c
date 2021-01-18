#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int num;
	int i, j;
	int *init;
	int *ans;

	scanf("%d", &num);
	i = 0;
	if (!(init = (int *)malloc(sizeof(int) * (num + 1))))
		return 0;
	if (!(ans = (int *)malloc(sizeof(int) * (num + 1))))
		return 0;
	ans[num + 1] = '\0';
	while (i < num)
	{
		scanf("%d", &init[i]);
		i++;
	}
	
	while (i > 0)
	{
		i--;
		j = 1;
		while ((init[i] > init[i - j]) && (i - j >= 0) && (j < num))
			j++;
		if (j > i)
			ans[i] = 0;
		else
			ans[i] = i - j + 1 ;
	}

	while (i < num)
	{
		printf("%d", ans[i]);
		if (i != num)
			printf(" ");
		i++;
	}
	
}