#include <iostream>

using namespace std;

int a, b;
int GCD; //Greatest Common Divisor(최대공약수)
int LCM; // Least Common Multiple(최소공배수)

// 유클리드 알고리즘 이용해서 최대 공약수 구한다.
void getGCD(int A, int B)
{
    int result = A % B;
    if (result == 0)
    {
        GCD = B;
        cout << GCD << endl;
    }
    else
        getGCD(B, result);
}

void getLCM(int A, int B)
{
    LCM = GCD * (A / GCD) * (B / GCD);

    cout << LCM << endl;
}

int main()
{
    cin >> a >> b;

    if (a >= b)
        getGCD(a, b);
    else
        getGCD(b, a);

    getLCM(a, b);
}