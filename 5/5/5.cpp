#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int n,s,v,answer;
    cin >> n >> s;
    vector<vector<bool>> f(1 + n, vector<bool>(1 + n));
    vector<bool> visted(n + 1, false);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> v;
            f[i][j] = (v == 1);
        }

    answer = 0;

    function<void(int)> visit = [&](int cur)
    {
        if (visted[cur])
            return;

        visted[cur] = true;

        answer++;

        for (int i = 0; i < n + 1; i++)
        {
            if (f[cur][v])
                visit(v);
        }
    };

    visit(s);

    cout << answer - 1;
}