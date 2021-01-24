#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

#define BFS 1
using namespace std;

vector<int>		*a;
int				*visited;

// w/ BFS
/* #################### 스택, 큐 ####################*/
int		q_bfs(queue<int> &q)
{
	int		j, i;
	int		ret_val = 0;

	if (a[1].size() == 0)
		return (0);
	q.push(1);
	visited[1] = 1;
	while (!q.empty())
	{
		j = q.front(); q.pop();
		for(i = 0; i < a[j].size(); i++)

			if (!visited[a[j][i]])
			{
				q.push(a[j][i]);
				visited[a[j][i]] = 1;
				ret_val += 1;
			}
	}
	return (ret_val);
}

// w/ DFS
int		s_dfs(stack<int> &s)
{
	int		i, j;
	int		v;
	int		ret_val = 0;

	s.push(1);
	visited[1] = 1;
	while (!s.empty())
	{
		v = s.top(); s.pop();
		for (i = 0; i < a[v].size(); i++)
		{
			j = a[v][i];
			if (!visited[j])
			{
				s.push(j);
				visited[j] = 1;
				ret_val += 1;
			}
		}
	}
	return (ret_val);
}

int		main()
{
	int		i, j, pairs, pc_num;
	queue<int>	q;
	stack<int>	s;

	cin >> pc_num >> pairs;
	a = new vector<int>[pc_num + 1];
	visited = new int[pc_num + 1];

	for (i = 0; i < pc_num + 1; i++)
		visited[i] = 0;
	while (pairs--)
	{
		cin >> i >> j;
		a[i].push_back(j);
		a[j].push_back(i);
	}
	#ifdef BFS
	int x = q_bfs(q);
	cout << x;
	#else
	int y = s_dfs(s);
	cout << y;
	#endif
}
