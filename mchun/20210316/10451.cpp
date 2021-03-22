#include <iostream>
#include <cstring>

using namespace std;

int		n;
int		input[1000 + 2];
int		visited[1000 + 2];

void	dfs(int	i)
{
	visited[i] = 1;
	if (!visited[input[i]])
		dfs(input[i]);
}

int		main()
{
	int		t;
	int		cycles;

	cin >> t;
	while (t--)
	{
		cycles = 0;
		memset(visited, 0, sizeof(visited));
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> input[i];
		for (int i = 1; i <= n; i++)
			if (!visited[i])
			{
				dfs(i);
				cycles++;
			}
		cout << cycles << endl;
	}
	return (0);
}
