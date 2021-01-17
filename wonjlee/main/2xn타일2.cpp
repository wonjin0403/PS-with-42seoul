#include <vector>
#include <queue> 
#include <bits/stdc++.h>
using namespace std;

int dp[1000 + 1];

int		dp_fun(int	n)
{
	if (n == 1 || n == 2)
		return (dp[n]);
	else if (dp[n - 1] != 0 && dp[n - 2] != 0)
		dp[n] = (dp[n - 1] + dp[n - 2] * 2) % 10007;
	else if (dp[n - 1] != 0)
		dp[n] = (dp[n - 1] + dp_fun(n - 2) * 2) % 10007;
	else if (dp[n - 2] != 0)
		dp[n] = (dp_fun(n - 1) + dp[n - 2] * 2) % 10007;
	else
		dp[n] = (dp_fun(n - 1) + dp_fun(n - 2) * 2) % 10007;
	return (dp[n]);
}

int main()
{
	int	n;
	dp[1] = 1;
	dp[2] = 3;
	cin >> n;
	cout << dp_fun(n);
} 
