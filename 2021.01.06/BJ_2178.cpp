#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX_M = 100;

int map[MAX_M][MAX_M];
bool visited[MAX_M][MAX_M];

int n, m;

int dn[4] = {0, 0, 1, -1};
int dm[4] = {1, -1, 0, 0};

int bfs(int n, int m)
{
    visited[n][m] = 1;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++)
        {
            map[i][j] = tmp[j] - '0';
            cout << map[i][j] << " ";
        }
    }

    bfs(0, 0);
}