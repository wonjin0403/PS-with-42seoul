#include <string>
#include <vector>
#include <queue> 
#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int	sum ;
    int idx = 1;
	int	size;
    queue <int> q;
    queue <int> distance;
	q.push(truck_weights[0]);
	distance.push(1);
	sum = truck_weights[0];
	while (!q.empty())
    {
    	if (distance.front() == bridge_length)
    	{
    		sum -= q.front();
			q.pop();
			distance.pop();
		}
		size = q.size();
		for (int i = 0; i < size; i++)
    	{
    		distance.push(distance.front() + 1);
			distance.pop();
		}
    	if (idx < truck_weights.size() && sum + truck_weights[idx] <= weight)
    	{
			q.push(truck_weights[idx]);
			distance.push(1);
			sum += truck_weights[idx];
			idx++;
		}
		answer++;
	}
    return answer;
}

int main()
{
	std::vector<int> v{10};
	cout << solution(100, 100, v);
}
