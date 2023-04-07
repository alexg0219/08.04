#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int h, w, n, tcost;
	tcost = 0;
	cin >> h >> w >> n;

	vector <vector<int>> cost(h, vector<int>(w));

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			cin >> cost[i][j];
			if (i > 0)
				cost[i][j] += cost[i - 1][j];
			
			if (j> 0)
				cost[i][j] += cost[i][j - 1];

			if (i > 0 && j > 0)
				cost[i][j] += cost[i - 1][j - 1];
		}

	for (int i = 0; i < n; i++)
	{
		int ai, bi, ci,di;
		cin >> ai >> bi >> ci >> di;
		tcost = cost[ci - 1][di - 1];

		if (ai > 1)
			tcost -= cost[ai - 2][di - 1];

		if (bi > 1)
			tcost -= cost[ci - 1][bi - 2];

		if (bi > 1 && ai > 1)
			tcost += cost[ai - 2][bi - 2];
	}

	cout << tcost/2;
}