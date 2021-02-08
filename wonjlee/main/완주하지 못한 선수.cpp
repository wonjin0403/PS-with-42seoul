#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> hashtable;
    map<string, int>::iterator it;
    string answer = "";
    int	num;
    
	for (int idx = 0; idx < completion.size(); idx++)
    {
    	it = hashtable.find(completion[idx]);
    	if (it == hashtable.end())
    		hashtable.insert(make_pair(completion[idx], 1));
    	else
    		(*it).second += 1;
	}
	for (int idx = 0; idx < participant.size(); idx++)
	{
		it = hashtable.find(participant[idx]);
		if (it == hashtable.end())
		{
			answer = participant[idx];
			break;
		}
		else if ((*it).second == 0)
		{
			answer = participant[idx];
			break;
		}
		else
			(*it).second -= 1;
	}
    return answer;
}

int main()
{
	vector<string> participant = {"mislav", "stanko", "mislav", "ana"};
	vector<string> completion = {"stanko", "ana", "mislav"};
	cout << solution(participant, completion);
}
