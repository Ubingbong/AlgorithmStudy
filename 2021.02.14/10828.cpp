#include <iostream>
#include <string>
#include <sstream>

#define MAX 10000

using namespace std;

int main()
{
    int stack[MAX] = {
        0,
    };
    int top, bottom = 0;
    int comCount;

    cin >> comCount;
    cin.ignore();

    while (comCount--)
    {
        string command;
        getline(cin, command);

        if (command == "top")
        {
            // 스택 가장 위에 있는 정수를 출력
            if (top > bottom)
                cout << stack[top - 1] << endl;
            // 스택이 비어있으면 -1 출력
            else
                cout << -1 << endl;
        }

        else if (command == "size")
            cout << top << endl;

        else if (command == "empty")
        {
            // 스택이 비어있지 않으면 0 출력
            if (top > bottom)
                cout << 0 << endl;
            // 스택이 비어있으면 1 출력
            else
                cout << 1 << endl;
        }

        else if (command == "pop")
        {
            // 스택 가장 위에 있는 정수를 출력
            if (top > bottom)
            {
                cout << stack[top - 1] << endl;
                stack[top - 1] = 0;
                top--;
            }
            // 스택이 비어있으면 -1 출력
            else
                cout << -1 << endl;
        }
        else //push
        {
            int pushnum;
            string tmpCom = command;
            int comSize = command.size();

            // 문자열 처리
            if (comSize > 5)
            {
                command = tmpCom.substr(0, 4);
                stringstream ssInt(tmpCom.substr(5, comSize - 4));
                ssInt >> pushnum;
            }

            stack[top] = pushnum;
            top++;
        }
    }

    return 0;
}
