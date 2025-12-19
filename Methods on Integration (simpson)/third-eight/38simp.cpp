#include <bits/stdc++.h>
using namespace std;

double power(double x, int y)
{
    if (y == 0)
        return 1;
    double ans = x;
    for (int i = 1; i < y; i++)
    {
        ans *= x;
    }
    return ans;
}
double func(vector<double> &coef, double x)
{
    double ans = 0;
    int n = coef.size();
    for (int i = 0; i < n; i++)
    {
        ans += coef[i] * power(x, n - i - 1);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<double> coeff(n + 1);
    for (int i = 0; i < n + 1; i++)
        cin >> coeff[i];
    cout << "the function is : ";
    for (int i = 0; i < n + 1; i++)
    {
        cout << coeff[i] << "x^" << n - i << "+";
    }
    cout << "\n";
    double a, b, y;
    int eq;
    cin >> b >> a >> eq;
    if (eq % 3 != 0)
    {
        cout << "Error: Simpson's 3/8 rule requires intervals to be a multiple of 3!" << endl;
        return 1;
    }
    double h = (b - a) / eq, x;
    double ans = 0;
    ans = func(coeff, a) + func(coeff, b);
    for (int i = 1; i < eq; i++)
    {
        x = a + i * h;
        y = func(coeff, x);
        if (i % 3)
            ans += (3 * y);
        else
            ans += (2 * y);
    }
    ans = ((h *3.0 )/8.0) * ans;
    cout << "the intigration form "<<a<<" to "<<b<<" with "<<eq<<" equal interval \nans=" << ans << "\n";
    return 0;
}
