#include <iostream>

#define MAX 101

using namespace std;

// 배열의 행과 열의 개수
int N;
// 지역을 나타내는 배열
int map[MAX][MAX];
// 지역의 높이를 니티내는 배열
int height[MAX];
// 지역을 조사한 적 있는지 확인을 위한 배열
bool visited[MAX][MAX];
// 안전한 지역의 개수를 저장하는 배열
int safeZoneCount[MAX];

int dRow[4] = {0, 0, 1, -1};
int dCol[4] = {1, -1, 0, 0};

void Init()
{
    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= N; col++)
        {
            visited[row][col] = false;
        }
    }
}

bool isInside(int row, int col)
{
    return (row > 0 && row <= N) && (col > 0 && col <= N);
}

void dfs(int row, int col, int rain)
{
    visited[row][col] = true;

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + dRow[i];
        int nCol = col + dCol[i];

        if (map[nRow][nCol] > rain && isInside(nRow, nCol) && !visited[nRow][nCol])
            dfs(nRow, nCol, rain);
    }
}

void findSafeZone(int rain)
{
    for (int row = 1; row <= N; row++)
    {
        for (int col = 1; col <= N; col++)
        {
            // 비에 잠기지 않았으며 아직 방문하지 않은 지역
            if (map[row][col] > rain && !visited[row][col])
            {
                dfs(row, col, rain);
                safeZoneCount[rain]++;
            }
        }
    }
}

int main()
{
    cin >> N;

    // 지역의 높이 정보를 지도에 저장
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    // 강수량에 따른 안전지역 찾기. 강수량이 n이면 n 이하의 지역은 잠긴다.
    for (int i = 1; i < MAX; i++)
    {
        findSafeZone(i);
        // 방문기록 초기화
        Init();
    }

    int ans = 1;

    for (int i = 1; i < MAX; i++)
    {
        if (safeZoneCount[i] > ans)
            ans = safeZoneCount[i];
    }

    cout << ans << endl;

    return 0;
}