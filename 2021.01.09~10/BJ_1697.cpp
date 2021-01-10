#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

// s는 수빈이의 위치, t는 동생의 위치
int s, t;
// 수빈이가 방문한 곳을 표시할 배열
int visited[MAX];
// 큐
queue<int> q;

void BFS()
{
    // 최초의 수빈의 위치를 큐에 등록 & 방문 표시
    q.push(s);
    visited[s] = 1;

    while (!q.empty())
    {
        // 현재 수빈의 위치
        int curPos = q.front();

        q.pop();

        // 만약 수빈의 위치가 동생의 위치와 같다면 함수 벗어남
        if (curPos == t)
            return;

        // 수빈이가 1칸 뒤로 움직이는 경우
        if (curPos - 1 >= 0 && visited[curPos - 1] == 0)
        {
            q.push(curPos - 1);
            visited[curPos - 1] = visited[curPos] + 1;
        }

        // 수빈이가 1칸 앞으로 움직이는 경우
        if (curPos + 1 < MAX && visited[curPos + 1] == 0)
        {
            q.push(curPos + 1);
            visited[curPos + 1] = visited[curPos] + 1;
        }

        // 수빈이가 현재위치의 2배로 순간이동하는 경우
        if (curPos * 2 < MAX && visited[curPos * 2] == 0)
        {
            q.push(curPos * 2);
            visited[curPos * 2] = visited[curPos] + 1;
        }
    }
}

int main()
{
    cin >> s >> t;

    BFS();

    // 수빈이가 처음 위치한 곳부터 count 되므로 움직인 횟수는: (목적지 도착에 걸린 횟수) -1
    cout << visited[t] - 1 << endl;
}