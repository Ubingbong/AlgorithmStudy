// 7576 토마토 / BFS
#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int map[MAX][MAX];
queue<pair<int, int>> q;
int col, row;
int day = 0;

int dCol[4] = {0, 0, -1, 1};
int dRow[4] = {-1, 1, 0, 0};

bool isInside(int n, int m)
{
    return (n >= 0 && n < col) && (m >= 0 && m < row);
}

void BFS()
{
    while (!q.empty())
    {
        int curCol = q.front().first;
        int curRow = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nxtCol = curCol + dCol[i];
            int nxtRow = curRow + dRow[i];

            if (map[nxtCol][nxtRow] == 0 && isInside(nxtCol, nxtRow))
            {
                map[nxtCol][nxtRow] = map[curCol][curRow] + 1;
                q.push(make_pair(nxtCol, nxtRow));
            }
        }
    }
}

int main()
{
    cin >> row >> col;

    // 토마토 창고 정보 입력받기
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    BFS();

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (map[i][j] == 0)
            {
                cout << -1 << endl;
                return 0;
            }

            if (day < map[i][j])
                day = map[i][j];
        }
    }

    cout << day - 1 << endl;

    return 0;
}
