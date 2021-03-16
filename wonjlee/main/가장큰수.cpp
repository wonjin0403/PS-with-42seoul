#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
bool cmp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    for (int i = 0; i < numbers.size(); i++)
        temp.push_back(to_string(numbers[i]));
    sort(temp.begin(), temp.end(), cmp);
    if (temp.at(0) == "0")
        return "0";
    for (int i = 0; i < tmp.size(); i++)
        answer += temp[i];
    return answer;
}

int main()
{
	vector <int> number = {109, 1};
	//for(int i = 0; i < 1000; i++)
	//	number.push_back((1000 - i));
	cout << solution(number);
}
