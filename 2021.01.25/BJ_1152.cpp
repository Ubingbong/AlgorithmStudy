#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    int ans = 1;

    getline(cin, input);

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            ans++;
        }
    }

    if (input[0] == ' ')
        ans--;
    if (input[input.length() - 1] == ' ')
        ans--;

    cout << ans;
}