#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    int isInside[26];

    fill_n(isInside, 26, -1);

    cin >> word;

    for (int i = 0; i < word.length(); i++)
    {
        int cur = word[i];

        for (int j = 'a'; j <= 'z'; j++)
        {
            if (isInside[j - 'a'] != -1)
                continue;

            if (cur == j)
            {
                isInside[j - 'a'] = i;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << isInside[i] << " ";
    }
}