#include <iostream>

using namespace std;

int main()
{
    int serialNum[5];
    int ans = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> serialNum[i];
    }

    for (int i = 0; i < 5; i++)
    {
        serialNum[i] *= serialNum[i];
    }

    for (int i = 0; i < 5; i++)
    {
        ans += serialNum[i];
    }

    ans %= 10;

    cout << ans << endl;
}