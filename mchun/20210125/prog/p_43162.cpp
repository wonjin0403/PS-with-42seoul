#include <string>
#include <iostream>
#include <vector>

using namespace std;

// 주의사항: 33~35줄이 없으면 단일노드를 세지 못합니다
// 따라서, 마지막에는 단일노드를 체크해줍니다
// Matrix(i,i)는 노드의 존재여부를 뜻하기 때문에, 네트워크 고려 시, 노드의 존재여부를통해 단일노드의 존재를 파악해야합니다

void	dfs(int i, int j, vector<vector<int>> &map, int n)
{
	if (map[i][j] != 1)
		return ;
	map[i][j] = 2;
	map[i][i] = 2;
	for (int k = 0; k < n; k++)
		if (j != k)
			dfs(j, k, map, n);
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	int	i, j;
	int	count = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (i != j && computers[i][j] == 1)
			{
				dfs(i,j,computers, n);
				count++;
			}
	}
	for (i = 0; i < n; i++)
		if (computers[i][i] == 1)
			count++;
	answer = count;
	return answer;
}
