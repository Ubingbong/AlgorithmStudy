#include <iostream>

using namespace std;

int getGCD(int A, int B)
{
    while (B > 0)
    {
        int tmp = B;
        B = A % B;
        A = tmp;
    }
    return A;
}

int main()
{
    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        int num[100] = {
            0,
        };
        int inputCount = 0;
        int ans = 0;
        char input;

        cin >> inputCount;

        for (int j = 0; j < inputCount; j++)
        {
            cin >> num[j];
        }

        for (int n = 0; n < inputCount - 1; n++)
        {
            for (int m = 1 + n; m < inputCount; m++)
            {
                ans += getGCD(num[n], num[m]);
            }
        }
        cout << ans << endl;
    }
}