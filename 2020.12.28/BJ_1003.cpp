#include <iostream>

using namespace std;

int rpt;       // 반복횟수
int N;         // N 번째 피보나치 수
int countOne;  // 1 등장 횟수
int countZero; // 0 등장 횟수

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
