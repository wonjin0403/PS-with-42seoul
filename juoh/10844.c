#include <stdio.h>
#define mod 1000000000

int	main(void)
{
	int n;
	int s[101][10] = {};
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		s[1][i] = 1;
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 10; j++){
			if (j == 0)
				s[i][0] = s[i - 1][1] % mod;
			else if (j == 9)
				s[i][9] = s[i - 1][8] % mod;
			else
				s[i][j] = (s[i - 1][j - 1] + s[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + s[n][i]) % mod;
	printf("%d\n", sum % mod);
}