#include <iostream>
#include <vector>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int add(int W, int wt[], int val[], int n)
{
	int i, w;
	std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1));

	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}

int main()
{
	int val[] = { 200, 120, 100 };
	int wt[] = { 3,   2,   1 };
	int W = 4;
	int n = sizeof(val) / sizeof(val[0]);

	std::cout << add(W, wt, val, n);
	return 0;
}