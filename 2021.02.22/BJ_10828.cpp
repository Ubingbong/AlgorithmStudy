#include <iostream>
#include <string>

using namespace std;

int main()
{
    int testcase;

    string command;

    int stack[10000];
    int front = 0;
    int end = 0;

    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        cin >> command;

        //push
        if (command == "push")
        {
            int pushNum;
            cin >> pushNum;
            stack[end] = pushNum;
            end++;
        }
        else
        {
            switch (command[0])
            {
            case 'p': //pop
                if (end > front)
                {
                    cout << stack[end - 1] << endl;
                    stack[end - 1] = 0;
                    end--;
                }
                else
                    cout << -1 << endl;
                break;

            case 's': //size
                cout << end << endl;
                break;

            case 'e': //empty
                if (end > front)
                    cout << 0 << endl;
                else
                    cout << 1 << endl;
                break;

            case 't': //top
                if (end > front)
                    cout << stack[end - 1] << endl;
                else
                    cout << -1 << endl;
                break;
            }
        }
    }
}