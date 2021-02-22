#include <iostream>
#include <vector>

using namespace std;

vector<int>		input;

void	postal_print(int start, int end)
{
	if (start > end)
		return ;
	int		right = end;
	int		left = start + 1;
	int		root = start;
	while (input[right] > input[root])
		right--;
	postal_print(left, right);
	postal_print(right + 1, end);
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
	postal_print(0, input.size() - 1);
	return (0);
}
