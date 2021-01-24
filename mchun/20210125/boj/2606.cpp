#include <iostream>
#include <vector>
#include <string>
using namespace std;

int		*visit;
vector<int>		*a;

int		effected_count(int vertice)
{
	int		sum = 0;

	if (visit[vertice])
		return (0);
	visit[vertice] = 1;
	for (int i = 0; i < a[vertice].size(); i++)
	{
		sum += (effected_count(a[vertice][i]));
	}
	return (sum + 1);
}

int		main()
{
	int		pc_num, pairs, i, j;

	cin >> pc_num >> pairs;

	a = new vector<int>[pc_num + 1];
	visit = new int[pc_num + 1];
	for(i = 0; i < pc_num + 1; i++)
		visit[i] = 0;

	while (pairs--)
	{
		cin >> i >> j;
		a[i].push_back(j);
		// 틀린 이유 : pair 모두 push_back 하지않아서
		// pair를 모두 push_back 해주어야하는이유는?
		// directed Graph 와 undirected Graph 생각하면 편하다
		// [2, 1], [3, 1]의 direction을 생각한다면 1에서 나가는 arrow가 존재하지않는다.
		a[j].push_back(i);
	}

	cout << (effected_count(1) - 1);
	return (0);
}
