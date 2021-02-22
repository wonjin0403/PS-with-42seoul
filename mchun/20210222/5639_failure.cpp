#include <iostream>
#include <vector>

using namespace std;

vector<int>		input;

void	postal_print(int root)
{
	if (root > input.size() - 1)
		return ;
	//base case 수정 필요.
	if (root + 1 < input.size() - 1 && input[root] < input[root + 1])
	{
		cout << input[root] << endl;
		return ;
	}
	int		right = root + 1;
	while (right < input.size() - 1 && input[root] > input[right])
		right++;
	postal_print(root + 1);
	postal_print(right);
	cout << input[root];
	if (root != 0)
		cout << endl;
}

/* 출력 초과.
 * while(!cin.eof())
 * 		cin >> a;
 * 		input.push_back(a);
 */
int		main()
{
	int		a;

	while (cin >> a)
		input.push_back(a);
	postal_print(0);
	return (0);
}
