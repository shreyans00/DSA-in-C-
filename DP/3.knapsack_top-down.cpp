#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, int wt[], int val[])
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][w];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 10;

    cout << knapsack(4, w, wt, val);
}
