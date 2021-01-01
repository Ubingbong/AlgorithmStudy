#include <iostream>
#define V_MAX 1000
#define E_MAX 10000

using namespace std;

int start;              // 시작 정점
int vn;                 // 정점의 총 개수
int en;                 // 간선의 총 개수
int front, rear = 0;    // 큐의 전단과 후단을 나타내는 변수
int queue[V_MAX];       // 큐
int map[V_MAX][V_MAX];  // 두 정점이 연결
int DFS_visited[V_MAX]; // DFS에서 해당 정점 방문 여부
int BFS_visited[V_MAX]; // BFS에서 해당 정점 방문 여부

// 깊이 우선 탐색
void DFS(int v)
{
    DFS_visited[v] = 1; // 정점 v 를 방문했다고 표시
    printf("%d ", v);

    for (int i = 1; i <= vn; i++)
    {
        if (map[v][i] == 1 && !DFS_visited[i]) // 만약 v와 i 가 연결되어 있고 i에 아직 방문하지 않았다면
        {
            DFS(i); // 정점 i 방문
        }
    }
}

// 넓이 우선 탐색
void BFS(int v)
{
    BFS_visited[v] = 1; // 첫번째 정점 방문

    queue[rear] = v; // 첫번째 정점을 큐에 push
    rear++;          // 큐의 후단을 하나 뒤로

    while (front < rear) // 후단이 전단과 같아지거나 전단보다 작아지면 루프 탈출
    {
        // 현재 방문 정점 가져오기
        int curV = queue[front];
        printf("%d ", curV);

        // 현재 방문 정점과 연결된 모든 정점 push
        for (int i = 1; i <= vn; i++)
        {
            if (map[curV][i] == 1 && BFS_visited[i] != 1)
            {
                BFS_visited[i] = 1;
                queue[rear] = i;
                rear++;
            }
        }

        // 현재 방문 정점 pop
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}
int main()
{
    int v1, v2; // 연결할 두 정점

    scanf("%d %d %d", &vn, &en, &start);

    for (int i = 0; i < en; i++)
    {
        scanf("%d %d", &v1, &v2);      // 연결할 두 정점 입력받기
        map[v1][v2] = map[v2][v1] = 1; // 연결할 두 정점 연결하기
    }

    DFS(start);
    printf("\n");
    BFS(start);

    return 0;
}