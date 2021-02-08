#include <iostream>

using namespace std;

// 유클리드 호제 알고리즘 반복문으로
int getGCD(int A, int B)
{
    while (B > 0)
    {
        int tmp = B;
        B = A % B;
        A = tmp;
    }
    return A;
}

int getLCM(int A, int B, int GCD)
{
    return A * B / GCD;
}

int main()
{
    int testSize;
    int a, b;
    int GCD;
    int LCM;

    cin >> testSize;

    for (int i = 0; i < testSize; i++)
    {
        cin >> a >> b;
        if (a >= b)
            GCD = getGCD(a, b);
        else
            GCD = getGCD(b, a);
        LCM = getLCM(a, b, GCD);

        cout << LCM << endl;
    }
}