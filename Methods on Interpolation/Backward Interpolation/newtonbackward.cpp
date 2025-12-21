#include <bits/stdc++.h>
using namespace std;

double fact(int n)
{
    double f = 1.0;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cout << "num of data : \n";
    int n;
    cin >> n;

    cout << "Enter x values : \n";
    vector<double> xv(n);
    for (int i = 0; i < n; i++)
        cin >> xv[i];

    cout << "Enter y values: \n";
    vector<double> ys(n);
    for (int i = 0; i < n; i++)
        cin >> ys[i];

    cout << "value to of x : \n";
    double x;
    cin >> x;

    vector<vector<double>> diff(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        diff[i][0] = ys[i];
    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }

    double h = xv[1] - xv[0];
    double u = (x - xv[n - 1]) / h;
    double ans = diff[n - 1][0];

    double u_val = 1.0;
    for (int k = 1; k < n; ++k)
    {
        u_val = u_cal(u, k);
        ans += (u_val / fact(k)) * diff[n - 1 - k][k];
    }

    cout << "\nBackward Difference Table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << diff[i][j] << '\t';
        }
        cout << '\n';
    }

    cout << "\n for x = " << x << "the value of f(x) = " << ans << "\n";
    return 0;
}