#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

int main()
{
	int n,inX,inY,answer;
	double r;
	vector <Point> p;
	cin >> inX >> inY >> r >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		x -= inX;
		y -= inY;

		if (sqrt(x * x + y * y) <= r)
			p.push_back(Point{ x,y });
	}

	answer = 0;

	for (Point p1 : p)
	{
		int in = 0;
		int l = 0;
		int r = 0;
		for (Point p2 : p)
		{
			int c = p1.x * p2.y - p2.x * p1.y;
			if (c < 0)
				l++;
			else
			{
				if (c > 0)
					r++;
				else
					in++;
			}
		}

		answer = max({ answer, in + l,in + r });
	}

	cout << answer;
}
