#include <iostream>
#define MAX_V 1001

using namespace std;

int v, e;
int map[MAX_V][MAX_V];
int visited[MAX_V];
int ans = 0;

void dfs(int n)
{
    visited[n] = 1;

    for (int i = 1; i <= v; i++)
    {
        if (map[n][i] == 1 && visited[i] != 1)
        {
            dfs(i);
        }
    }
}

int main()
{

    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        map[v1][v2] = map[v2][v1] = 1;
    }

    for (int i = 1; i <= v; i++)
    {
        if (visited[i] != 1)
        {
            dfs(i);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}