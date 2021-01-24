// https://programmers.co.kr/learn/courses/30/lessons/42586/solution_groups?language=cpp
// 최우수 답변
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
		/* 내 방식과 비슷하지만 훨씬 깔끔함.
		 * 내 방식 :  ((100 - progresses[i] + speeds[i] - 1 ) / speeds[i])
		 * 끝에 1을 더해주는 방식이냐, 그렇지 않은 방식이냐에 따라 다름.
		 * speeds가 1인 경우까지 생각해주지 않아도 되는 코드
		 */
        day = (99 - progresses[i]) / speeds[i] + 1;

		/* max_day : 기능개발 하는데 필요한 최소 필요한 일.
		 * answer를 처음 넣는 상황이거나,
		 * 이전 progress의 기능개발 일 수 보다 많은 일 수가 소요된다면
		 * 기능개발이 끝난 progress의 개수의 update를 멈추고, 다음 progress의 일 수를 계산해야함.
		 * 이미 progress의 개발이 끝난 경우는 progress 개수의 update가 이루어짐. (++answer.back())
		 * max_day의 update가 이루어짐.
		*/
        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}
