#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &wt, vector<int> &profit, int n, int W)
{
    vector<vector<int>> arr(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i] <= j)
                arr[i][j] = max((profit[i] + arr[i - 1][j - wt[i]]), arr[i - 1][j]);

            else
                arr[i][j] = arr[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
    return arr[n][W];
}

int main()
{
    vector<int> wt = {0, 3, 4, 6, 5};
    vector<int> profit = {0, 2, 3, 1, 4};
    int W = 8;
    int n = wt.size() - 1;

    cout << "Maximum profit is " << knapsack(wt, profit, n, W);
}
