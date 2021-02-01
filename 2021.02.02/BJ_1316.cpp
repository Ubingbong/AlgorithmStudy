#include <iostream>
#include <string>

using namespace std;

int main()
{
    int testcase = 0;
    int ans = 0;

    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        string inputString;
        bool isGroup = true;

        cin >> inputString;

        char appeared[101] = {
            0,
        };

        for (int j = 0; j < inputString.length(); j++)
        {
            // 연속되는 문자면 아래 연산을 진행하지 않는다.
            if (j > 0)
                if (inputString[j - 1] == inputString[j])
                    continue;

            // 이미 등장 했던 알파벳이 나오면 그룹 단어가 아니다
            for (int k = 0; k < j; k++)
            {
                if (appeared[k] == inputString[j])
                    isGroup = false;
            }

            // 아직까지 그룹 단어이면 등장 했던 알파벳 목록에 현재 알파벳을 추가한다.
            if (isGroup)
                appeared[j] = inputString[j];
            // 그룹단어가 아니면 반복문에서 나간다.
            else
                break;
        }
        if (isGroup)
            ans++;
    }
    cout << ans;
    return 0;
}