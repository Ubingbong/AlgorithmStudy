// BFS
#include <iostream>
#include <tuple>
#include <queue>
#define MAX 100

using namespace std;

int M, N, H; // 가로 세로 높이
int tomatoContainer[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
queue<tuple<int, int, int>> q;
int day = 0;

int dRow[6] = {0, 0, 0, 0, -1, 1};
int dCol[6] = {0, 0, -1, 1, 0, 0};
int dHi[6] = {-1, 1, 0, 0, 0, 0};

bool isInside(int row, int col, int hi)
{
    return (row >= 0 && row < M) && (col >= 0 && col < N) && (hi >= 0 && hi < H);
}

void BFS()
{

    while (!q.empty())
    {
        tuple<int, int, int> curTuple = q.front();
        int curRow = get<0>(curTuple);
        int curCol = get<1>(curTuple);
        int curHi = get<2>(curTuple);

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nxtRow = curRow + dRow[i];
            int nxtCol = curCol + dCol[i];
            int nxtHi = curHi + dHi[i];

            if (isInside(nxtRow, nxtCol, nxtHi) && tomatoContainer[nxtHi][nxtCol][nxtRow] == 0 && visited[nxtHi][nxtCol][nxtRow] == 0)
            {
                tomatoContainer[nxtHi][nxtCol][nxtRow] = 1;
                visited[nxtHi][nxtCol][nxtRow] = visited[curHi][curCol][curRow] + 1;
                q.push(make_tuple(nxtRow, nxtCol, nxtHi));
            }
        }
    }
}

bool isAllRip()
{
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                // 한개라도 안익었으면
                if (tomatoContainer[i][j][k] == 0)
                    return false;
            }
    return true;
}

int main()
{
    cin >> M >> N >> H;

    // 토마토 상태 저장
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                int __input;
                cin >> __input;
                tomatoContainer[i][j][k] = __input;
            }

    // 모든 토마토가 익어있는지 확인
    if (isAllRip())
    {
        cout << 0 << endl;
        return 0;
    }

    // 토마토 탐색 시작
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                if (tomatoContainer[i][j][k] == 1 && visited[i][j][k] == 0)
                {
                    // 내가 틀렸던 부분. 익은 녀석들을 먼저 queue에 넣고 탐색을 시작해야 BFS 제대로 실행 가능
                    visited[i][j][k] = 1;
                    q.push(make_tuple(k, j, i));
                }
            }
    BFS();

    // 모든 토마토가 익어있는지 확인
    if (!isAllRip())
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                if (day < visited[i][j][k])
                    day = visited[i][j][k];
            }

    cout << day - 1 << endl;
    return 0;
}