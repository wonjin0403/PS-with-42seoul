#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector <int> value;
    value.push_back(0);
    for (int depth = 0; depth < triangle.size(); depth++)
    {
    	vector <int> new_value;
    	for (int width = 0; width < triangle[depth].size(); width++)
    	{
    		if (width - 1 >= 0 && width < value.size())
    			new_value.push_back(max(value[width - 1], value[width]) + triangle[depth][width]);
    		else if (width - 1 < 0)
    			new_value.push_back(value[width] + triangle[depth][width]);
    		else if (width >= value.size())
    			new_value.push_back(value[width - 1] + triangle[depth][width]);
		}
		value = new_value;
	}
	for (int i = 0; i < value.size(); i++)
		answer = max(answer, value[i]);
    return answer;
}

int main(void)
{
	vector<vector <int> > triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
	cout << solution(triangle);
	
	return (0);
}
