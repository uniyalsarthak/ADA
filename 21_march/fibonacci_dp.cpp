#include <bits/stdc++.h>
using namespace std;
int fibonacci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

int main()
{
    int n = 6;
    vector<int> dp(n + 1);
    for (int i = 0; i < dp.size(); i++)
        dp[i] = -1;
        
    cout << fibonacci(n, dp);
}