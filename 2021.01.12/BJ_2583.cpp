#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 100

using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int blankArea[MAX];
int N, M, K;
int ans = 0;

int dX[4] = {0, 0, -1, 1};
int dY[4] = {-1, 1, 0, 0};

bool isInside(int x, int y)
{
    return (x >= 0 && x < N) && (y >= 0 && y < M);
}
void DFS(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nxtX = x + dX[i];
        int nxtY = y + dY[i];

        if (map[nxtY][nxtX] != 1 && isInside(nxtX, nxtY) && visited[nxtY][nxtX] != 1)
        {
            DFS(nxtY, nxtX);
            blankArea[ans]++;
        }
    }
}

int main()
{
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = 0; y < M; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (x >= x1 && x < x2 && y >= y1 && y < y2)
                {
                    map[y][x] = 1;
                }
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != 1 && visited[i][j] != 1)
            {
                DFS(i, j);
                blankArea[ans]++;
                ans++;
            }
        }
    }

    cout << ans << endl;

    sort(blankArea, blankArea + ans);

    for (int i = 0; i < ans; i++)
    {
        cout << blankArea[i] << " ";
    }
}