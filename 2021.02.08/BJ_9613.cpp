#include <iostream>

using namespace std;

int getGCD(int A, int B)
{
    if (A % B == 0)
        return B;

    return getGCD(B, A % B);
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
        long long ans = 0;

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