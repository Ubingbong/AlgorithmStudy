#include <iostream>

#define ROW_MAX 60
#define COL_MAX 60

using namespace std;

int testcase;
int row, col;
int cabbageField[ROW_MAX][COL_MAX];
int visited[ROW_MAX][COL_MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int cabbage;
int warm;

void Init()
{
    for (int i = 0; i < ROW_MAX; i++)
    {
        for (int j = 0; j < COL_MAX; j++)
        {
            cabbageField[ROW_MAX][COL_MAX] = 0;
        }
    }
}

bool isInside(int v1, int v2)
{
    return (v1 >= 0 && v1 < row) && (v1 >= 0 && v1 < col);
}

void dfs(int v1, int v2)
{
    visited[v1][v2] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = v1 + dx[i];
        int ny = v2 + dy[i];

        if (cabbageField[nx][ny] == 1 && isInside(nx, ny))
            dfs(nx, ny);
    }
}

int main()
{
    int v1, v2;
    cin >> testcase;

    while (testcase--)
    {
        Init();

        cin >> row >> col >> cabbage;

        for (int j = 0; j < cabbage; j++)
        {
            cin >> v1 >> v2;
            cabbageField[v1][v2] = 1;
        }

        for (int m = 0; m < row; m++)
        {
            for (int n = 0; n < col; n++)
            {
                if (cabbageField[m][n] == 1)
                {
                    dfs(m, n);
                    warm++;
                }
            }
        }
        cout << warm << endl;
    }

    return 0;
}