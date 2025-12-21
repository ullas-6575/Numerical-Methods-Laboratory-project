#include<bits/stdc++.h>
using namespace std;

// The derivative function: dy/dx = x + y^2
double func(double x, double y){
    return x + y * y;
}

double rk4(double x, double y, double h){
    double k1 = func(x, y);
    double k2 = func(x + 0.5 * h, y + 0.5 * h * k1);
    double k3 = func(x + 0.5 * h, y + 0.5 * h * k2);
    double k4 = func(x + h, y + h * k3);

    // Formula: y + (h/6)*(k1 + 2k2 + 2k3 + k4)
    return y + (h / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x0, y0, xn, h;

    cout << "(x0, y0): \n";
    cin >> x0 >> y0;

    cout << "(xn): \n";
    cin >> xn;

    cout << "step size (h): \n";
    cin >> h;

    cout << fixed << setprecision(4);

    double x = x0;
    double y = y0;
    
    cout << x << "\t" << y << endl;

    while (x < xn) {
        if (x + h > xn) h = xn - x; 
        
        y = rk4(x, y, h);
        x = x + h;
        
        cout << x << "\t" << y << endl;
    }

    cout << "\nValue of y at x = " << xn << " is " << y << endl;

    return 0; 
}