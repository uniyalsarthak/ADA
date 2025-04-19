#include <bits/stdc++.h>
using namespace std;

void printOptimalPattern(vector<vector<int>> &s, int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        printOptimalPattern(s, i, s[i][j]);
        printOptimalPattern(s, s[i][j] + 1, j);
        cout << ")";
    }
}
void matrixChainOrder(vector<int> &p)
{
    int n = p.size() - 1;
    vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));    // to store optimal number of scaler multiplications
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));    // to store where the matrix mult pattern will split

    // l is the chain length
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n] << endl;
    cout << "Optimal Pattern: ";
    printOptimalPattern(s, 1, n);
}

int main()
{
    vector<int> p = {2, 3, 4, 2};
    matrixChainOrder(p);
}
