#include <bits/stdc++.h>

using namespace std;
int	arr[500000];

int	main()
{
	stack <int> s;
	stack <int> index;
	int num;
	int	hight;

	cin >> num;
	arr[0] = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> hight;
		while (!s.empty() && s.top() < hight)
		{
			s.pop();
			index.pop();
		}
		if (!s.empty())
			arr[i] = index.top();
		s.push(hight);
		index.push(i + 1);
	}
	for (int i = 0 ; i < num; i++)
		cout << arr[i] << " ";
}
