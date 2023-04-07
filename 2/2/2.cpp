#include <iostream>

using namespace std;

int main()
{
	int p,t;
	cin >> p;

	for  (int i = 26;i >= 1;i--)
	{
		t = (1 << (i - 1)) - 1;
		if (p == 1)
		{
			cout << char('a' +i - 1);
			return 0;
		}
		else
		{
			if (p <= t + 1)
				p--;
			else
				p -= 1 + t;
		}
	}
}