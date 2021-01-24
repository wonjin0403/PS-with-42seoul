#include <iostream>
#include <string>
#include <queue>

using namespace std;

int		**map;
int		count_minus = 0;
int		N, M, x, y;
int		cnt = 0;
queue<int> Q;

int		count_minus_1(void)
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == -1)
				count_minus++;
			if (map[i][j] == 1)
			{
				Q.push(j);
				Q.push(i);
				cnt++;
			}
		}
	return (0);
}

bool		is_valid_coord(int x, int y)
{
	return ((0 <= x && x < N) && (0 <= y && y < M));
}

int		main()
{
	int		i,j,k;
	int		day;

	cin >> N >> M;
	map = new int*[M];
	for (i = 0; i < M; i++)
		map[i] = new int[N];

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> map[i][j];
	count_minus_1();

	while (!Q.empty())
	{
		x = Q.front(); Q.pop();
		y = Q.front(); Q.pop();
		day = map[y][x];

		if (is_valid_coord(x, y-1) && map[y-1][x] == 0)
		{
			map[y-1][x] = day + 1;
			Q.push(x);
			Q.push(y-1);
			cnt++;
		}
		if (is_valid_coord(x, y+1) && map[y+1][x] == 0)
		{
			map[y+1][x] = day + 1;
			Q.push(x);
			Q.push(y+1);
			cnt++;
		}
		if (is_valid_coord(x-1, y) && map[y][x-1] == 0)
		{
			map[y][x-1] = day + 1;
			Q.push(x-1);
			Q.push(y);
			cnt++;
		}
		if (is_valid_coord(x+1, y) && map[y][x+1] == 0)
		{
			map[y][x+1] = day + 1;
			Q.push(x+1);
			Q.push(y);
			cnt++;
		}
	}
	if (N * M > count_minus + cnt)
		cout << (-1);
	else
		cout << (day - 1);
}
