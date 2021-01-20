// 백준 1920 수 찾기. 나의 풀이는 선형 탐색. 시간 초과로 틀렸다.
#include <iostream>
#define MAX 100001
using namespace std;

bool isContain(int array[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == num)
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    int array_1[MAX];
    int array_2[MAX];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> array_1[i];

    cin >> m;

    for (int i = 0; i < m; i++)
        cin >> array_2[i];

    for (int i = 0; i < n; i++)
    {
        if (isContain(array_1, n, array_2[i]))
        {
            cout << 1 << endl;
            continue;
        }
        cout << 0 << endl;
    }

    return 0;
}