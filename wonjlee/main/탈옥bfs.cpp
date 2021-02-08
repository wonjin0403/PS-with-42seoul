#include <queue>
#include <iostream>

using namespace std;

char map[102][102];
int check_bfs[102][102][3];
int num, w, h;
int	dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int start_x, int start_y, int z)
{
	queue <int> x;
	queue <int> y;
	check_bfs[start_x][start_y][z] = 0;
	x.push(start_x);
	y.push(start_y);
	int now_x, now_y, new_x, new_y;
	
	while (!x.empty())
	{
		now_x = x.front();
		now_y = y.front();
		x.pop();
		y.pop();
		for (int i = 0; i < 4; i++)
		{
			new_x = now_x + dx[i];
			new_y = now_y + dy[i];
			if (new_x >= 0 && new_x <= w + 1 && new_y >= 0 && new_y <= h + 1 &&\
				map[new_x][new_y] != '*' && check_bfs[new_x][new_y][z] == -1 )
			{
				if (map[new_x][new_y] == '#')
					check_bfs[new_x][new_y][z] = check_bfs[now_x][now_y][z] + 1;
				else if(map[new_x][new_y] == '.')
					check_bfs[new_x][new_y][z] = check_bfs[now_x][now_y][z];
				x.push(new_x);
				y.push(new_y);
			}
		}
	}
}


int	main()
{
	int answer;
	queue <int> x;
	queue <int> y;
	cin >> num;
	while (num-- > 0)
	{
		answer = 1000000;
		cin >> w >> h;
		for (int i = 0; i <= w + 1; i++)
		{
			for (int j = 0; j <= h + 1; j++)
			{
				check_bfs[i][j][0] = -1;
				check_bfs[i][j][1] = -1;
				check_bfs[i][j][2] = -1;
				if (i == 0 || i == w + 1 || j == 0 || j == h + 1)
					map[i][j] = '.';
				else
					cin >> map[i][j];
				if (map[i][j] == '$')
				{
					x.push(i);
					y.push(j);
					
				}
			}
		}
		
		bfs(x.front(), y.front(), 0);
		x.pop();
		y.pop();
		
		bfs(x.front(), y.front(), 1);
		x.pop();
		y.pop();
		
		bfs(0, 0, 2);
		
		for (int i = 0; i <= w + 1; i++)
		{
			for (int j = 0; j <= h + 1; j++)
			{
				if (map[i][j] == '#' && map[i][j] != '*' && check_bfs[i][j][0] != -1 && check_bfs[i][j][1] != -1 && check_bfs[i][j][2] != -1)
				{
					if (answer > check_bfs[i][j][0] + check_bfs[i][j][1] + check_bfs[i][j][2] - 2)
						answer = check_bfs[i][j][0] + check_bfs[i][j][1] + check_bfs[i][j][2] - 2;
				}
				else if (answer > check_bfs[i][j][0] + check_bfs[i][j][1] + check_bfs[i][j][2] && map[i][j] != '*' &&\
					check_bfs[i][j][0] != -1 && check_bfs[i][j][1] != -1 && check_bfs[i][j][2] != -1)
					answer = check_bfs[i][j][0] + check_bfs[i][j][1] + check_bfs[i][j][2];
			}
		}
		cout << answer << endl;
	}
}
