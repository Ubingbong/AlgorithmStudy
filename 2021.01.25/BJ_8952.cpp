#include <iostream>

using namespace std;

int main()
{
    int testcase;

    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        string result;
        int count = 0;
        int score = 0;

        cin >> result;

        for (int j = 0; j < result.size(); j++)
        {
            if (result[j] == 'O')
            {
                count++;
                score += count;
            }
            else
            {
                count = 0;
            }
        }
        cout << score << endl;
    }
}