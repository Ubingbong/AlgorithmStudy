// 백준 1920 수 찾기. 답는 이진 탐색.
#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int n, m;
int num;
int g_array[MAX];

// 내가 틀렸던 부분 : 이진 탐색 알고리즘
void binarySearch()
{
    int start = 0;
    int end = n - 1;

    while (end - start >= 0)
    {
        int mid = (start + end) / 2;

        if (g_array[mid] == num) // 만약 중앙값과 찾는 것이 같으면 TRUE
        {
            printf("1\n");
            return;
        }
        else if (g_array[mid] > num) // 만약 중앙값보다 찾는 값이 작으면 현재 중앙값이 마지막 값
            end = mid - 1;
        else // 만약 중앙값보다 찾는 값이 크면 현재 중앙값이 시작값
            start = mid + 1;
    }

    printf("0\n");
    return;
}

int main()
{
    // cin, cout 보단 printf, scanf 가 빠름
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &g_array[i]);

    sort(g_array, g_array + n); // 내가 틀렸던 부분: 이진 탐색 알고리즘

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &num);
        binarySearch(); // 내가 틀렸던 부분: 입력 받으면서 바로 있는지 없는지 체크
    }

    return 0;
}