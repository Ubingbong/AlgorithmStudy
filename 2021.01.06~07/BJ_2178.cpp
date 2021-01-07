/*
    백준 2178 번 : 미로 탐색
    BFS 문제
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX_M = 101;

int map[MAX_M][MAX_M];     // 미로 정보
int visited[MAX_M][MAX_M]; // 몇 번의 노드를 걸쳐 방문했는지 저장

int n, m; // 미로의 열과 행

int dcol[4] = {1, -1, 0, 0};
int drow[4] = {0, 0, 1, -1};

bool isInside(int col, int row)
{
    return (col >= 0 && col < n) && (row >= 0 && row < m);
}

void bfs(int col, int row)
{
    // 큐에 시작점을 push
    queue<pair<int, int>> q;
    q.push(make_pair(col, row));

    // 시작점 1부터 시작
    visited[col][row] = 1;

    // 큐가 비면 탐색 종료
    while (!q.empty())
    {
        // 큐의 첫번째 노드의 행과 열을 가져온다
        int curCol = q.front().first;
        int curRow = q.front().second;

        // 첫번째 노드 pop해서 큐에서 삭제
        q.pop();

        // 만약 현재 노드가 미로의 마지막이면 탐색을 종료
        if (curCol == n - 1 && curRow == m - 1)
        {
            break;
        }

        // 현재 노드의 상,하,좌,우를 탐색
        for (int i = 0; i < 4; i++)
        {
            int ncol = curCol + dcol[i];
            int nrow = curRow + drow[i];

            // 다음 지역이 길이고 아직 방문하지 않았으며 미로의 범위 안이면 큐에 저장
            if (map[ncol][nrow] == 1 && visited[ncol][nrow] == 0 && isInside(ncol, nrow))
            {
                q.push(make_pair(ncol, nrow));
                visited[ncol][nrow] = visited[curCol][curRow] + 1; // 현재노드까지 몇번만에 왔는지 저장
            }
        }
    }
}

int main()
{
    // 열과 행을 입력받는다
    cin >> n >> m;

    // 띄어쓰기 없이 입력이 주어지므로 string으로 받아서 배열로 쪼개 저장한다.
    // (tip!)숫자의 string type - '0' = 숫자의 int type
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++)
        {
            map[i][j] = tmp[j] - '0';
        }
    }

    // 넓이 우선 탐색 (bfs)를 실시. 인수로는 탐색 시작점을 주었다.
    bfs(0, 0);

    cout << visited[n - 1][m - 1] << endl;

    return 0;
}