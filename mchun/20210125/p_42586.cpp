#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	int		i, day, len, count;
	len = progresses.size();
	for (i = 0; i < len; )
	{
		count = 0;
		day = (speeds[i] == 1) ? 100 - progresses[i] : ((100 - progresses[i] + speeds[i] - 1 ) / speeds[i]);
		while (progresses[i] + day * speeds[i] >= 100 && i < len)
		{
			i++;
			count++;
		}
		answer.push_back(count);
	}
    return answer;
}

int		main()
{
	vector<int>		progress{93, 30, 55};
	vector<int>		speeds{1, 30, 5};
	vector<int>		speeds2{1, 1, 1, 1, 1, 1};
	vector<int>		progress2{95, 90, 99, 99, 80, 99};
	vector<int>		sol = solution(progress2, speeds2);

	for (auto i = sol.begin(); i != sol.end(); ++i)
		cout << *i << " ";
}
