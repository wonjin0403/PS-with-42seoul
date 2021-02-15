#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool bool_words[51];
int answer;
vector<string> words;

int ft_cmp(string src1, string src2)
{
	int	diff_char = 0;
	for (int i = 0; i < src1.length(); i++)
	{
		if (src1[i] != src2[i])
		{
			diff_char++;
		}
	}
	if (diff_char == 1)
		return (1);
	return (0);
}

void dfs(string now, string target, int cnt)
{
	cout << now << " " << cnt <<"\n";
	if (now == target)
	{
		if (answer == 0 or cnt < answer)
			answer = cnt;
		return ;
	}
	for (int i = 0; i < words.size(); i++)
	{
		if (!bool_words[i] && ft_cmp(now, words[i]))
		{
			bool_words[i] = true;
			dfs(words[i], target, cnt + 1);
			bool_words[i] = false;
		}
	}
	return ;
}

int solution(string begin, string target, vector<string> in_words)
{
    answer = 0;
	words = in_words;
    
    dfs(begin, target, 0);
    return (answer);
}

int main()
{
	vector<string> v = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout << solution("hit", "cog", v);
}
