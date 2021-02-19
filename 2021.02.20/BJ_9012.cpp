#include <iostream>
#include <string>

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        string inputString;
        char stack[50];
        int start = 0;
        int end = 0;

        cin >> inputString;

        for (int j = 0; j < inputString.size(); j++)
        {
            //push
            stack[end] = inputString[j];
            end++;

            if (end - 1 > start)
            {
                //pop
                if (stack[end - 1] == ')' && stack[end - 2] == '(')
                {
                    stack[end - 1], stack[end - 2] = 0;
                    end -= 2;
                }
            }
        }

        if (end > start)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}