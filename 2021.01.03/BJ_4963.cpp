#include <iostream>
#define MAX 50

using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int w, h;
int island;

int dw[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dh[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool isInside(int m, int n)
{
    return (m >= 0 && m < h) && (n >= 0 && n < w);
}

void dfs(int m, int n)
{
    visited[m][n] = 1;

    for (int i = 0; i < 8; i++)
    {
        int nw = m + dw[i];
        int nh = n + dh[i];

        if (map[nh][nw] == 1 && isInside(nh, nw) && visited[nh][nw] != 1)
            dfs(nh, nw);
    }
}

void Init()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main()
{
    while (true)
    {
        island = 0;
        Init();

        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf("%1d", &map[i][j]);
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] == 1 && visited[i][j] != 1)
                {
                    dfs(i, j);
                    island++;
                }
            }
        }

        cout << island << endl;
    }
}
