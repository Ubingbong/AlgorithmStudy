#include <iostream>

#define ROW_MAX 50
#define COL_MAX 50

using namespace std;

int testcase;
int row, col;
int cabbageField[ROW_MAX][COL_MAX];
int visited[ROW_MAX][COL_MAX];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int cabbage;
int warm;

// 배추밭 순회하면서 배추밭 초기화
void Init()
{
    for (int i = 0; i < ROW_MAX; i++)
    {
        for (int j = 0; j < COL_MAX; j++)
        {
            cabbageField[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

// 배추밭 범위 내인지 확인
bool isInside(int m, int n)
{
    return (m >= 0 && m < row) && (n >= 0 && n < col);
}

void dfs(int m, int n)
{
    visited[m][n] = 1;

    // 배추와 상하좌우로 인접한 배추 검사
    for (int i = 0; i < 4; i++)
    {
        int nx = m + dx[i];
        int ny = n + dy[i];

        // 상하좌우에 있접한 배추가 있고, 배추밭 범위 내이며, 방문한 적이 없다면
        if (cabbageField[nx][ny] == 1 && isInside(nx, ny) && visited[nx][ny] != 1)
            dfs(nx, ny);
        else
            continue;
    }
}

int main()
{
    // 테스트 케이스의 횟수를 입력받는다
    cin >> testcase;

    for (int i = 0; i < testcase; i++)
    {
        // 가로 세로 값, 배추 개수 입력 받기
        cin >> row >> col >> cabbage;

        // 배추 위치를 저장할 임시값
        int v1, v2 = 0;
        //배추밭 초기화
        Init();
        // 필요한 벌레 개수 초기화
        warm = 0;

        // 배추 위치 입력 받기
        for (int j = 0; j < cabbage; j++)
        {
            // 배추 위치 입력 받기
            cin >> v1 >> v2;
            // 해당 위치에 배추 심기
            cabbageField[v1][v2] = 1;
        }

        // 배추밭 순회하며 배추가 있는 곳을 발견하면 깊이 우선 탐색
        for (int m = 0; m < row; m++)
        {
            for (int n = 0; n < col; n++)
            {
                if (cabbageField[m][n] == 1 && visited[m][n] != 1)
                {
                    warm++;
                    dfs(m, n);
                }
            }
        }
        // 이번 테스트 케이스에서 필요한 벌레 수 출력
        cout << warm << endl;
    }

    return 0;
}