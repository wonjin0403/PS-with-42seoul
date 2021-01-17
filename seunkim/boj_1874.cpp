#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n;

vector<int> v;
stack<int> s;

string plus_minus;
                                                                                                                                                                                                                                                                                   
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        // 스택에 집어 넣기.
        s.push(i);
        plus_minus += '+';
        
        // 베열 안에 있는 값과 스택의 최상단 값이 일치하는 지 계속 확인
        while (!s.empty() && v[j] == s.top())
        {
            s.pop();
            plus_minus += '-';
            j++;
        }
    }
    
    // 스택에 값이 남아 있으면 no!
    if (!s.empty())
        printf("NO\n");
    else
    {
        for (int i = 0; i < plus_minus.length(); i++)
            printf("%c\n", plus_minus[i]);
    }
}