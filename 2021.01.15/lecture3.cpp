#include <iostream>

using namespace std;

int main()
{
    int N;
    int ans = 0;

    cin >> N;

    for (int i = 1; i < N; i++)
    {
        if (N % i == 0)
            ans += i;
    }

    cout << ans << endl;
}