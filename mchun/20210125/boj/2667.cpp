#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

char	**map;
int		**visited;
int		N;

// MAP과visited 배열 중 MAP 배열만 있어도 될 것같다.
// 다음엔그렇게짜보자.
bool	is_valid_xy(int x, int y)
{
	return ((0 <= x && x <= N-1) && (0 <= y && y <= N-1));
}

int		dfs(int	x, int y)
{
	int		sum;

	sum = 0;
	if (!is_valid_xy(x,y) || visited[y][x])
		return (0);
	visited[y][x] = 1;
	if (map[y][x] == '0')
		return (0);
	sum += (dfs(x-1,y) + dfs(x+1, y) + dfs(x, y-1) + dfs(x, y+1));
	return (sum + 1);
}

int		main()
{
	vector<int>	count_vec;
	int		x, y, i, j, cnt;

	cin >> N;
	map = new char*[N];
	visited = new int*[N];
	for (i = 0; i < N; i++)
	{
		map[i] = new char[N];
		visited[i] = new int[N];
	}

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			visited[i][j] = 0;
	}

	for (i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			cin >> map[i][j];

	for (y = 0; y < N; y++)
	{
		for (x = 0; x < N; x++)
		{
			// cout << x << ' ' <<  y << endl;
			if (visited[y][x])
				continue;
			else
			{
				if (map[y][x] == '0')
				{
					visited[y][x] == 1;
					continue;
				}
				else
					cnt = dfs(x,y);
					if (cnt != 0)
						count_vec.push_back(cnt);
			}
		}
	}
	if (count_vec.size() == 0)
		count_vec.push_back(0);
	sort(count_vec.begin(), count_vec.end());
	cout << count_vec.size() << endl;
	for (i = 0; i < count_vec.size(); i++)
		cout << count_vec[i] << endl;
}
