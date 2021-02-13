#include <iostream>

bool isPrime(int a, int num)
{
    if (a <= 2)
        return false;

    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;

    for (int i = 2; i * i <= (num - a); i++)
        if ((num - a) % i == 0)
            return false;

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

            if (isPrime(n, num))
            {
                printf("%d = %d + %d\n", num, n, num - n);
                isPossible = true;
                break;
            }
        }

        if (!isPossible)
            printf("Goldbach's conjecture is wrong.\n");
    }
}