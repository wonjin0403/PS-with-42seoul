#include <stack>
#include <iostream>
#include <string>

using namespace std;

int		main()
{
	string		input;
	int			stick_num;
	int			sum;
	stack<int>	stk;

	getline(cin, input);
	stick_num = sum = 0;
	for(int i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '(')
			stk.push(1);
		else
		{
			stk.pop();
			if (input[i - 1] == '(')
			{
				sum += stk.size();
			}
			else
				sum += 1;
		}
	}
	cout << sum;
}
