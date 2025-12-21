#include<bits/stdc++.h>
using namespace std;

double u_cal(double x, int k, vector<double>& xv)
{
    double temp = 1.0;
    for (int i = 0; i < k; i++)
        temp = temp * (x - xv[i]);
    return temp;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cout<<"num of data : \n";
    int n; cin>>n;

    cout<<"Enter x values : \n";
    vector<double> xv(n);
    for (int i=0; i<n; i++) cin>>xv[i];

    cout<<"Enter y values: \n";
    vector<double> ys(n);
    for (int i=0; i<n; i++) cin>>ys[i];

    cout<<"value to of x : \n";
    double x; cin >> x;

    vector<vector<double>> diff(n, vector<double>(n));
    for (int i=0; i<n; i++) diff[i][0] = ys[i];
    
    for (int j = 1; j < n; ++j) {
        for (int i=0; i<n-j; i++) {
            diff[i][j] = (diff[i+1][j-1] - diff[i][j-1]) / (xv[i+j] - xv[i]);
        }
    }

    double ans = diff[0][0],uv;
    
    for (int k=1; k<n; ++k){
        uv = u_cal(x, k, xv); 
        ans += uv * diff[0][k];
    }

    cout<<"\nDivided Difference Table:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++) {
            cout<< diff[i][j] << '\t';
        }
        cout<<'\n';
    }

    cout<<"\n for x = " << x << " the value of f(x) = " << ans << "\n";
    return 0;
}