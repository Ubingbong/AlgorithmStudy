#include <iostream>

using namespace std;

int main()
{
    int N;
    int min, max;

    cin >> N;

    // 첫번째 나이를 min과 max에 저장
    int input;
    cin >> input;
    min = input;
    max = input;

    for (int i = 0; i < N - 1; i++)
    {
        int input;
        cin >> input;

        if (input > max)
        {
            max = input;
        }
        if (input < min)
        {
            min = input;
        }
    }

    cout << max - min << endl;
    return 0;
}