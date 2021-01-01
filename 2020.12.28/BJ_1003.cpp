#include <iostream>

using namespace std;

int rpt; // 반복횟수
int N;   // N 번째 피보나치 수

int countZero, countOne = 0; // 0과 1 등장 횟수

void fibonacci(int n)
{
    if (n == 0)
        countZero++;
    if (n == 1)
        countOne++;

    for (int i = 1; i < n; i++)
    {
        if (n - i == 0)
            countZero++;
        if (n - i == 1)
            countOne++;

        if (n - (i + 1) == 0)
            countZero++;
        if (n - (i + 1) == 1)
            countOne++;
    }
}

int main(int argc, char const *argv[])
{
    cin >> rpt;

    for (int i = 0; i < rpt; i++)
    {
        cin >> N;
        fibonacci(N);
        cout << countZero << ends;
        cout << countOne << ends;

        countZero = 0;
        countOne = 0;
    }

    return 0;
}
