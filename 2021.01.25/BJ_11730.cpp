#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    string numLine;
    int ans = 0;

    cin >> N;
    cin >> numLine;

    for (int i = 0; i < N; i++)
    {
        int curNum = numLine[i] - '0';
        ans += curNum;
    }
    cout << ans;
}