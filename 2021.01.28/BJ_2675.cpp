#include <iostream>
#include <string>

using namespace std;

int main()
{
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int repeat;
        string inputString;

        cin >> repeat >> inputString;

        for (int j = 0; j < inputString.length(); j++)
        {
            for (int k = 0; k < repeat; k++)
            {
                cout << inputString[j];
            }
        }
        printf("\n");
    }
}