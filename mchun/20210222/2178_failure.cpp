#include <iostream>
using namespace std;

int		n;
int		m;
char	map[101][101];
int		visit[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int		minimum = 10001;

int		is_valid_coord(int x, int y)
{
	return !(x < 0 || y < 0 || x >= n || y >= m);
}

void	DFS(int x, int y, int ret_val)
{
	int coord_x;
	int coord_y;

	if (is_valid_coord(x, y))
		return ;
	if (x == n - 1 && y == m - 1)
	{
		if (ret_val < minimum)
			minimum = ret_val;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		coord_x = x + dx[i];
		coord_y = y + dy[i];
		if (visit[coord_x][coord_y] == 0 && map[coord_x][coord_y] == '1')
		{
			visit[coord_x][coord_y] = 1;
			DFS(coord_x, coord_y, ret_val + 1);
			visit[coord_x][coord_y] = 0;
		}
	}
}

int main(void)
{
	cin >> n >> m;    //N세로 M가로

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	DFS(0, 0, 1);
	cout << minimum;
}

