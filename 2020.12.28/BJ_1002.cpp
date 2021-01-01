#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    // 입력 받는 횟수
    int count;

    // 조규현의 위치 (x1, y1)과 마린까지의 거리 r1
    int x1;
    int y1;
    int r1;

    // 백승환의 위치 (x2, y2)과 마린까지의 거리 r2
    int x2;
    int y2;
    int r2;

    // 백승환과 조규현 사이의 거리
    double d;

    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

        // 두 사람의 위치가 같을 때
        if (x1 == x2 && y1 == y2)
        {
            // case1. 두 원이 같을 때
            if (r1 == r2)
                cout << -1 << endl;

            // case2. 같은 중점의 두 원의 반지름이 다를 때 (동심원)
            else
                cout << 0 << endl;
        }
        // 두 사람의 위치가 같지 않을 때
        else
        {
            // case3. 두 원이 두 점에서 만날 때
            if (r1 + r2 > d && abs(r1 - r2) < d)
                cout << 2 << endl;
            // case4. 두 원이 외접할 때
            else if (r1 + r2 == d)
                cout << 1 << endl;
            // case5. 두 원이 내접할 때
            else if (abs(r1 - r2) == d)
                cout << 1 << endl;
            // case6. 두 원의 접점이 없을 때
            else
                cout << 0 << endl;
        }
    }
    return 0;
}