#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sorted_array;
    vector <int> arr_sort;
    int i, j, k;
    
    for (int idx = 0; idx < commands.size(); idx++)
    {
    	sorted_array = array;
        i = commands[idx][0] - 1;
        j = commands[idx][1];
        k = commands[idx][2] - 1;
        cout << i << " " << j << "\n";
        sort(sorted_array.begin() + i, sorted_array.begin() + j);
        for (int a = 0; a < sorted_array.size(); a++)
        	cout << sorted_array[a] << ", ";
        answer.push_back(sorted_array[i + k]);
        cout << "\n";
    }
    return answer;
}
int main()
{
	vector <int> array = {1, 5, 2, 6, 3, 7, 4};
	vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
	vector <int> ans = solution(array, commands);
}
