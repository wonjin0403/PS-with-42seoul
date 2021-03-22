#include <string>
#include <vector>
#include <cmath>
#include <iostream> 
using namespace std;
long long search_max(vector<int> times)
{
    long long max = 0;
    
    for (int i = 0; i < times.size(); i++)
    {
        if (max < times[i])
            max = (long long)times[i];
    }
    return (max);
}

long long search_min(vector<long long> ans)
{
    long long min = ans[0];
    
    for (int i = 1; i < ans.size(); i++)
    {
        if (min > ans[i])
            min = ans[i];
    }
    return (min);
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long max_time = search_max(times) * n;
    long long min_time = 1;
    long long middle;
    long long num_p;
    vector <long long> ans;

    while (min_time <= max_time)
    {
        num_p = 0;
		middle = round((max_time + min_time) / 2);
        for (int i = 0; i < times.size(); i++)
            num_p += floor(middle / times[i]);
        if (num_p < n)
           min_time = middle + 1;
        else
            max_time = middle - 1;
        if (num_p == n)
            ans.push_back(middle);
    }
    answer = search_min(ans);
    return answer;
}
int main()
{
	vector <int> times={7, 10};
	cout << solution(1, times);
}
