// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>

// 틀린 이유 : progress = {95, 93, 91}에 speeds = {2, 3, 4}일 때, day가 안좋게나옴.
// 만약, 위 문제를 해결 한 뒤, speeds가 1일 때도 예외처리 해주어야함.
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
	int		i, day, len, count;
	len = progresses.size();
	for (i = 0; i < len; )
	{
		count = 0;
		day = (100 - progresses[i]) / speeds[i];
		while (progresses[i] + day * speeds[i] >= 100 && i < len)
		{
			i++;
			count++;
		}
		answer.push_back(count);

	}
    return answer;
}
