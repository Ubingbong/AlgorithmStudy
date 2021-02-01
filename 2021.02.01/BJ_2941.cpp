#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputWord;
    int ans = 0;

    cin >> inputWord;

    ans = inputWord.length();

    for (int i = 0; i < inputWord.length(); i++)
    {
        if (inputWord[i] == '=')
        {
            if (i >= 2 && inputWord[i - 2] == 'd' && inputWord[i - 1] == 'z')
                ans--;
            ans--;
        }

        if (inputWord[i] == '-')
            ans--;

        if (inputWord[i] == 'j')
            if (inputWord[i - 1] == 'l' || inputWord[i - 1] == 'n')
                ans--;
    }

    cout << ans;
}