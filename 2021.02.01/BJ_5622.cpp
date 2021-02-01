#include <iostream>
#include <string>

using namespace std;

int main()
{
    string dial;
    int ans = 0;
    char curNum;

    cin >> dial;

    for (int i = 0; i < dial.length(); i++)
    {
        curNum = dial[i];

        // 알파벳 대문자가 아니면 종료
        if (curNum > 'Z' || curNum < 'A')
            return 0;

        if (curNum >= 'W')
            ans += 10;
        else if (curNum >= 'T')
            ans += 9;
        else if (curNum >= 'P')
            ans += 8;
        else if (curNum >= 'M')
            ans += 7;
        else if (curNum >= 'J')
            ans += 6;
        else if (curNum >= 'G')
            ans += 5;
        else if (curNum >= 'D')
            ans += 4;
        else if (curNum >= 'A')
            ans += 3;
    }

    cout << ans;
    return 0;
}
