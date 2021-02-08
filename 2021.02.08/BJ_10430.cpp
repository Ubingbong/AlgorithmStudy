#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int ans;

    cin >> a >> b >> c;

    ans = (a + b) % c;
    cout << ans << endl;

    ans = ((a % c) + (b % c)) % c;
    cout << ans << endl;

    ans = (a * b) % c;
    cout << ans << endl;

    ans = ((a % c) * (b % c)) % c;
    cout << ans << endl;
}