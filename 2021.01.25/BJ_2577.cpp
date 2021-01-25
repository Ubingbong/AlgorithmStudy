#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, c;
    string result;
    int ans[10] = {
        0,
    };

    cin >> a >> b >> c;

    result = to_string(a * b * c);

    for (int i = 0; i < result.size(); i++)
    {
        ans[result[i] - '0']++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << ans[i] << endl;
    }
}