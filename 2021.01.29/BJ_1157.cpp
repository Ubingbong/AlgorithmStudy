#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    int count[26] = {
        0,
    };
    int maxCount = 0;
    int mostAppearedCount = 0;
    char ans;

    cin >> word;

    // 등장하는 알파벳의 개수처리 (대소문자 구분x)
    for (int i = 0; i < word.length(); i++)
    {
        int cur = word[i];
        if (cur >= 'a') // 소문자 처리
            count[cur - 'a']++;
        else // 대문자 처리
            count[cur - 'A']++;
    }

    // 가장 많이 나온 알파벳의 개수 구하기
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > maxCount)
        {
            maxCount = count[i];
        }
    }

    // 만약 중복이면 '?' 출력
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == maxCount)
        {
            ans = i + 'A';
            mostAppearedCount++;
        }
    }
    if (mostAppearedCount == 1)
        cout << ans << endl;
    else
        cout << "?" << endl;
}