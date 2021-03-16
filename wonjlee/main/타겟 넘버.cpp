#include <string>
#include <vector>
#include <iostream> 

using namespace std;

int 		answer;
int			visited[20];
int			sign[2] = {1, -1};
int			g_target;
vector<int> g_numbers;

void	dfs(int now, int num)
{
	if (num == g_target && now + 1 == g_numbers.size())
	{
		answer++;
		return ;
	}
	for (int idx = 0; idx < 2; idx++)
	{
		if (now + 1 < g_numbers.size() && visited[now + 1] == 0)
		{
			int new_num = num + sign[idx] * g_numbers[now + 1];
			visited[now + 1] == 1;
			dfs(now + 1, new_num);
			visited[now + 1] == 0;
		}
	}
}

int solution(vector<int> numbers, int target) {
	answer = 0;
    g_numbers = numbers;
    g_target = target;
    dfs(-1, 0);
    return answer;
}

int main(void)
{
	vector<int> triangle = {1, 1, 1, 1, 1};
	cout << solution(triangle, 3);
	
	return (0);
}
