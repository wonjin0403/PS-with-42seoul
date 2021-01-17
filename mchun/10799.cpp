#include <iostream>
#include <string>

using namespace std;

int main()
{
	int		numstick;
	int		sum;
	char	c;
	string	input;
	int		i;

	getline(cin, input);
	i = numstick = sum = 0;
	do
	{
		if (input[i] == '(')
			numstick++;
		else
		{
			if (input[i - 1]== '(')
			{
				numstick--;
				sum += numstick;
			}
			else
			{
				sum += 1;
				numstick--;
			}
		}
	} while (input[++i] != '\0') ;
	cout << sum;
	return (0);
}
