#include <iostream>
#define MAX_PC 100

using namespace std;

int pcNum;
int connect;
int map[MAX_PC][MAX_PC];
int infected[MAX_PC];
int infectedPCNum = 0;

void dfs(int v)
{
    infected[v] = 1;
    infectedPCNum++;

    for (int i = 1; i <= pcNum; i++)
    {
        if (map[v][i] == 1 && infected[i] != 1)
            dfs(i);
    }
}

int main()
{

    int v1, v2;

    cin >> pcNum;

    cin >> connect;

    for (int i = 0; i < connect; i++)
    {
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1;
    }

    dfs(1);

    cout << infectedPCNum - 1 << endl; // 1번 컴퓨터로 인해 바이러스에 걸리는 컴퓨터의 수이므로 1번 컴퓨터는 제외
}