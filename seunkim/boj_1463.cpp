#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int X;

int arr[1000001];

int min(int a, int b, int c)
{
    int tmp;

    tmp = a < b ? a : b;
    return (tmp < c ? tmp : c);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> X;

    int a, b, c;

    for (int i = 2; i <= X; i++)
    {
        a = b = c = 9999999;        // 최대한 큰 값으로 대입
        if (i % 3 == 0) 
            a = arr[i / 3];
        if (i % 2 == 0)
            b = arr[i / 2];
        c = arr[i - 1];
        arr[i] = min(a, b, c) + 1;  // 3개의 경우 중 가장 작은 값 
    }
    printf("%d\n", arr[X]);
}