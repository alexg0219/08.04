#include <iostream>

using namespace std;

int main()
{
    int n, m,y,x;
    int cnt = 0;
    int dir = 0;
    cin >> n >> m >> y >> x;

    while (y >= 1 && y <= n && x >= 1 && x <= m)
    {
        cnt++;

        if (dir == 0)
        {
            if (x == m || !((y + x) % 2))
            {
                dir = 1;
                y++;
            }
            else
            {
                x++;
            }
        }
        else if (dir == 1)
        {
            if (y == n || !((y + x) % 2))
            {
                dir = 2;
                x--;
            }
            else
            {
                y++;
            }
        }
        else if (dir == 2)
        {
            if (x == 1 || !((y + x) % 2))
            {
                dir = 3;
                y--;
            }
            else
            {
                x--;
            }
        }
        else
        {
            if (y == 1 || !((y + x) % 2))
            {
                dir = 0;
                x++;
            }
            else
            {
                y--;
            }
        }

        if (y == y && x == x)
            break;
    }

    cout << cnt;
}