#include <iostream>

using namespace std;

int main()
{
    int A, B;
    int ans = 0;

    cin >> A >> B;

    for (int i = A; i <= B; i++)
    {
        ans += i;
    }

    cout << ans << endl;
}