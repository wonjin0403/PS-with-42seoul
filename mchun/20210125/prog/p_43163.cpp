#include <string>
#include <vector>

using namespace std;

int		*visited;

int		op(string s1, string s2)
{
	int diff = 0;
	for (int i = 0; i < s1.length(); i++)
		if (s1[i] != s2[i])
			diff++;
	return ((diff > 1) ? 0 : 1);
}

int		find_min_tree(int k, string target, vector<string> &words)
{
	int		min = (1 << 20) - 1;
	int		val;

	if (target == words[k])
		return (0);
	visited[k] = 1;
	for (int i = 0; i < words.size(); i++)
	{
		if (visited[i] != 1 && op(words[k], words[i]))
		{
			val = find_min_tree(i, target, words);
			min = ((min < val) ? min : val);
			visited[i] = 0;
		}
	}
	return (min + 1);
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int min = (1<<20) - 1;
	visited = new int[words.size()];
	for (int i = 0; i < words.size(); i++)
		if (op(begin, words[i]) == 1)
		{
			answer = find_min_tree(i, target, words);
			min = (min > answer) ? answer : min;
		}
	if (min >= (1 << 20 - 1))
		return (0);
	return (answer + 1);
}
