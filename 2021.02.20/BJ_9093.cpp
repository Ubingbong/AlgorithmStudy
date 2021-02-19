#include <iostream>
#include <string>

#define MAX 10001

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    cin.ignore();

    for (int i = 0; i < testcase; i++)
    {
        string inputString;

        string stack[20];
        int start, end = 0;

        getline(cin, inputString);

        for (int j = 0; j <= inputString.size(); j++)
        {
            if (inputString[j] == ' ' || j == inputString.size())
            {
                if (end > start)
                {
                    for (int k = end - 1; k >= 0; k--)
                        cout << stack[k];

                    cout << ' ';

                    stack[0] = {
                        0,
                    };
                    end = 0;
                }
            }

            else
            {
                stack[end] = inputString[j];
                end++;
            }
        }

        cout << '\n';
    }
}
