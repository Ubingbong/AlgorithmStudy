#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int inputSize;
    int ans = 0;

    cin >> inputSize;

    for (int i = 0; i < inputSize; i++)
    {
        int input;
        double squareRoot;
        bool isPrime = true;

        cin >> input;

        if (input == 1)
            continue;
        else
            for (int j = 2; j < input; j++)
            {
                if (input % j == 0)
                    isPrime = false;
            }

        if (isPrime)
            ans++;
    }

    cout << ans << endl;
}