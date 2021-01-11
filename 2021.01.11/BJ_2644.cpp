// 백준 2644번 촌수계산
#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int map[MAX][MAX] = {
    0,
};
int dist[MAX] = {
    0,
};
queue<int> q;

int n;
int m;
int a, b;

void bfs()
{
    q.push(a - 1);

    while (!q.empty())
    {
        int cur = q.front();

        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (map[cur][i] == 1 && dist[i] == 0)
            {
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        map[tmp1 - 1][tmp2 - 1] = map[tmp2 - 1][tmp1 - 1] = 1;
    }

    bfs();

    if (dist[b - 1] == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dist[b - 1] << endl;
    }
}