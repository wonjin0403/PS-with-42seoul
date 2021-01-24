#include <string>
#include <vector>

using namespace std;

int	find_comb(int i, int target, vector<int> &number, int sum)
{
	if (i == number.size())
		if (target == sum)
			return (1);
		else
			return (0);
	return ((find_comb(i+1, target, number, sum += number[i])) + \
				find_comb(i+1, target, number, sum -= (number[i]) * 2));
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
	answer = find_comb(0, target, numbers, 0);
    return answer;
}
