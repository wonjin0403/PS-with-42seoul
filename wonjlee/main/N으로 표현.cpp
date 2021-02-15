#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int MIN = 8;

int	con_num(int idx, int N)
{
	int num;
	
	num = N;
	for (int i = 1; i < idx; i++)
		num = num * 10 + N;
	return (num); 
}

int solution(int N, int number) {
    int answer = -1;
    vector <int> number_of_num[MIN + 1];
    
    for (int idx = 1; idx <= MIN; idx++)
    	number_of_num[idx].push_back(con_num(idx, N));
    for (int i = 1; i <= MIN; i++)
    {
    	for (int j = 1; j < i; j++)
    	{
    		for (int len1 = 0; len1 < number_of_num[j].size(); len1++)
    		{
    			for (int len2 = 0; len2 < number_of_num[i - j].size(); len2++)
    			{
    				number_of_num[i].push_back(number_of_num[j][len1] + number_of_num[i - j][len2]);
    				number_of_num[i].push_back(number_of_num[j][len1] - number_of_num[i - j][len2]);
    				number_of_num[i].push_back(number_of_num[j][len1] * number_of_num[i - j][len2]);
    				if (number_of_num[i - j][len2] != 0)
    					number_of_num[i].push_back(number_of_num[j][len1] / number_of_num[i - j][len2]);
				}
			}
		}
		if (find(number_of_num[i].begin(), number_of_num[i].end(), number) != number_of_num[i].end())
		{
			answer = i;
			break;
		}	
	}
    return answer;
}

int main()
{
	cout << solution(5, 12);
}
