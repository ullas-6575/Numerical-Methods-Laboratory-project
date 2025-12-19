#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = a; i < b; i++)
const double E = 1e-4;

double power(double x, int y)
{
    if (y == 0)
        return 1;
    double ans = x;
    loop(i, 1, y)
    {
        ans *= x;
    }
    return ans;
}
double func(vector<double> &coef, double x)
{
    double ans = 0;
    int n = coef.size();
    loop(i, 0, n)
    {
        ans += coef[i] * power(x, n - i - 1);
    }
    return ans;
}

double secant(double x0,double x1,vector<double> &coeff){
    double x;
    do{       
        x=x1-(func(coeff,x1)*((x1-x0)/(func(coeff,x1)-func(coeff,x0))));
        x0=x1;
        x1=x;
    } while(abs(x0-x1)>E || abs(func(coeff,x1))>E);
    return x1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    // n = degree ;
    // P(x)=an​x^n+an−1​x^n−1+⋯+a1​x+a0​ ; coeff[0]=an , co[n]= a0;
    vector<double> coeff(n + 1);
    loop(i, 0, n + 1) cin >> coeff[i];
    cout << "the function is : ";
    loop(i, 0, n + 1)
    {
        cout << coeff[i] << "x^" << n - i << "+";
    }
    cout << "\n";
    double tmax = 1, m = -1e16;
    for (int i = 1; i <= n; i++)
    {
        m = max(m, ((coeff[i] * 1.0) / coeff[0]));
    }
    tmax += m;
    cout << "tmax =" << tmax << "\n";
    double h = 0.5;
    double a = -tmax, b = a + h;
    int c = 0, rr = 0;
    while (b <= tmax)
    {
        if (func(coeff, a) * func(coeff, b) < 0)
        {
            cout << "[ " << a << " , " << b << " ]\nroot=";
            double result = secant(a, b, coeff);
            cout << result<< "\n";
            rr++;
        }
        a += h;
        b += h;
    }
    return 0;
}