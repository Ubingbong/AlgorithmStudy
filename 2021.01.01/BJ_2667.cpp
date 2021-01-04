#include <iostream>
#include <algorithm>
#define MAXSIZE 25

using namespace std;

int mapSize;
int map[MAXSIZE][MAXSIZE];
int village[1000]; // 왜 빌리지가 25일땐 틀렸을까..?
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int villageNum = 0;

bool isInside(int i, int j)
{
    return (i >= 0 && i < mapSize) && (j >= 0 && j < mapSize);
}

void dfs(int i, int j)
{
    if (villageNum == 1)
        map[i][j] = 0;
    else
        map[i][j] = villageNum;

    village[villageNum - 1]++;

    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (map[nx][ny] == 1 && isInside(nx, ny))
            dfs(nx, ny);
    }
}

int main()
{
    cin >> mapSize;

    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            scanf("%1d", &map[i][j]); // 1d를 하면 정수를 1개씩 입력받는다. (enter 단위로 입력받지 않음)
        }
    }

    for (int i = 0; i < mapSize; i++)
    {
        for (int j = 0; j < mapSize; j++)
        {
            if (map[i][j] == 1 && isInside(i, j))
            {
                villageNum++;
                dfs(i, j);
            }
        }
    }

    sort(village, village + villageNum);

    cout << villageNum << endl;

    for (int i = 0; i < villageNum; i++)
    {
        cout << village[i] << endl;
    }

    return 0;
}