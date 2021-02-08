#include <iostream>

bool isPrime(int a)
{
    if (a < 3)
        return false;

    for (int i = 2; i * i < a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main()
{

    while (true)
    {
        int num;
        bool isPossible = false;

        scanf("%d", &num);

        if (num == 0)
            break;

        for (int n = 3; n < num; n += 2)
        {
            int m = num - n;

            bool isPossible;
            if (isPrime(n) && isPrime(m))
            {
                printf("%d = %d + %d\n", num, n, m);
                isPossible = true;
                break;
            }
        }

        if (!isPossible)
            printf("Goldbach's conjecture is wrong.\n");
    }
}